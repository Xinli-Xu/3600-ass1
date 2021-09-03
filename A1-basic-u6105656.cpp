//#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<time.h>
using namespace std;
/* define three global array. arr[] is used to store all y values of centers. */
long long arr[500000000];
/* L[] and R[] is used in merge function for storing the left part of unsorted array and right part of unsorted array. */
long long L[500000000];
long long R[500000000];
/* reference for algorithm:https://www.geeksforgeeks.org/merge-sort/ */
/* function merge is used to merge two subarrays. */
void merge(int l, int m, int r) 
{ 
    int i, j, k;
    /* n1 is the size of left array. */ 
    int n1 = m - l + 1; 
    /* n2 is the size of right array. */
    int n2 =  r - m; 
  
    /* Copy data to arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the L[] and R[] into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* If there are any remaining elements in L[], copy it to arr[] */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* If there are any remaining elements in R[], copy it to arr[] */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is the index of left and r is the index of right */
void mergeSort( int l, int r) 
{ 
    if (l < r) 
    {
        /* calculate the middle of the part of array which is wanted to be sorted. */
        int m = l+(r-l)/2;
        /* seperately sort the left and right side. */
        mergeSort(l, m); 
        mergeSort( m+1, r);
        /* After sorting the substrings, call the function merge to merge into one array. */
        merge(l, m, r);
    } 
} 
  
/* main function. */
int main(int argc, char* argv[]) 
{ 
	/* The algorithm of loading data from file is code from tutorial. */
	/* read the file. */
	ifstream file;
	file.open(argv[1]);
	long long length;
	long long width;
	/* num is the number of centers. */
	int num;
	file >> length >> width >> num;
	for (int i = 0; i < num; i++) {
		long long x;
		long long y;
		file >> y;
		file >> x;
		arr[i] = x;	
	}
	file.close();
	/* define two clocks for storing the starting and ending time. */
	clock_t start,end;
	/* record the starting time. */	
	start = clock();
	/* mergesort the array of center y values. */
    mergeSort(0, num - 1);
	long long median;
	/* if n value is even, the median of the array with length n is arr[n/2] + arr[(n/2)-1]. */
	if (num % 2 == 0) {
		median = (arr[(num/2)] + arr[(num/2) - 1])/2;
		cout << median << endl; }
	else {
	/* if n value is odd, the median of the array with length n is arr[(n-1)/2]. */
		median = arr[(num - 1)/2] ;
		cout << median << endl; }
	/* record the ending time. */	
	end = clock();
	/* following code is for printing the time. */
	/*cout << start << " " << end << " ";
	cout << CLOCKS_PER_SEC << "\n";
	long double cpu_timeused = (end - start)/(long double)CLOCKS_PER_SEC;
	cout << 1000*cpu_timeused << "\n";
    return 0; */
} 

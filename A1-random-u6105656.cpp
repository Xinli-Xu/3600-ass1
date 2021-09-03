 #include <stdio.h>
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <climits>
#include<fstream>
//#include<bits/stdc++.h>
#include<iomanip>
/* Define a global array to store all y values for centers */
long long arr[500000000];
/* Reference for algorithm: https://www.techiedelight.com/quickselect-algorithm/*/
int partition(int left, int right, int pivotIndex)
{
	/* Pick pivotIndex as pivot from the array, the pivotIndex is randomly generated. */
	long long pivot = arr[pivotIndex];

	/* swap the pivot to end of array. */
	swap(arr[pivotIndex], arr[right]);

	int pIndex = left;
	int i;

	/* if the value is less than the pivot value, it will be pushed to the left side. if the value is lerger than or equal to the pivot value, it will be pushed to the right side. */
	for (i = left; i < right; i++)
	{
		if (arr[i] <= pivot)
		{
			swap(arr[i], arr[pIndex]);
			pIndex++;
		}
	}

	/* swap the pivot to its final place. */
	swap(arr[pIndex], arr[right]);
	
	/* return the index of pivot. */
	return pIndex;
}

/* the function quickselect the k-th value within left..right in the array. */
long long quickselect(int left, int right, int k)
{
	/* if only one element in the search array, return it. */
	if (left == right)
		return arr[left];

	/* randomly select a pivot between left and right. */
	int pivotIndex = left + rand() % (right - left + 1);

	pivotIndex = partition(left, right, pivotIndex);

	/* if the random pivot is the element we want to find. directly returns the value. */
	if (k == pivotIndex)
		return arr[k];

	/* if the k is less than the pivotindex, call quickselect function again, but k value is not change. The right side need decreases to pivotindex - 1. */
	else if (k < pivotIndex)
		return quickselect(left, pivotIndex - 1, k);

	// if k is more than the pivot index, call quickselect function again. Keep the k value but change the left side to pivot+1. */
	else
		return quickselect(pivotIndex + 1, right, k);
}

/* main function */
int main(int argc, char* argv[])
{	
	/* read file algorithm is from tutorial code. */
    int n;
    /* read the file. */
    ifstream file;
    file.open(argv[1]);
    long long length;
    long long width;
    /* load the length, width and the number of centers from the file. */
    file >> length >> width >> n;
    /* load all center values to the global array. */
    for (int i = 0; i < n; i++) {
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
	/* if n value is even, the median of the array with length n is (arr[(n/2)-1] + arr[n/2])/2*/	
	if (n % 2 == 0) {
  		int a = n/2 + 1;
  		int b = n/2;
  		/* call function quickselect to get the k-th value. */
  		long long c = quickselect(0,n-1,a);
  		long long d = quickselect(0,n-1,b);
  		int median = (c+d)/2;
  		cout << median << endl;
	}
   	else {
  	/* if n value is odd, the median of the array with length n is arr[(n-1)/2]. */
  	int k = (n-1)/2;
  	long long median = quickselect(0, n - 1, k);
  	cout << median << endl;
  	}
	/* record the ending time. */
	end = clock();
	/* Following is for testing the time. */
	/*cout << start << " " << end << " ";
	cout << CLOCKS_PER_SEC << "\n";
	long double cpu_timeused = (end - start)/(long double)CLOCKS_PER_SEC;
	cout << 1000*cpu_timeused << "\n"; 
    return 0; */
}

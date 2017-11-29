#include <iostream>
#include <cassert>

using namespace std;

// a = the array of values to sort
// x =  a temporary array for merging 2 sorted sub-arrays
// s = start of range to sort
// e = end of range to sort

void merge(int a[], int x[], int s, int midpoint, int e){
	int i = s;
	int m = midpoint;
	int j = m + 1;
	int k = 0;

	while (i <= m && j <= e){
	   if (a[i] < a[j]){
	      x[k] = a[i];
	      i++;
	      k++;
	   }
	   else  
	      x[k] = a[j];
	      j++;
	      k++;
	   
	}

	while (i <= m){
	   x[k] = a[i];
	   k++;
	   i++;
	}

	while (j <= e){
	   x[k] = a[j];
	   k++;
	   j++;
	   
	}

	for (i = s; i <= e; i++) {
	   int k = 0;
	   a[i] = x[k];
	   k++;
	}
}



void msort(int a[], int x[], int s, int e){
	int midpoint;
	if (e - s < 1) return;
	   midpoint = (s + e)/2;
	   msort(a, x, s, midpoint);
	   msort(a, x, midpoint + 1, e);
	   merge(a, x, s, midpoint, e);

	   
	   
}

void mergesort(int a[], int len){
	int *x = new int[len];
	int s = 0;
	msort(a, x, s, len - 1);
	delete [] x;
}

bool sorted (int a[], int len){
	for (int i = 0; i < len - 1; i++) {
		if (a[i] > a[i +1]) {
			return false;
		}
	}
	return true;
}


int main(int argc, char * args[]){
	int a[] = {2};
	mergesort(a,1);
	assert(sorted(a,1));

	int b[] = {1, 2, 3, 4, 5,};
	mergesort(b, 5);
	assert(sorted(b, 5));

	int c[1000];
	for (int i = 0; i < 1000; i++) c[i] = -50 + rand() % 100;
	mergesort(c, 1000);
	assert(sorted(c, 1000));

	int d[1001];
	for (int i = 0; i < 1001; i++) d[i] = -50 + rand() % 100;
	mergesort(d, 1001);
	assert(sorted(d, 1001));

	cout << "All tests passed." << endl;

	return 0;
}


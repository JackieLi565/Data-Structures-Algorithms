#include "mySort.h"

void merge(int arr[], int l, int m, int r) {

  //copy
    // data[i] = tmp;
    // myCopy(&tmp, &data[i]);

  //compare
    // data[j] < foo 
    // myCompare(data[i], foo) < 0 -> data[i] - foo 

  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  // Create temp arrays
  int L[n1], R[n2];
  // Copy data to temp array
  for (i = 0; i < n1; i++) {
    myCopy(&arr[l + i], &L[i]); // L[i] = arr[l + i];
  }

  for (j = 0; j < n2; j++) {
    myCopy(&arr[m + 1+ j], &R[j]); //R[j] = arr[m + 1+ j];
  }

  // Merge the temp arrays
  i = 0;
  j = 0;
  k = l;

  while (i < n1 && j < n2) {
    if (myCompare(L[i], R[j]) < 0 || L[i] == R[j]) { //L[i] <= R[j]
      myCopy(&L[i], &arr[k]); // arr[k] = L[i];
      i++;
    } else {
      myCopy(&R[j], &arr[k]); //arr[k] = R[j];
      j++;
    }

    k++;
  }

  // Copy the remaining elements of L[]
  while (i < n1) {
    myCopy(&L[i], &arr[k]); //arr[k] = L[i];
    i++;
    k++;
  }

  // Copy the remaining elements of R[]
  while (j < n2) {
    myCopy(&R[j], &arr[k]); //arr[k] = R[j];
    j++;
    k++;
  }
  
}

void mySort(int array[], unsigned int first, unsigned int last) {
	if (first < last) {
		int middle = (last+first)/2;

    //recursive calls
		mySort(array, first, middle);
		mySort(array,middle +1, last);
    //calls merge function
		merge(array,first,middle,last);
	}    
}

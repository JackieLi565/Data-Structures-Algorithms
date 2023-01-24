#include <stdio.h>
#include <stdlib.h>
#include "mySort.h"

int main(int argc, char * argv[])
{
  int data[10000];
  int nDataItems;
  int i;
  
  if(argc > 1) {
    for(int j = 1; j < argc;j++ ){
      data[j-1] = atoi(argv[j]);
    }
    nDataItems = argc-1;
    mySort(data, nDataItems);
    
  } else {
    nDataItems = 4;
    data[0] = 10;
    data[1] = 20;
    data[2] = 30;
    data[3] = 40;

    mySort(data, nDataItems);
  }

  /*Checking if the array is sorted*/
  for(i = 0; i < nDataItems-1;i++) {
    if(data[i] > data[i+1]) {
      fprintf(stderr,"Sort error: daata[%d] (= %d)"
	      " should be <= data[%d] (= %d)- -aborting\n",
	      i, data[i], i+1, data[i+1]);
      exit(1);
    }
  }

  for(i = 0; i<nDataItems; i++) {
    printf("%d\n", data[i]);
  }
  exit(0);
}

#include "mySort.h"

void mySort(int array[], unsigned int first, unsigned int last) {
    int i,j, key;

    for (i = first+1; i <= last; i++) {
        j = i -1;
        myCopy(&array[i], &key);// key = array[i];
        
        while (j >= first && myCompare(key, array[j]) < 0) {
            myCopy(&array[j], &array[j+1]); // array[j+1] = array[j];
            j--;
        }
        myCopy(&key, &array[j+1]); //array[j+1] = key;
    }
}

1. With the supplied betterSort object module we could use the divide-and-conquer algorithm model. Since we are supplied with the first and last values, we can calcualte the middle index of the array. As divide-and-conquer is a recursive algorithm, we can break down and split the array into halfs, while storing the new array in memory, until we get to one single value.
This algorithm would not nesessarily better than the previous as with large data set the new mySort would be a much more viable option as it does not compare every single value to itself if memory is not a constraint. With small data sets, the previous sorting alogorithm would be better as the betterSort algo requires more memory as it grows (array storage).

The Pseudo Code for mySort();

mySort(int data[], first, last) {

	middle <= (first + last)/2;	//finding the middle
	betterSort(int data[], first, middle); //breaks left branch (recursive call)
	betterSort(int data[], middle + 1, last); //breaks into right branch (recursive call)
	mergeFunction(arr[], left, middle, last) //compare left and right and merging back as a sorted array.

}



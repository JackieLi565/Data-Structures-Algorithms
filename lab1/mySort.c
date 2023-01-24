void mySort(int d[], unsigned int n)
{
  for(int i =1; i < n; i++) {
    int key = d[i];
    int j = i - 1;
    while(j >= 0 && d[j] > key) {
      d[j + 1] = d[j];
      j--;
    }
    d[j + 1] = key;
  }
}

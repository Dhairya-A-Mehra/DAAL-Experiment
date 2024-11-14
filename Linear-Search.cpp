#include <stdio.h>
void linear_search(int a[], int n, int key){
   int i, count = 0;
   for(i = 0; i < n; i++) {
      if(a[i] == key) { // compares each element of the array
         printf("The element is found at %d position\n", i+1);
         count = count + 1;
      }
   }
   if(count == 0) // for unsuccessful search
      printf("The element is not present in the array\n");
}
int main(){
   int i, n, key;
   n = 6;
   int a[10] = {12, 44, 32, 18, 4, 10};
   key = 18;
   linear_search(a, n, key);
   key = 23;
   linear_search(a, n, key);
   return 0;
}
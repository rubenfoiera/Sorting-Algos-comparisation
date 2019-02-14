
#include <stdio.h>
#include <stdlib.h>

int parent(int i) {
return (i - 1) / 2;
}
int lchild(int i) {
return (i + 1) * 2 - 1;
}
int rchild(int i) {
return (i + 1) * 2;
}
void swap(int A[], int i, int j) {
int tmp;
tmp = A[i];
A[i] = A[j];
A[j] = tmp;
}
void heapify(int A[], int i, int n) {
int l = lchild(i);
int r = rchild(i);
int max = i;
int tmp;
if (l<n && A[l]>A[max]) max = l;
if (r<n && A[r]>A[max]) max = r;
if (max != i) {
swap(A, i, max);
heapify(A, max, n);
}
}
void buildMaxHeap(int A[], int n) {
int i;
for (i = n/2; i >= 0; i--) heapify(A, i, n);
}
void heapSort(int A[], int n) {
int i, s = n;
buildMaxHeap(A, n);
for (i=n-1; i>0; i--) {
swap(A, i, 0);
s--;
heapify(A, 0, s);
}}

void swap1(int *x, int *y)
{
  int tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}



void QuickSort(int a[],int low,int high, int choice) {
    int q;
    
    if (low<high){
	    q=HoarePartition(a,low,high,choice);
	    QuickSort(a,low,q-1,choice);
	    QuickSort(a,q,high,choice);
}}

int HoarePartition (int a[],int low, int high, int choice) {
    int x,i=low-1,j=high+1;
    if(choice==1){
    	x=median(a, low, high);
    	while (1) {
        do  j--; while (a[j] > x);
        do  i++; while (a[i] < x);
        if  (i <= j) 
            swap1(&a[i],&a[j]);
        else 
            return i;
    }}
    
    else{
	x=a[high];
	    while (1) {
	        do  j--; while (a[j] > x);
	        do  i++; while (a[i] < x);
	        if  (i < j) 
	            swap1(&a[i],&a[j]);
	        else 
	            return i; }}
}

int median(int a[], int p, int r)
{
    int m = (p+r)/2;
    if(a[p] < a[m])
    {
        if(a[p] > a[r])
            return a[p];
        else if(a[m] < a[r])
            return a[m];
    }
    else
    {
        if(a[p] < a[r])
            return a[p];
        else if(a[m] > a[r])
            return a[m];
    }
    return a[r];
}

void bubblesort(int *array, int length)
{
   int i, j,tmp;

   for (i = 0; i < length ; i++) 
   {
      for (j = i; j < length ; j++) 
      {
          if (array[i] > array[j]) 
          {
              tmp = array[i];
              array[i] = array[j];
              array[j] = tmp;
          }
      }
   }
}

void swap2(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
int choose_pivot(int i,int j )
{
    return((i+j) /2);
}
 
void quicksort(int list[],int m,int n)
{
    int key,i,j,k;
    if( m < n)
    {
        k = choose_pivot(m,n);
        swap2(&list[m],&list[k]);
        key = list[m];
        i = m+1;
        j = n;
        while(i <= j)
        {
            while((i <= n) && (list[i] <= key))
                i++;
            while((j >= m) && (list[j] > key))
                j--;
            if( i < j)
                swap2(&list[i],&list[j]);
        }
        
        swap2(&list[m],&list[j]);
 
        
        quicksort(list,m,j-1);
        quicksort(list,j+1,n);
    }
}

int main(int argc, char *argv[]) {



void readFile(char filename[], int output[], int *n) {
 FILE *f;
 int i;

f=fopen(filename, "r");

i=0;
while(fscanf(f, "%d", &output[i]) == 1) i++;
 
*n=i-1;

 fclose(f); }
 int m=30000;
 int invers[m];
 int ordered[m];
 int random[m];
 readFile("inverse.txt", invers, &m);
 readFile("ordered.txt", ordered, &m);
 readFile("random.txt", random, &m);
 
#include <time.h>

clock_t start;
clock_t end;
float seconds;

start = clock();
heapSort(ordered,m);
end = clock();
seconds = (float)(end - start) / CLOCKS_PER_SEC;
printf("secs  heapSort ordered: %f\n", seconds);

start = clock();
heapSort(random,m);
end = clock();
seconds = (float)(end - start) / CLOCKS_PER_SEC;
printf("secs  heapSort random: %f\n", seconds);

start = clock();
heapSort(invers,m);
end = clock();
seconds = (float)(end - start) / CLOCKS_PER_SEC;
printf("secs heapSort inverse: %f\n", seconds);

start = clock();
quicksort(ordered,0,m);
end = clock();
seconds = (float)(end - start) / CLOCKS_PER_SEC;
printf("secs Quicksort ordered: %f\n", seconds);

start = clock();
quicksort(random,0,m);
end = clock();
seconds = (float)(end - start) / CLOCKS_PER_SEC;
printf("secs Quicksort random: %f\n", seconds);

start = clock();
quicksort(invers,0,m);
end = clock();
seconds = (float)(end - start) / CLOCKS_PER_SEC;
printf("secs Quicksort inverse: %f\n", seconds);

start = clock();
QuickSort(ordered,0,m,1);
end = clock();
seconds = (float)(end - start) / CLOCKS_PER_SEC;
printf("secs Quicksort Median ordered: %f\n", seconds);

start = clock();
QuickSort(random,0,m,1);
end = clock();
seconds = (float)(end - start) / CLOCKS_PER_SEC;
printf("secs Quicksort Median random: %f\n", seconds);

start = clock();
QuickSort(invers,0,m,1);
end = clock();
seconds = (float)(end - start) / CLOCKS_PER_SEC;
printf("secs Quicksort Median inverse: %f\n", seconds);

bubblesort(ordered,m);
end = clock();
seconds = (float)(end - start) / CLOCKS_PER_SEC;
printf("secs bubblesort ordered: %f\n", seconds);

start = clock();
bubblesort(random,m);
end = clock();
seconds = (float)(end - start) / CLOCKS_PER_SEC;
printf("secs bubblesort random: %f\n", seconds);

start = clock();
bubblesort(invers,m);
end = clock();
seconds = (float)(end - start) / CLOCKS_PER_SEC;
printf("secs bubblesort inverse: %f\n", seconds);

return 0;
}

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void quicksort(int V[10],int first,int last){
   int i, j, pivot, temp;
   if(first<last){
  	pivot=first;
  	i=first;
  	j=last;
  	while(i<j){
     	while(V[i]<=V[pivot]&&i<last)
        	i++;
     	while(V[j]>V[pivot])
        	j--;
     	if(i<j){
        	temp=V[i];
        	V[i]=V[j];
        	V[j]=temp;
     	}
  	}
  	temp=V[pivot];
  	V[pivot]=V[j];
  	V[j]=temp;
  	quicksort(V,first,j-1);
  	quicksort(V,j+1,last);
   }
}

// 10 + [(n-1) * 2(n-1)] +

int main() {
int i, j;
/*srand(time(NULL));
  time_t t;
for (i=0;i<10;i++) {
           	int r = rand() % 20;
           	V[i] = r;
}
*/
int V[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
for (i=0;i<10;i++) {
           	printf("%d\n",V[i]);
}
quicksort(V,0,9);
printf("\n\n");
for (i=0;i<10;i++) {
           	printf("%d\n",V[i]);
}
system("PAUSE");
return 0;
}

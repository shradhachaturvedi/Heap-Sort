#include<stdio.h>
#include<conio.h>
#include<math.h>

void adjust(int a[],int i,int n){
	int j = 2*i;
	int item = a[i];
	while(j<=n){
		if((j<n) && (a[j]<a[j+1]))
			j++;
		if(item >= a[j])
			break;
		
		a[(int) floor(j/2.00)]=a[j];
		j=2*j;
	}
	a[(int) floor(j/2.00)] = item;
}

void heapify(int a[], int n){
	float k = (n/2);
	for(int i= floor(k);i>=1;i--){
		adjust(a,i,n);
	}
}

void heapSort(int a[], int n){
	heapify(a,n);
	for(int i=n;i>2;i--){
		int t = a[1];
		a[1] = a[i];
		a[i] = t;
		adjust(a,1,i-1);
	}
}

int main(){
	printf("Enter values of the array to be sorted\n");
	int a[7];
	for(int i=0;i<7;i++)
		scanf("%d",&a[i]);
	heapSort(a,7);
	printf("Sorted array is : \n");
	for(int i=0;i<7;i++)
		printf("%d\t",a[i]);
	getch();
	return 0;
}
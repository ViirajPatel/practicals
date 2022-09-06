#include <stdio.h>
#include<iostream>
#include <time.h>
#include<vector>
using namespace std;
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) 
{
    int pi = arr[low];
    int i = low ;
    int j = high + 1;
    int a =1;
    while (a==1)
    {
	do{
	    i = i + 1;
	 
	} while (arr[i]<pi && i!=high);
	do
	{
	    j = j - 1;
	   
	} while (arr[j] > pi && j !=low);
	
	if (i < j){
	 
	    swap(&arr[i], &arr[j]);
	}
	else{
	    swap(&arr[j],&arr[low]);
	    return j;

	}
    }
}

void quick(int arr[], int low, int high) 
{
   int pi;
	   if (low < high)
    {
	pi = partition(arr, low, high);
	quick(arr, pi+1, high);
       quick(arr, low,pi-1);
    }
	
}


int main(){
	int temp;

	int arr[100001],count=0;
	
	FILE *pFile;
	
	pFile = fopen("./100k_dsc.txt", "r");

	while (temp != -1)
	{
		fscanf(pFile, "%d", &temp);
		arr[count] = temp;
		count++;
		
	}

	fclose(pFile);


	clock_t t;
	t = clock();

	quick(arr, 0, 100000);
	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC;

	for (int i=0;i<=5;i++)
		cout << arr[i] << " ";
	printf("it took %f seconds to execute quick \n", time_taken);
 return 0;
}
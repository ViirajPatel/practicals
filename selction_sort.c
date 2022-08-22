#include<stdio.h>
int main(){
    int a[7] = {1, 20, 10, 4, 33, 3, 2};
    int min ;

    for (int i = 0; i < 7;i++){
        min = a[i];
        for (int j = i; j < 7;j++){
            if(a[j]<min){
                min = a[j];
                a[j] = a[i];
                a[i] = min;
               
            }
        }
        printf("%d ", a[i]);
        }
   
        return 0;
}
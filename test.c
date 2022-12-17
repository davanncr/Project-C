#include<stdio.h>
int main(){
    int n=5;
    int arr[]={4,2,6,1,5};
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                int swap=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=swap;
            }
        }
    }
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
}
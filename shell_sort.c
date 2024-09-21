#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
int findmax(int A[],int n){
    int x=A[0];
    for(int i=0;i<n;i++){
        if(x<A[i]){
            x=A[i];
        }
    }
    return x;
}
void shell_Sort(int A[], int n){
    int gap=0,i,j;
    for(gap=n/2;gap>=1;gap/=2){
        for(i=gap;i<n;i++){
            int temp=A[i];
            j=i-gap;
            while(j>=0 && A[j]>temp){
                A[j+gap]=A[j];
                j=j-gap;
            }
            A[j+gap]=temp;
        }
    }
    
}
int main(){
    int A[]={11,13,7,12,16,9,24,5,10,3};
    int n=10;
    shell_Sort(A,n);
    for(int i=0;i<10;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    
    
} 
    
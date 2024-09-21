#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
}*head;
void merge(int A[],int l, int mid, int h){
    int i=l,j=mid+1,k=l;
    int b[100];
    while(i<=mid && j<=h){
        if(A[i]<A[j]){
            b[k++]=A[i++];
        }
        else{
            b[k++]=A[j++];
        }
    }
    for(;i<=mid;i++){
        b[k++]=A[i];
    }
    for(;j<=h;j++){
        b[k++]=A[j];
    }
    for(i=l;i<=h;i++){
        A[i]=b[i];
    }
}

void ImergeSort(int A[], int n){
    int p,l,h,mid,i;
    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<n;i=i+p){
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            merge(A,l,mid,h);
        }
    }
    if(p/2<n){
        merge(A,0,p/2-1,n-1);
    }
}
void RmergeSort(int A[], int l,int h){
    int mid;
    if(l<h){
        mid=(l+h)/2;
        RmergeSort(A,l,mid);
        RmergeSort(A,mid+1,h);
        merge(A,l,mid,h);
    }
}
int findmax(int A[], int n){
    int i;
    int x=A[0];
    for(i=1;i<n;i++){
        if(x<A[i]){
            x=A[i];
        }        
    }
    return x;
}
 void countSort(int A[], int n){
    int max,i,j,*B;
    max=findmax(A,n);
    B=(int*)malloc(sizeof(int)*(max+1));
    for(i=0;i<max+1;i++){
        B[i]=0;
    }
    for(i=0;i<n;i++){
        B[A[i]]++;
    }
    i=0,j=0;
    while(i<max+1){
        if (B[i]>0){
            A[j++]=i;
            B[i]--;
        }
        else{
            i++;
        }
    }
 }
void Insert(struct Node *head, int pos, int val) {
    struct Node *t, *p;
    int i = 0;
    if (pos < 0) {
        return;
    }
    
    t = (struct Node *)malloc(sizeof(struct Node));
    if (!t) { // Check if memory allocation failed
        printf("Memory allocation failed.\n");
        return;
    }
    
    t->data = val;
    t->next = NULL; 
    
    if (pos == 0) {
        t->next = head;
        head = t; // Update head to point to the new node
    } else {
        p = head;
        while (p && i < pos - 1) {
            p = p->next;
            i++;
        }
        if (p) {
            t->next = p->next;
            p->next = t;
        }
    }
}

int Delete(struct Node *head, int pos) {
    struct Node *q = NULL;
    struct Node *p = head; // Assuming head is the pointer to the first node
    int x = -1; // Default return value if deletion fails
    int i;

    if (pos < 1 || pos > count(head)) {
        return -1; // Invalid position
    }

    if (pos == 1) {
        x = p->data; // Store data of the node to be deleted
        head = head->next; // Update head to point to the next node
        free(p); // Free memory of the deleted node
        return x; // Return the deleted value
    } else {
        for (i = 0; i < pos - 1 && p; i++) {
            q = p;
            p = p->next;
        }
        if (p) {
            q->next = p->next; // Link the previous node to the node after p
            x = p->data; // Store data of the node to be deleted
            free(p); // Free memory of the deleted node
            return x; // Return the deleted value
        }
    }

    return -1; 

void Bucket_Bin_Sort(int A[], int n){
    int i,j,max;
    max=findmax(A,n);
    struct Node**Bins;
    Bins=(struct Node**)malloc(sizeof(struct Node)*(max+1));
    if (!Bins) { 
        printf("Memory allocation failed.\n");
        return;
    }
    for(i=0;i<max+1;i++){
        Bins[i]=NULL;
    }
    for(i=0;i<n;i++){
        Insert(Bins[A[i]],i,A[i]);
    }
    i=0;j=0;
    while(i<max+1){
        while(Bins!=NULL){
            A[j++]=Delete(Bins[i]);  
        }
        i++;
    }
}
int main()
{   
    int A[]={2,4,8,10,12,3,5,6,7,14};
    int n=10;
    int i;
    Bucket_Bin_Sort(A,n);
    for(i=0;i<10;i++){
        printf("%d\t",A[i]);
    }
    printf("\n");
    printf("%d",findmax(A,n));

    return 0;
}
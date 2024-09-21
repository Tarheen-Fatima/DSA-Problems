#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* prev;
    int data;
    struct Node*next;
}*first=NULL;
void create(int A[],int n){
    struct Node*last,*t;
    int i;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    first->prev=NULL;
    last=first;
    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}
void Display(struct Node*p){
    while(p){
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}
int Length(struct Node*p){
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}
void insert(struct Node*p,int pos,int x){
    struct Node*q=NULL;
    if(pos<0 ||pos>Length(p)){
        return;
    }
    if(pos==0){
        struct Node*t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else{
        for(int i=0;i<pos-1 ;i++){
            p=p->next;
        }
        struct Node*t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        t->prev=p;
        t->next=p->next;
        if(p->next!=NULL){
            p->next->prev=t;
        }
        p->next=t;
    }
}

int Delete(struct Node*p,int pos){
    int x=-1;
    if(pos<0 || pos>Length(p)){
        return -1;
    }
    if(pos==1){
        first=first->next;
        x=p->data;
        free(p);
        if(first)
        {
            first->prev=NULL;
        }
    }
    else{
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next)
        {
            p->next->prev=p->prev;
        }
        x=p->data;
        free(p);
    }
    return x;
}
void*Reverse(struct Node*p){
    struct Node*temp;
    while(p!=NULL){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL){
            first=p;
        }
    }
}
int main(){
    int A[]={1,2,3,4,5};
    create(A,5);
    Reverse(first);
    Display(first);
}
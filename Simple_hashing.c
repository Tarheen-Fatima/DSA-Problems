#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
}*first;
void Sorted_insert(struct Node**H, int x){
    struct Node *t,*q=NULL,*p=*H;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if (*H==NULL){
        *H=t;
    }
    else{
        while(p && p->data<x){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next=first;
            q->next=t;
        }
    }
}
struct Node*Search (struct Node*p,int key){
    while(p!=NULL){
        if(key==p->data){
            return p;
        }
        else{
            p=p->next;
        }
    }
    return NULL;
}
int Hash(int key){
    return key%10;
}
void Insert(struct Node*H[],int key){
    int index=Hash(key);
    Sorted_insert(&H[index],key);
}
int main(){
    struct Node*HT[10];
    struct Node*temp;
    int i;
    for(i=0;i<10;i++){
        HT[i]=NULL;
    }
    Insert(HT,12);
    Insert(HT,32);
    Insert(HT,42);
    temp=Search(HT[Hash(12)],12);
    printf("%d ",temp->data);
}



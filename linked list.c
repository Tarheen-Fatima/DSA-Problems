#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdbool.h>
struct Node{
    int data;
    struct Node*next;
}*first=NULL,*second=NULL,*third=NULL;
struct Node*last=NULL;

void create(int A[],int n){
    int i;
    struct Node*t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void create2(int A[],int n){
    int i;
    struct Node*t,*last;
    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=A[0];
    second->next=NULL;
    last=second;
    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void display(struct Node*p)
{
    while(p!=NULL){
        printf("%d->",p->data);
        p=p->next;
    }
    printf("NULL");
}
int count(struct Node *p){
    int l=0;
    while(p){
        l++;
        p=p->next;
    }
    return l;
}
int Rcount(struct Node*p){
    if(p!=NULL){
        return Rcount(p->next)+1;
    }
    else{
        return 0;
    }
}
int Sum(struct Node*p){
    int sum=0;
    while(p!=NULL){
        sum=sum+p->data;
        p=p->next;
    }
    return sum;
}

int Rsum(struct Node*p){
    int sum=0;
    if(p==0){
        return 0;
    }
    else{
        return Rsum(p->next)+p->data;
    }
}
int Max(struct Node*p)
{
    int max=0;
    while(p!=0)
    {
        if(max<p->data){
            max=p->data;
        }
        p=p->next;
    }
    return max;
}
int Rmax(struct Node*p){
    int x=0;
    if(p==0){
        return 0;
    }
    x=Rmax(p->next);
    return x>p->data?x:p->data;
    
}
int Min(struct Node*p){
    int min;
    while(p){
        if(p->data<min){
            min=p->data;
        }
        p=p->next;
    }
    return min;
}
struct Node*LinearSearch(struct Node*p,int key){
    while(p!=NULL){
        if(key==p->data){
            return (p);
        }
        p=p->next;
    }
    return NULL;
}
struct Node*MoveToHead(struct Node*p,int key){
    struct Node*q=NULL;
    while(p!=NULL){
        if(key==p->data){
            q->next=p->next;
            p->next=first;
            first=p;
            return (p);
        }
        q=p;
        p=p->next;
    }
    return NULL;
}
int AddAtStarting(struct Node*p,int val){
    struct Node*temp=NULL;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=val;
    temp->next=first;
    first=temp;
}
int AddAtPosition(struct Node*p,int val,int pos){
    struct Node*t;
    int i=0;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=val;
    p=first;
    for(i=0;i<pos-1;i++){
        p=p->next;
    }
    t->next=p->next;
    p->next=t;
}
int AddAtLast(struct Node*p,int val){
    struct Node*t;
    int i=0;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=val;
    while(p->next!=NULL){
        p=p->next;
    }
    t->next=p->next;
    p->next=t;
    
}

void Insert(struct Node*p,int pos,int val){
    struct Node*t;
    int i=0;
    if(pos<0 || pos>count(p)){
        return;
    }
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=val;
    if(pos==0){
        t->next=first;
        first=t;
    }
    else if(pos>0){
        p=first;
        for(i=0;i<pos-1 && p;i++){
            p=p->next;
        }
        if(p){
            t->next=p->next;
            p->next=t;
        }
    }
}
void InsertLast(int x){
    struct Node*t;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL){
        first=last=t;
    }
    else{
        last->next=t;
        last=t;
    }
}
 
 
void InsertSorted(int x){
    struct Node*temp;
    struct Node*p=first;
    struct Node*q=NULL;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    if (first==NULL){
        first=temp;
    }
    else{
        while(p && p->data<x){
            q=p;
            p=p->next;
        }
        if(p==first){
            temp->next=first;
            first=temp;
        }
        else{
            temp->next=q->next;
            q->next=temp;
        }
    }
}
int Delete( struct Node*p,int pos){
    struct Node*q=NULL;
    int x=-1;
    int i;
    if(pos<1 || pos>count(p)){
        return -1;
    }
    if(pos==1){
        x=p->data;
        first=first->next;
        free(p);
        return x;
    }
    else{
        for(i=0;i<pos-1 && p;i++){
            q=p;
            p=p->next;
        }
        if(p){
            q->next=p->next;
            x=p->data;
            free(p);
            return x;
        }
    }
   
}
int IsSorted(struct Node*p){
    int x=-32768;
    while(p!=NULL){
        if(p->data<x){
            return false;
        }
        x=p->data;
        p=p->next;
    }
    return true;
}
void RemoveDuplicate(struct Node*p){
    struct Node*q=first->next;
    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}
void Reverse(struct Node*p){
    int n=count(p);
    int b[n];
    int i=0;
    while(p!=NULL){
        b[i]=p->data;
        p=p->next;
        i++;
    }
    p=first,i--;
    while(p!=NULL){
        p->data=b[i];
        p=p->next;
        i--;
    }
}

void concate(struct Node*p,struct Node*q){
    third=first;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
}
void merge(struct Node*p,struct Node*q){
    struct Node*last;
    if(p->data<q->data){
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else{
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q){
        if(p->data<q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
        if(p!=NULL){
            last->next=p;
        }
        else{
            last->next=q;
        }
    }
}
int isLoop(struct Node*f){
    struct Node*p,*q;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && q && p!=q);
    if(p==q){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    struct Node *t1,*t2;
    int A[]={2,8,10,15,30};
    create(A,5);
    t1=first->next->next;
    t2=first->next->next->next->next;
    t2->next=t1;
    printf("%d",isLoop(first));
    
    
   }


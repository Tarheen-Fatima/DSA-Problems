#include<stdio.h>
#include<malloc.h>
struct Node{
    int data;
    struct Node*next;
}*head;
void create(int A[],int n){
    struct Node*t,*last;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=A[0];
    head->next=head;
    last=head;
    for(int i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
void Display(struct Node*h){
    do{
        printf("%d ",h->data);
        h=h->next;
    }while(h!=head);
    printf("\n");
}
void Rdisplay(struct Node*h){
    static int flag=0;
    if(h!=head || flag==0){
        flag=1;
        printf("%d ",h->data);
        Rdisplay(h->next);
    }
    flag=0;
}
int length(struct Node*p){
    int c=0;
    do{
        c+=1;
        p=p->next;
    }while(p!=head);
    return c;
}
void Insert(struct Node*p,int x,int pos){
    struct Node*t;
    if (pos<0 || pos>length(p)){
        return;
    }
    if(pos==0){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        if(head==NULL){
            head=t;
            head->next=head;
        }
        else{
            while(p->next!=head){
                p=p->next;
            }
            p->next=t;
            t->next=head;
            head=t;
        }
    }
    for(int i=0;i<pos-1 && p;i++){
        p=p->next;
    }
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=p->next;
    p->next=t;
}
int Delete(struct Node*p,int pos){
    struct Node*q;
    int x;
    if(pos<0 || pos>length(head)){
        return -1;
    }
    if(pos==1){
        while(p->next!=head){
            p=p->next;
        }
        x=head->data;
        if(p==head){
            free(head);
            head=NULL;
        }
        else{
            p->next=head->next;
            free(head);
            head=p->next;
        }
    }
    else{
        for(int i=0;i<pos-2 && p;i++){
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
    return x;
}

int main(){
    int A[]={2,3,4,5,6};
    create(A,5);
    printf("%d",Delete(head,0));
    printf("\n");
    Display(head);
}









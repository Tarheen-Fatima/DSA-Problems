#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
}*top=NULL;

void push(int x){
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Stack is Full\n");
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop(){
    int x=-1;
    struct Node* p;
    if(top==NULL){
        printf("Stack is Empty\n");
    }
    else{
        p=top;
        x=top->data;
        top=top->next;
        free(p);
    }
    return x;
}

void display(){
    struct Node* p=top;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int peek(int pos){
    struct Node* p=top;
    for(int i=0; p!=NULL && i<pos-1; i++){
        p=p->next;
    }
    if(p!=NULL){
        return p->data;
    }
    else{
        return -1;
    }
}

int stackTop(){
    if(top){
        return top->data;
    }
    return -1;
}

int isFull(){
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
    int r=t?0:1;
    free(t);
    return r;
}

int isEmpty(){
    return top?0:1;
}

int pre(char x){
    if(x=='+' || x=='-'){
        return 1;
    }
    else if(x=='*' || x=='/'){
        return 2;
    }
    return 0;
}

int isOperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/'){
        return 0;
    }
    else{
        return 1;
    }
}

char* infix_to_postfix(char *infix){
    int i=0, j=0;
    char* postfix;
    int len=strlen(infix);
    postfix=(char*)malloc((len+2)*sizeof(char));
    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else{
            while(top!=NULL && pre(infix[i])<=pre(top->data)){
                postfix[j++]=pop();
            }
            push(infix[i++]);
        }
    }
    while(top!=NULL && top->data!='#'){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    return postfix;
}

int main(){
    char *infix="a+b*c/e";
    push('#');
    char *postfix=infix_to_postfix(infix);
    printf("%s",postfix);
}

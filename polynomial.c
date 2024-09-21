#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node{
    int coeff;
    int expon;
    struct Node*next;
}*poly=NULL;

void create(){
    struct Node*t,*last=NULL;
    int num;
    int i=0;
    printf("Number of terms\n");
    scanf("%d",&num);
    printf("Enter the values of coefficient and exponent\n");
    for(i=0;i<num;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        scanf("%d%d",&t->coeff,&t->expon);
        t->next=NULL;
        if(poly==NULL){
            poly=last=t;
        }
        else{
            last->next=t;
            last=t;
        }
    }
    
}

void display(struct Node*p){
    while(p!=NULL){
        printf("%dx^%d + ",p->coeff,p->expon);
        p=p->next;
    }
    printf("\n");
}

long Eval(struct Node*p,int x){
    int sum;
    while(p!=NULL){
        sum+=p->coeff*pow(x,p->expon);
        p=p->next;
    }
    return sum;
}
int main(){
    create();
    display(poly);
    printf("\nSum of the polynomial is = %ld ",Eval(poly,1));
}


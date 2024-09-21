#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int*s;
};

void create(struct stack*st){
    printf("Enter the size:");
    scanf("%d",&st->size);
    st->top=-1;
    st->s=(int*)malloc(st->size*(sizeof(int)));
}
void display(struct stack st){
    int i;
    for(i=st.top;i>=0;i--){
        printf("%d\n",st.s[i]);
    }
    printf("\n");
}
void push(struct stack *st,int x){
    if(st->top==st->size-1){
        printf(" stack overflow\n");
    }
    else{
        st->top++;
        st->s[st->top]=x;
    }
}
int pop(struct stack*st){
    int x=-1;
    if(st->top==-1){
        printf("stack Underflow\n");
    }
    else{
        x=st->s[st->top];
        st->top--;
    }
    return x;
}
int peek(struct stack st,int index){
    int x=-1;
    if(st.top-index+1<0){
        printf("Invalid Position\n");
    }
    else{
        x=st.s[st.top-index+1];
    }
    return x;
}
int stackTop(struct stack st)
{
    if(st.top==-1){
        return -1;
    }
    else{
        return st.s[st.top];
    }
}
int isEmpty(struct stack st){
    if(st.top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack st){
    if(st.top==st.size-1){
        return 1;
    }
    else{
        return 0;
    }
}


int main()
{
    struct stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    push(&st,50);
    display(st);
    printf("%d\n", stackTop(st));
}






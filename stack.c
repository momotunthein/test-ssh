#include "stdio.h"
#include "stdlib.h"
#define MAXOFSTACK 10
 int toCount =0;
 struct stack {
     int data[MAXOFSTACK];
     int top;
 };
typedef struct stack st;
int isStackIsFull(st *myStack){
    if(myStack->top ==  MAXOFSTACK-1){
        return 1;
    }else{
        return 0;
    }
}
int isStackIsEmpty(st *myStack){
    if (myStack->top == -1){
        return 1;
    }else{
        return 0;
    }
}
void creat_emptyStack(st *myStack){
    myStack->top = -1;
}
void pushToStack(st *myStack, int value){

    if (isStackIsFull(myStack)){
        printf("Stack is Full");
    }else{
        myStack->top++;
        myStack->data[myStack->top]= value;
    }

}
void popFormStack(st *myStack){
   if(isStackIsEmpty(myStack)) {
       printf("Stack is Empty");
   }
   else{
       int count =0;
       for (int j= myStack->top; j>=0; j--) {
           printf("Pop from stack index: %d  data is: %d\n",j, myStack->data[j]);
           myStack->top--;
           count++;
       }
       printf ("Number of Pop element:%d", count);
   }

}

int main()
{
    st *myStack =(st*)malloc(sizeof(st));
    creat_emptyStack(myStack);
    pushToStack(myStack, 7);
    pushToStack(myStack, 9);
    pushToStack(myStack, 4);
    pushToStack(myStack, 87);
    pushToStack(myStack, 10);
    pushToStack(myStack, 14);
    popFormStack(myStack);
    return 0;
}
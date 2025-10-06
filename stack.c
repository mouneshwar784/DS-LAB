#include<stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int value){
        if(top >= MAX - 1){
            printf("Stack Overflow: Cannot push %d, the stack is full.\n",value);
        }
        else{
            top++;
            stack[top] = value;
            printf("Pushed %d onto the stack.\n",value);
        }
}
void pop(){
     if(top == -1){
        printf("Stack Underflow: Cannot pop, the stack is empty.\n");
     }
     else{
        printf("Popped %d from the stack.\n",stack[top]);
        top--;
     }
}
void display(){
   if(top == -1){
    printf("Stack is empty.\n");
   }
   else{
    printf("Stack contents(top to bottom):\n");
    for(int i = top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
   }
}

int main(){
  int choice,value;

  while(1){
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Display\n");
    printf("4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice){
    case 1:
        printf("Enter value to push: ");
        scanf("%d",&value);
        push(value);
        break;
    case 2:
        pop();
        break;
    case 3:
        display();
        break;
    case 4:
        printf("Exiting program.\n");
        return 0;
    default:
        printf("Invalid choice.Please try again.\n");
    }
  }
}

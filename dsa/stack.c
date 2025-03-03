#include<stdio.h>
void push();
void pop();
void display();
int i,j,choice=0,n,top = -1,stack[100];
int main()
{
  printf("Enter the no. of elements of Stack: ");
  scanf("%d",&n);
  printf("\n*********Stack Operation Using Array*********\n");
  while(choice != 4)
  {
    printf("Please Choose what operation you want to perform on stack.");
    printf("\n1.Push\n2.Pop\n3.Traverse\n4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        push();
        break;

      case 2:
        pop();
        break;
     
      case 3:
        display();
        break;

      case 4:
        printf("Exiting...\n");
        break;

      default:
        printf("Please Enter a valid choice.\n");
    }
  }
}

void push()
{
  int val;
  if(top == n-1){
    printf("Stack Overflow\n");
    return;
  }
  else{
    printf("Please Enter the value to be inserted: ");
    scanf("%d",&val);
    //top+=1;
    top=top+1;
    stack[top]=val;
    printf("The inserted value is: %d\n",val);
  }
}

void pop()
{
  int val;
  if(top == -1)
  {
    printf("Stack Underflow\n");
    return;
  }
  else{
    val=stack[top];
    top=top-1;
    printf("The popped item is: %d\n",val);
  }
}
void display() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

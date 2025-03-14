#include<stdio.h>
#include<stdlib.h>
struct queue{
  int rear;
  int front;
  int *item;
};
typedef struct queue que;
void enqueue(que *q, int n){
  int data;
  if(q->rear>=n-1)
  {
    printf("Queue Overflow.\n");
    return;
  }
  else 
  {
    printf("Enter the element to be inserted: ");
    scanf("%d",&data);
    q->rear++;
    q->item[q->rear]=data;
  }
}
void dequeue(que *q){
  int data;
   if(q->rear<q->front)
   {
    printf("The queue is empty.\n");
    return;
   }
   else 
   {
    data=q->item[q->front];
    q->front++;
    printf("The deleted item is: %d.\n",data);
   }
}
void display(que *q){
  int i;
   if(q->rear<q->front)
   {
    printf("The queue is empty.\n");
    return;
   }
   else 
   {
     printf("The elements of queue are: \n");
    for (i=q->front; i<=q->rear; i++) {
      printf("%d\t",q->item[i]);
    }
    printf("\n");
   }

}

int main()
{
  int choice=0,n;
  que q;
  printf("Enter the no. of elements of Queue: ");
  scanf("%d",&n);
  q.rear = -1;
  q.front = 0;
  q.item = (int *)malloc(n * sizeof(int));
  printf("\n*********Queue Operation Using Pointer*********\n");
  while(choice != 4)
  {
    printf("Please Choose what operation you want to perform on Queue.");
    printf("\n1.Enqueue\n2.Dequeue\n3.Traverse\n4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        enqueue(&q,n);
        break;

      case 2:
        dequeue(&q);
        break;
     
      case 3:
        display(&q);
        break;

      case 4:
        printf("Exiting...\n");
        break;

      default:
        printf("Please Enter a valid choice.\n");
    }
  }
  printf("\n-----------------------------------\n");
  printf("Programmed By Rabin Acharya.\n");

}



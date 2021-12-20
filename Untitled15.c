#include <stdio.h>
#include <stdlib.h>
// queue functions
void enqueue(int n);
void displayqueue();
int dequeue();
//stack functions
void push(int n);
int pop();
// for queue structure
struct node1
{
 int data;
 struct node1 *next;
};
struct node1 *front = 0;
struct node1 *rear = 0;
void enqueue(int n)
{
 struct node1 *newnode1;
 newnode1 = (struct node1 *)malloc(sizeof(struct node1));
 newnode1->data = n;
 newnode1->next = 0;
 if ((front == 0) && (rear == 0))
 {
 front = newnode1;
 rear = newnode1;
 }
 else
    {
 rear->next = newnode1;
 rear = newnode1;
 }
}
void displayqueue()
{
 struct node1 *temp;
 if ((front == 0) && (rear == 0))
 {
 printf("The queue is empty");
 }
 else
 {
 temp = front;
 while (temp != 0)
 {
 printf("%d<--", temp->data);
 temp = temp->next;
 }
 }
}
int dequeue()
{
 struct node1 *temp;
 int k;
 temp = front;
 if ((front == 0) && (rear == 0))
 {
 printf("The queue is empty (underflow)");
 return 0;
 }
 else
 {
 k = front->data;
 front = front->next;
 free(temp);
 return k;
 }
}
//for stack structure
struct node2
{
 int data2;
 struct node2 *next2;
};
struct node2 *top = 0;
void push(int n)
{
 struct node2 *newnode;
 newnode = (struct node2 *)malloc(sizeof(struct node2 *));
 newnode->data2 = n;
 newnode->next2 = top;
 top = newnode;
}
int pop()
{
 struct node2 *temp;
 int k;
 temp = top;
 if (top == 0)
 {
 printf("underflow of stack");
 return 0;
 }
 else
 {
 k = top->data2;
 top = top->next2;
 free(temp);
 return k;
 }
}
int main()
{
 int count, num;
 printf("Enter number of elements you would like to insert in the queue:\n"
);
 scanf("%d", &count);
 printf("Enter the values:\n");
 for (int i = 0; i < count; i++)
 {
 scanf("%d", &num);
 enqueue(num);
 }
 printf("The current queue is:\n");
 displayqueue();
 int k;
 printf("\nEnter the number of elements you want to reverse from the start:\n");
 scanf("%d", &k);
 for (int i = 0; i < k; i++)
 {
 push(dequeue());
 }
  for (int i = 0; i < k; i++)
 {
 enqueue(pop());
 }
 for (int i = 0; i < (count - k); i++)
 {
 enqueue(dequeue());
 }
 printf("The queue after reversing elements is:\n");
 displayqueue();
 return 0;
}


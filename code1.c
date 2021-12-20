#include <stdio.h>
#include <stdlib.h>
void begininsert();
void insertnode();
void printlist();
void deletenode();
struct node
{
 int data;
 struct node *next;
};
struct node *head;
void begininsert()
{
 struct node *newnode;
 newnode = (struct node *)malloc(sizeof(struct node));
 printf("Enter the new node that you want to insert:\n");
 scanf("%d", &newnode->data);
 newnode->next = head;
 head = newnode;
}
void insertnode()
{
 int pos, count = 1;
 struct node *temp = head;
 struct node *newnode = (struct node *)malloc(sizeof(struct node));
 printf("Enter the Insert Position\n");
 scanf("%d", &pos);
 printf("Enter the data\n");
 scanf("%d", &newnode->data);
 while (count < pos - 1)
 {
 temp = temp->next;
 count++;
 }
 newnode->next = temp->next;
 temp->next = newnode;
}
void printlist()
{
 struct node *temp;
 temp = head;
 printf("The linked list is :\n");
 while (temp != NULL)
 {
 printf("%d--->", temp->data);
 temp = temp->next;
 }
}
void deletenode()
{
 int position, count = 1;
 struct node *nextnode, *temp = head;
 printf("Enter Delete Position \n");
 scanf("%d", &position);
 while (count < position - 1)
 {
 temp = temp->next;
 count++;
 }
 nextnode = temp->next;
 temp->next = nextnode->next;
 free(nextnode);
}
int main()
{
 int num;
 struct node *newnode, *temp;
 head = NULL;
 int n = 1;
 while (n == 1)
 {
 newnode = (struct node *)malloc(sizeof(struct node));
 printf("Enter the numbers:\n");
 scanf("%d", &newnode->data);
 newnode->next = NULL;
 if (head == NULL)
 {
 head = newnode;
 temp = newnode;
 }
 else
 {
 temp->next = newnode;
 temp = newnode;
 }
 printf("for continuing the linked list enter 1 or 0:\n");
 scanf("%d", &n);
 }
 printf("Your current linked list is:\n");
 printlist();
 printf("\nChoose the task you would like to do on your linked list:\n");
 printf("enter 1 if you want to insert an element in the beginning:\n");
 printf("enter 2 if you want to insert an element at a specific position:\n");
 printf("enter 3 if you want to delete an element at a specific position:\n");
 printf("Your choice is:\n");
 scanf("%d", &num);
 if (num == 1)
 {
 begininsert();
 printf("The list after begining insertion is:\n");
 printlist();
 }
 else if (num == 2)
 {
 insertnode();
 printf("The list after insertion is:\n");
 printlist();
 }
 else if (num == 3)
 {
 deletenode();
 printf("The list after deletion is :\n");
 printlist();
 }
 return 0;
}

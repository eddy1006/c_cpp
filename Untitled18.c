#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
 struct node * f = '\0';
    struct node * r = '\0';
void enqueue(int val)
{
    struct node* sp = (struct node*)malloc(sizeof(struct node));
    if(sp == '\0')
        printf("Queue is full");
    else
    {
        sp->data = val;
        sp->next = '\0';
        if(f == '\0' && r == '\0')
        {
            f =sp;
            r =sp;
            r->data = val;
            printf("inserted %d \n",r->data);
        }
        else
        {
            r->next = sp;
            r = sp;
            r->data = val;
            r->next = '\0';
             printf("inserted %d \n",r->data);
        }
    }
}
int dequeue( )
{
    int val =-1;
    struct node *ptr;
    ptr = f;
    if(f == '\0')
    {
      printf("QUEUE IS EMPTY");
    }
    else
    {
        f = f->next;
        val = ptr->data;

    }
    return val;
}
int main()
{


    enqueue(34);
    enqueue(56);
    enqueue(21);
    enqueue(90);
    printf("Deleted %d \n",dequeue(f));
     printf("Deleted %d \n",dequeue(f));
       printf("Deleted %d \n",dequeue(f));
         printf("Deleted %d \n",dequeue(f));
    return 0;
}

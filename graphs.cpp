#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data ;
    struct node* next_ptr;
};

struct list
{
    struct node* head;
};

struct graph
{
    int v;
    struct list* array;
};

struct node* createNode(int x)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = x;
    node->next_ptr = NULL;
    return node;
}

struct graph* createGraph(int v)
{
    struct graph* graph = (struct graph*)malloc(sizeof(struct graph));
    graph->v = v;
    graph->array = (struct list*)malloc(v*sizeof(struct list));
    for(int i=0;i<v;i++)
    {
        graph->array[i].head = NULL;
    }
    return graph;
}

void addEdge(struct graph* graph,int source,int destinaton)
{
    struct node* d;
    d = createNode(destinaton);
    d->next_ptr = graph->array[source].head;
    graph->array[source].head = d;
}

void printGraph(struct graph* graph)
{
    for(int i=0;i<graph->v;i++)
    {
        printf("Vertex :%d-->",i);
        struct node* temp = graph->array[i].head;
        while(temp!=NULL)
        {
            printf("%d -->",temp->data);
            temp = temp->next_ptr;
        }
        printf("\n");
    }
}

int main(void)
{
    struct graph* graph = createGraph(5);
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,0);
    addEdge(graph,1,3);
    addEdge(graph,2,0);
    addEdge(graph,3,1);
    addEdge(graph,3,4);
    addEdge(graph,4,3);
    addEdge(graph,4,2);
    addEdge(graph,2,4);
    printGraph(graph);
}

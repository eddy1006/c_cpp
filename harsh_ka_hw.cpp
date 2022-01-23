#include <bits/stdc++.h>
using namespace std;

struct Book {
    string title;
    string author;
    string publisher;
    int year;
    int isbn;
    int price;
};

struct Node {
    struct Node* next;
    Book* data;
    struct Node* prev;
};

Node* head = NULL;

bool isEmpty() {
    if (head == NULL)
        return true;

    return false;
}
void top_element()
{
    if (isEmpty())
        cout << "stack is empty" << endl;
    else
        cout << "Top: " << head->data->isbn << endl;
}
void push(Book* data) {

    struct Node* temp;
    temp = new Node();
    if (isEmpty())
    {
        temp->data = data;
        temp->prev = NULL;
        temp->next = NULL;
        head = temp;
    }
    else
    {   temp->data = data;
        temp->next = head;
        head->prev = temp;
        temp->prev = NULL;
        head = temp;
    }
}

void stack_size()
{
    int count = 0;

    Node* curr = head;

    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }

    cout << "size: " << count << endl;
}

void pop() {

    struct Node* temp;
    temp = new Node();

    if (isEmpty())
        cout << "stack is empty" << endl;
    else if (head->next == NULL && head->prev == NULL)
    {
        temp = head;
        head = NULL;
        delete(head);
    }
    else
    {   temp = head;
        head = head->next;
        head->prev = NULL;
        delete(temp);
    }
}

void print_stack() {

    Node* curr = head;

    cout << "elements are: ";

    while (curr != NULL)
    {
        cout << curr->data->author << " ";
        cout << curr->data->isbn << " ";
        cout << curr->data->title << " ";
        cout << curr->data->price << " ";
        cout << curr->data->year << " ";
        cout << curr->data->publisher <<"\n";
        curr = curr->next;

    }

    cout << endl;

}

void stack_sum() {

    Node* curr = head;

    cout << "sum of prices of all books : ";
    int sum = 0;

    while (curr != NULL)
    {
        sum += curr->data->price;
        curr = curr->next;

    }

    cout <<sum<< endl;

}

int main() {
  
    Book* book1 = new Book();
    book1->author = "harsh gatotkach";
    book1->title = "op bolte chaddi kholte";
    book1->price = pow(10,5);
    book1->publisher = "gupta electrionics";
    book1->year = 2077;
    book1->isbn = 0;
    Book* book2 = new Book();
    book2->author = "harsh gatotk2ach";
    book2->title = "op bolte chaddi kholte";
    book2->price = pow(10,5);
    book2->publisher = "gupta electrionics";
    book2->year = 2077;
    book2->isbn = 1;
    Book* book3 = new Book();
    book3->author = "harsh gatotkach";
    book3->title = "op bolte chaddi kholte";
    book3->price = pow(10,5);
    book3->publisher = "gupta electrionics";
    book3->year = 2077;
    book3->isbn = 2;
    Book* book4 = new Book();
    book4->author = "harsh gatotkach";
    book4->title = "op bolte chaddi kholte";
    book4->price = pow(10,5);
    book4->publisher = "gupta electrionics";
    book4->year = 2077;
    book4->isbn = 3;
    Book* book5 = new Book();
    book5->author = "harsh gatotkach";
    book5->title = "op bolte chaddi kholte";
    book5->price = pow(10,5);
    book5->publisher = "gupta electrionics";
    book5->year = 2077;
    book5->isbn = 4;
    push(book1);
    push(book2);
    push(book3);
    push(book4);
    push(book5);
    stack_sum();
    print_stack();
    stack_size();
    top_element();
    pop();
    print_stack();
    stack_size();
    pop();
    print_stack();
    stack_size();
    top_element();
    return 0;
}
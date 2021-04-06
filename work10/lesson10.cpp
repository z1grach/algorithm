#include <iostream>

using namespace std;

typedef struct Node{
    int dat;
    struct Node *next;
}Node;

typedef struct{
    Node *head;
    int sz;
}List;


void init(List *from)
{
    from->head=NULL;
    from->sz=0;
}


void ins(List *from, int data)
{
    Node *nw=new Node[sizeof(Node)];
    nw->dat=data;
    nw->next=NULL;

    Node *current=from->head;

    if(current == NULL){
        from->head=nw;
        from->sz++;
        return;
    }
    else{
        while(current->next != NULL){
            current=current->next;
        }
        current->next=nw;
        from->sz++;
    }
}


void copyList(List *from, List *to)
{
    if(from->head==NULL){
        to->head==NULL;
        to->sz=0;
        cout << "List is empty\n";
        return;
    }

    to->head=from->head;
    Node *parent=from->head;
    Node *current=to->head;
    to->sz=1;

    while(parent->next != NULL){
        current->next->dat=parent->next->dat;
        ++to->sz;
        parent=parent->next;
        current=current->next;
    }
}


void printNode(Node *n)
{
    if(n==NULL){
        cout << "[]";
        return;
    }
    printf("[%d] ",n->dat);
}


void printList(List *lst)
{
    Node *current=lst->head;
    if(current==NULL){
        printNode(current);
    }
    else{
        do{
            printNode(current);
            current=current->next;
        }while(current!=NULL);
    }
    printf("Size: %d \n", lst->sz);
}


bool sortList(List *lst)
{
    Node *current=lst->head;
    while(current->next != NULL){
        if(current->dat > current->next->dat)
            return false;
        current=current->next;
    }
    return true;
}

int main()
{
//Ex.2
    List *from=new List[sizeof(List)];
    List *to=new List[sizeof(List)];
    init(from);
    ins(from, 4);
    ins(from, 5);
    ins(from, 7);
    ins(from, 8);
    ins(from, 9);
    copyList(from, to);
    printList(to);

//Ex.3
    sortList(from) ? cout << "True\n" : cout << "False\n";

    delete [] from;
    delete [] to;

    return 0;
}

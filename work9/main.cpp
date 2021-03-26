#include <iostream>
#define SIZE 10

using namespace std;

typedef struct{
    int pr;
    int dat;
}Node;

Node *qu[SIZE];
int head;
int tail;
int items;


void init()
{
    for(int i=0; i<SIZE; ++i){
        qu[i]=NULL;
    }

    head=0;
    tail=0;
    items=0;
}


void ins(int pr, int dat)
{
    Node *arr=new Node[sizeof(Node)];
    arr->dat=dat;
    arr->pr=pr;


    if(items==SIZE){
        cout << "Queue is full\n";
        return;
    }
    else{
        qu[tail++]=arr;
        ++items;
    }
}


void rem()
{
    if(items==0)
        cout << "Queue is empty\n";
    else{
        int maxPr=qu[head]->pr;
        int idx;
        for(int i=head; i<tail; ++i){
            if(maxPr<=qu[i]->pr){
                maxPr=qu[i]->pr;
                idx=i;
            }
        }

        for(int i=idx+1; i<tail; ++i){
            qu[i-1]=qu[i];
        }
        qu[--tail]=NULL;
        --items;
    }
}


void printQueue()
{
    cout << "[ ";
    for(int i=0; i<SIZE; ++i){
        if(qu[i]==NULL)
        cout << "[*, *] ";
        else printf("[%d, %d] ", qu[i]->pr, qu[i]->dat);
    }
    cout << " ]\n";
}


//---------------------------------------------------------------------


#define T int

int cursor=-1;
T Stack[SIZE];

T dvoich(T n)
{
    if(n==1){
        Stack[++cursor]=1;
    }
    else{
        Stack[++cursor]=n%2;
        dvoich(n/2);
    }
}


bool push(T data)
{
    if(cursor<SIZE){
        dvoich(data);
        return true;
    }
    else{
        cout << "Stack overflow\n";
        return false;
    }
}


T pop()
{
    if(cursor!=-1)
        return Stack[cursor--];
    else{
        cout << "Stack is empty\n";
        return -1;
    }
}


int main()
{
//Ex.1
    init();
    ins(1, 11);
    ins(3, 22);
    ins(6, 33);
    ins(2, 44);
    ins(2, 55);
    ins(7, 77);
    ins(4, 88);
    ins(3, 99);
    ins(6, 100);
    ins(6, 66);
    printQueue();

    rem();
    printQueue();

    rem();
    printQueue();

    rem();
    printQueue();

//---------------------------------
    cout << "\n\n\n";

//Ex.2
    int num=155;
    push(num);
    cout << num << " = ";
    while(cursor!=-1)
        cout << pop() << ' ';

    return 0;
}

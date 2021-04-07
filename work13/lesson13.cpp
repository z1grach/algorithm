#include <iostream>

using namespace std;

typedef struct OneLinkNode {
    int dat;
    struct OneLinkNode *next;
} OneLinkNode;

typedef struct {
    OneLinkNode *head;
    int size;
} OneLinkList;

void initOneLinkList(OneLinkList *lst) {
    lst->head = NULL;
    lst->size = 0;
}


int get2dInt(int** array, const int row, const int col) {
    return *((*(array + row)) + col);

}


void set2dInt(int** array, const int row, const int col, int value) {
    *((*(array + row)) + col) = value;
}


int** init2dIntArray(int** array, const int row, const int col) {
    array = (int**) calloc(sizeof(int*), row);
    for (int i = 0; i < row; ++i) {
        *(array + i) = (int*) calloc(sizeof(int), col);
    }
    return array;
}


void free2dIntArray(int** array, const int row, const int col) {
    for (int i = 0; i < row; ++i) {
        free(array[i]);
    }
    free(array);
}


bool pushOneLinkStack(OneLinkList *stack, int value)
{
    OneLinkNode *tmp = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    if (tmp == NULL) {
        printf("Stack overflow \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->size++;
    return true;
}


int popOneLinkStack(OneLinkList *stack)
{
    if (stack->size == 0) {
        printf("Stack is empty \n");
        return -1;
    }
    OneLinkNode *tmp = stack->head;
    int data = stack->head->dat;
    stack->head = stack->head->next;
    free(tmp);
    stack->size--;
    return data;
}


void clearVisited(int* arr, int SZ) {
    for (int i = 0; i < SZ; ++i) {
        arr[i] = 0;
    }
}


void depthTraversStack(int** matrix, int start, const int size) {
    OneLinkList* Stack = new OneLinkList[sizeof(OneLinkList)];
    initOneLinkList(Stack);
    int visited[size];
    clearVisited(visited, size);
    pushOneLinkStack(Stack, start);
    while (Stack->size > 0) {
        int indx = popOneLinkStack(Stack);
        if (visited[indx] == 1) continue;
        visited[indx] = 1;
        printf("%d ", indx);
        for (int i = size-1; i >=0; --i) {
            if (get2dInt(matrix, indx, i) == 1 && visited[i] == 0)
                pushOneLinkStack(Stack, i);
        }

    }
}


void exer1()
{
    const int SZ = 6;
    int** adjacency = init2dIntArray(adjacency, SZ, SZ);
    set2dInt(adjacency, 0, 1, 1);
    set2dInt(adjacency, 0, 2, 1);
    set2dInt(adjacency, 1, 3, 1);
    set2dInt(adjacency, 1, 4, 1);
    set2dInt(adjacency, 1, 5, 1);
    set2dInt(adjacency, 2, 5, 1);
    set2dInt(adjacency, 3, 0, 1);
    set2dInt(adjacency, 5, 4, 1);

    depthTraversStack(adjacency, 0, SZ);
    printf("\n\n");
    free2dIntArray(adjacency, SZ, SZ);
}

/*
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
*/

//----------------------------------------------------------------------------



typedef struct TwoLinkNode {
    int dat;
    struct TwoLinkNode *next;
    struct TwoLinkNode *prev;
} TwoLinkNode;

typedef struct {
    struct TwoLinkNode *head;
    struct TwoLinkNode *tail;
    int size;
} TwoLinkList;


void initTwoLinkList(TwoLinkList *lst) {
    lst->head = NULL;
    lst->tail = NULL;
    lst->size = 0;
}


bool TwoLinkEnqueue(TwoLinkList *queue, int value) {
    TwoLinkNode *tmp = (TwoLinkNode*) malloc(sizeof(TwoLinkNode));
    if (tmp == NULL) {
        printf("Out of memory! \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = NULL;
    tmp->prev = queue->tail;

    if (queue->tail != NULL) {
        queue->tail->next = tmp;
    }
    if (queue->head == NULL) {
        queue->head = tmp;
    }

    queue->tail = tmp;
    queue->size++;
    return true;
}


int TwoLinkDequeue(TwoLinkList *queue) {
    if (queue->size == 0) {
        printf("Queue is empty \n");
        return -1;
    }
    TwoLinkNode *tmp = queue->head;
    int data = queue->head->dat;

    queue->head = queue->head->next;

    if (queue->head != NULL) {
        queue->head->prev = NULL;
    }
    if (tmp == queue->tail) {
        queue->tail = NULL;
    }

    free(tmp);
    queue->size--;
    return data;
}


void adjacencyCount(int** matrix, int start, const int size)
{
    TwoLinkList* queue = (TwoLinkList*) malloc(sizeof(TwoLinkList));
    initTwoLinkList(queue);
    int visited[size];
    int listCount[size];
    clearVisited(visited, size);
    clearVisited(listCount, size);
    TwoLinkEnqueue(queue, start);
    while (queue->size > 0) {
        int indx = TwoLinkDequeue(queue);
        if (visited[indx] == 1) continue;
        visited[indx] = 1;

        for (int i = 0; i < size; ++i) {
            if (get2dInt(matrix, indx, i) == 1 && visited[i] == 0){
                TwoLinkEnqueue(queue, i);
                ++listCount[i];
            }
            if(indx==i && get2dInt(matrix, indx, i)==1)
                ++listCount[i];
        }
    }
    cout << "\n\nKol-vo ssilok na kajdi uzel \n";
    cout << "A B C D E F \n";
    for (int i = 0; i < size; ++i)
        cout << listCount[i] << " ";
    cout << "\n\n";
}

int visitedDepth[6] = {0};
int ssilkaCount[6] = {0};
void traversalCount(int** matrix, int start, const int size)
{
    int r;
    visitedDepth[start] = 1;

    for (r = 0; r < size; ++r) {
        if (matrix[start][r] == 1 && !visitedDepth[r]) {
            ++ssilkaCount[r];
            traversalCount(matrix, r, size);
        }
        if(start==r && matrix[start][r] == 1)
            ++ssilkaCount[r];
    }
}


/*
        {0, 1, 0, 0, 0, 0},
        {1, 0, 1, 1, 1, 0},
        {0, 1, 0, 1, 0, 0},
        {0, 1, 1, 1, 0, 0},
        {0, 1, 0, 0, 1, 1},
        {0, 0, 0, 0, 1, 0},
*/

void exer2()
{
    const int SZ = 6;
    int** adjacency = init2dIntArray(adjacency, SZ, SZ);
    set2dInt(adjacency, 0, 1, 1);
    set2dInt(adjacency, 1, 0, 1);
    set2dInt(adjacency, 1, 2, 1);
    set2dInt(adjacency, 1, 3, 1);
    set2dInt(adjacency, 1, 4, 1);
    set2dInt(adjacency, 2, 1, 1);
    set2dInt(adjacency, 2, 3, 1);
    set2dInt(adjacency, 3, 1, 1);
    set2dInt(adjacency, 3, 2, 1);
    set2dInt(adjacency, 3, 3, 1);
    set2dInt(adjacency, 4, 1, 1);
    set2dInt(adjacency, 4, 4, 1);
    set2dInt(adjacency, 4, 5, 1);
    set2dInt(adjacency, 5, 4, 1);

    adjacencyCount(adjacency, 0, SZ);
    traversalCount(adjacency, 0, SZ);
    for (int i = 0; i < SZ; ++i)
        cout << ssilkaCount[i] << " ";


    free2dIntArray(adjacency, SZ, SZ);
}


int main()
{
//Ex.1
    exer1();
//Ex.2
    exer2();

    return 0;
}

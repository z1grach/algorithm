#include <iostream>

using namespace std;


typedef struct OneLinkNode {
    int dat;
    struct OneLinkNode *next;
} OneLinkNode;

int htSize;


int simpleHashSum(char* arr, const int SZ)
{
    int sum=0, idx=0;
    for (int i = SZ-2; i >= 0; --i) {
         ++idx;
         sum+=arr[i]%idx;
    }
    return sum;
}


bool chainInsertNode(OneLinkNode **table, int data, int idx) {
    OneLinkNode *p, *p0;

    int bucket = idx;
    p = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    if (p == NULL) {
        printf("Out of memory! \n");
        return false;
    }

    p0 = table[bucket];
    table[bucket] = p;
    p->next = p0;
    p->dat = data;
    return true;
}


void printTable(OneLinkNode** table, int size) {
    OneLinkNode *p;
    for (int i = 0; i < size; ++i) {
        p = table[i];
        while (p) {
            printf("%5d", p->dat);
            p = p->next;
        }
        printf("\n");
    }
    printf("\n");
}


void exer1() {
    htSize = 8;
    char* arr="Hello";
    const int SZ = 6;

    OneLinkNode** hashTable = (OneLinkNode**) calloc(256, sizeof(OneLinkNode*));
    int idx=simpleHashSum(arr, SZ);
    for(int i=0; i<SZ-1; ++i)
    chainInsertNode(hashTable, arr[i], idx);

    printTable(hashTable, htSize);

    free(hashTable);

}

//__________________________________________________________________________________


int exchange(int* money, int size)
{
    int sum = 0, k=0;
    while(sum!=98){
        while(sum+money[k]<=98){
            sum+=money[k];
            cout << money[k] << " ";
        }
        ++k;
    }

    cout << "\n";
    return sum;
}

void exer2()
{
    const int size = 5;
    int money[5] = {50, 10, 5, 2, 1};
    cout << "\n\n" << exchange(money, size);
}


int main()
{
//Ex.1
    exer1();
//Ex.2
    exer2();

    return 0;
}

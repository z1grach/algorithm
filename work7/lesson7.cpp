#include <iostream>

using namespace std;

int funSwap(int *a, int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void printArr(int *arr, const int SIZE)
{
    for(int i=0; i<SIZE; ++i){
        cout << arr[i] << " ";
    }
    cout << '\n';
}


int vibor(int *arr, int first, int last);
void sortVstavka(int* arr, const int SIZE);
int qs(int *arr, int first, int last);


int main()
{
//Ex.1
    const int SIZE=8;
    int arr[SIZE]={10,6,2,0,1,5,7,15};

    vibor(arr, 0, SIZE-1);
    printArr(arr, SIZE);


    return 0;
}


int vibor(int *arr, int first, int last)
{
    if(last-first<=9) sortVstavka(arr, last+1);
    else {
        int mid=first+last/2;

        while(arr[first]>arr[mid] && arr[mid]>arr[last]){
            if(arr[first]>arr[mid])
                funSwap(&arr[first], &arr[mid]);
            if(arr[mid]>arr[last])
                funSwap(&arr[first], &arr[last]);
        }

        qs(arr, first, last);
    }
}


void sortVstavka(int* arr, const int SIZE)
{
    int temp, pos;
    for (int i = 1; i < SIZE; ++i) {
        temp = arr[i];
        pos = i - 1;
        while (pos >= 0 && arr[pos] > temp) {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = temp;
    }
}


int qs(int *arr, int first, int last)
{
    int i=first;
    int j=last;

    int x=arr[(first+last)/2];

    do{
            while(arr[i]<x) i++;
            while(arr[j]>x) j--;

            if(i<=j){
                funSwap(&arr[i], &arr[j]);
                i++;
                j--;
            }

    }while(i<=j);

    if(i<last) vibor(arr, i, last);
    if(first<j) vibor(arr, first, j);
}

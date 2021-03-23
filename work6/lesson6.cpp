#include <iostream>
#include <cmath>


using namespace std;

int funSwap(int *a, int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void sortPuzir(int arr[][3], int const row, int const col)
{

    for(int k=0; k<row*col; ++k){
        for(int i=0; i<row; ++i){
            for(int j=0; j<col-1; ++j){
                if(arr[i][j]>arr[i][j+1])
                    funSwap(&arr[i][j], &arr[i][j+1]);
            }
            while ((arr[i][col-1]>arr[i+1][0]) && i!=row-1)
                funSwap(&arr[i][col-1], &arr[i+1][0]);
        }
    }

}


void printArray(int arr[][3], int const row, int const col)
{
    for(int i=0; i<row; ++i){
        for(int j=0; j<col; ++j){
            cout << arr[i][j] << "  ";
        }
        cout << '\n';
    }
}

//--------------------------------------------------------------------------------------------


void sortShake(int *arr, int const SIZE)
{
    int l=0, r=SIZE-1;

    while(l<=r){
    for(int i=l; i<r; ++i){
        if(arr[i]<arr[i+1])
            funSwap(&arr[i], &arr[i+1]);
    }
    for(int i=r-1; i>l; --i){
        if(arr[i]>arr[i-1])
            funSwap(&arr[i], &arr[i-1]);
    }
    --r;
    ++l;
    }
}


void knut(int *arr, int const SIZE)
{
    int i=0, result=0;
    while(i!=SIZE || result>400){
        result=sqrt(fabs(arr[i])) + 5 * pow(arr[i], 3);
        ++i;
    }
    if(i==SIZE)
        cout << "Takogo chisla net\n";
    else if(result>400)
        printf("Chislo %d previshaet 400\n", arr[i]);
}

int main()
{
//Ex.1
    int const row=3;
    int const col=3;
    int arr[row][col]={{1,9,2},
                       {5,7,6},
                       {4,3,8}};
    sortPuzir(arr, row, col);
    printArray(arr, row, col);


//Ex.3
    int const SIZE=11;
    int p[SIZE];
    for (int i=0; i<SIZE; i++)
        cin >> p[i];
    sortShake(p, SIZE);
    knut(p, SIZE);

    return 0;
}

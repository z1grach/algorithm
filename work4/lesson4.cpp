#include <iostream>

using namespace std;

int dvoich(int n)
{
    if(n==1){
        cout << n;
        return 1;
    }
    else{
        dvoich(n/2);
        cout << n%2;
    }
}


int step(const int num, int stepen)
{
    return (stepen==0) ? 1 : num*step(num, stepen-1);
}


int svoistva(int num, int stepen)
{
    if(stepen==0){
        return 1;
    }
    else
        return (stepen%2==0) ? svoistva(num*num, stepen/2) : num*svoistva(num, stepen-1);
}


int korol(int m, int n)
{
    if( (m==0 && n==0) || (m==1 && n==2) || (m==3 && n==1))
        return 0;
    else if(m==0 ^ n==0)
        return 1;
    else return korol(m, n-1) + korol(m-1, n);
}

int main()
{
//Ex.1
    dvoich(54);
    cout << "\n\n";

//Ex.2
    int a=4, b=7;
    cout << step(a, b);
    cout << "\n\n";

//Ex.3
    a=3;
    b=7;
    cout << svoistva(a, b);
    cout << "\n\n";

//Ex.4
    int hod[4][4]={0};
    for(int m=0; m<4; ++m){
        for(int n=0; n<4; ++n){
            hod[m][n]=korol(m, n);
        }
    }

    for(int m=0; m<4; ++m){
        for(int n=0; n<4; ++n){
            cout << hod[m][n] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

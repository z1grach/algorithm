#include <iostream>

using namespace std;

int main()
{
    bool result=true;
    int num=23;
    int i=2;
    while(i<num){
        if(num%i++ == 0){
            result=false;
            break;
        }
    }

    cout << result;
    return 0;
}

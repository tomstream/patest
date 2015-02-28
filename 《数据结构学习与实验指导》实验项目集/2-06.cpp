
#include <iostream>
#include <string>
using namespace std ;



int main(void)
{
    int A,N;
    cin >> A >> N;
    string s;
    int thisCount;
    int carry(0);
    char c;
    int temp;
    for(int i=0;i < N;i++)
    {
        temp=(N-i)*A+carry;
        thisCount = temp % 10;
        carry = temp / 10;
        
        c= '0'+thisCount;
        s= c + s;
    }
    c='0'+carry;
    if(carry) s= c + s;
    if(!N) cout << '0';
    else cout << s;

    return 0;
}
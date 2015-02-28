
#include <iostream>
#include <string>
using namespace std ;

int nextPrimeNumber(int n){
    int nextNumber=(n%2)?n+2:n+1;
    int middle=nextNumber/2;
    bool flag;
    
    if(n==1)return 2;
    while(1){
        flag=1;
        for(int i=3;i<middle;i+=2)
            if(nextNumber%i==0){flag=0;break;}
        if(flag)return nextNumber;
        nextNumber+=2;
    }
}

int main(void)
{
    long int N;
    int i(0);
    int prime(1);
    
    cin >> N;
    cout << N << '=';
    
    if(N==1)cout << '1';
    while(N!=1)
    {
        prime=nextPrimeNumber(prime);
        while( N % prime == 0 )
        {
            N = N/prime;
            ++i;
        }
        if(i)
        {
            cout << prime;
            if(i!=1)cout << '^' << i;
            if(N!=1)cout << '*';
        }
        i=0;
    }
    return 0;
}
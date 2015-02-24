/*
int nextPrimeNumber(int n);
 求下一个素数
 */

#include <iostream>
#include <string>
using namespace std;

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


int main(){
    int n,nextPrime,presentPrime(3),count(0);
    cin>>n;
    while(1){
        nextPrime=nextPrimeNumber(presentPrime);
        if(nextPrime>n)break;
        if(nextPrime-presentPrime==2)count++;
        presentPrime=nextPrime;
    }
    cout<<count;
    return 0;
}

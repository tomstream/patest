/*
1008. 数组元素循环右移问题 (20)
 */

#include <iostream>
#include <string>
using namespace std;

int returnPosition(int n,int m,int N)
{
    return (m+n) % N;
}

int main()
{
    int N,M;
    cin>>N>>M;
    int a[N];
    int m=M%N;
    int temp;
    
    for(int i=0;i<N;i++)
    {
        cin>>temp;
        a[returnPosition(i,m, N)]=temp;
    }
    for(auto &i:a)
    {
        cout<<i;
        if(&i!=a+N-1)cout<<' ';
    }
    
    
    return 0;
}
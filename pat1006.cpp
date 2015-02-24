#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    string s;
    int m=n/100;
    for(int i=0;i<m;i++)s=s+'B';
    
    m=n%100/10;
    for(int i=0;i<m;i++)s=s+'S';
    
    cout<<s;
    
    m=n%10;
    for(int i=1;i<=m;i++)cout<<i;
    
}

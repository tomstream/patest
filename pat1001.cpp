#include <sstream>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    long a,b;
    cin>>a>>b;
    stringstream ss;
    string s;
    ss<<a+b;
    ss>>s;
    
    size_t count=s.size();
    for(size_t i=0;i<count;i++)
    {
        
        cout<<s[i];
        if((count-1-i)%3==0&&count-1!=i&&s[i]!='-')
            cout<<',';
    }
    
    
    return 0;
}



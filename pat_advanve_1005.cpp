#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

long long int convertToRadix(char c)
{
    if('0'<=c&&c<='9')return static_cast<long long int>(c-'0');
    else return static_cast<long long int>(c-'a')+10;
}

long long int convertToRadix(string& s,long long int radix)
{
    long long int ret(0);
    
    for(auto c:s)
    {
        ret=ret*radix+convertToRadix(c);
    }
    return ret;
}

int main()
{
    string a,b;
    long long int tag,radix;
    cin>>a>>b>>tag>>radix;
    
    if(a==b)
    {
        cout<<radix;return 0;
    }
    
    if(tag==2)std::swap(a,b);
    
    long long int radixMin=convertToRadix(*max_element(b.begin(), b.end()))+1;
    
    long long int decimalForA=convertToRadix(a, radix);
    long long int radixB=decimalForA;
    
    if(b.size()!=1)
        radixB=pow(decimalForA/convertToRadix(b[0]),1.0/(b.size()-1));
    
    long long int decimalForB=convertToRadix(b,radixB);
    if(decimalForA==decimalForB&&radixB>=radixMin)
    {
        cout<<radixB;return 0;
    }
    
    for(long long int i=(radixB-radixB/10>radixMin)?radixB-radixB/10:radixMin;i<radixB+radixB/10+5;i++)
    {
        decimalForB=convertToRadix(b,i);
        if(decimalForA==decimalForB)
        {
            cout<<i;return 0;
        }
    }
    cout<<"Impossible";return 0;
}

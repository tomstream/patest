
#include <iostream>
#include <stdio.h>
#include <set>
#include <math.h>
using namespace std ;

int main(void)
{
    int                     n;
    cin >> n;
    
    multiset<double>        numbers;
    double                  temp;
    for(int i = 0;i < n;i++)
    {
        cin >> temp;
        numbers.insert(temp);
    }
    
    double                     sum1(0),sum2(0);
    for(auto &i: numbers)
    {
        sum1+=i;sum2+=i*i;
        
    }

    
    
    double                     variance;
    variance = sum2/numbers.size()-(sum1/numbers.size())*(sum1/numbers.size());
    printf("%.5f",pow(variance,0.5));
    
    return 0;
    
}

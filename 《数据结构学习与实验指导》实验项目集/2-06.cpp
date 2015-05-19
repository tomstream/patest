//
//  cppprogram
//
//  Created by thomas on 15/5/7.
//  Copyright (c) 2015年 thomas. All rights reserved.
//

#include <iostream>
#include <list>
using namespace std;

int main()
{
    int N,value;
    cin>>value>>N;
    int carry=0;
    int bit;
    int thisbit;
    list<int> l;
    
    if(N==0)
    {
        cout<<0;
        return 0;
    }
    
    for(int i=0;i<N;i++)
    {
        thisbit=carry+(N-i)*value;
        bit=thisbit%10;
        carry=thisbit/10;
        l.push_back(bit);
    }
    while(carry!=0)
    {
        bit=carry%10;
        carry=carry/10;
        l.push_back(bit);
    }
    
    for(auto riter=l.rbegin();riter!=l.rend();riter++)
    {
        cout<<*riter;
    }
    
    return 0;
}

//
//#include <iostream>
//#include <string>
//using namespace std ;
//
//
//
//int main(void)
//{
//    int A,N;
//    cin >> A >> N;
//    string s;
//    int thisCount;
//    int carry(0);
//    char c;
//    int temp;
//    for(int i=0;i < N;i++)
//    {
//        temp=(N-i)*A+carry;
//        thisCount = temp % 10;
//        carry = temp / 10;
//        
//        c= '0'+thisCount;
//        s= c + s;
//    }
//    c='0'+carry;
//    if(carry) s= c + s;
//    if(!N) cout << '0';
//    else cout << s;
//
//    return 0;
//}


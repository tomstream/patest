/*
1012. 数字分类 (20) */

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std ;


int nextFlag()
{
    static int      flag(-1);
    
    if( flag == 1 ) flag = -1 ;
    else flag = 1;
    
    return flag;
}

void readLineInt(vector<int> &v)
{
    char            c;
    int             tempNumber = 0;
    while( 1 )
    {
        cin.get( c ) ;
        if( '0' <= c && c <= '9' )
        {
            tempNumber = tempNumber * 10 + c - '0';
        }
        else if( c == ' ' )
        {
            v.push_back(tempNumber);
            tempNumber = 0;
        }
        else
        {
            v.push_back(tempNumber);
            break;
        }
    }
}

void print(int A,int B)
{
    if(B)cout << A << ' ';
    else cout << "N ";
}

int main()
{
    vector<int>     v ;
    int             A1(0) ,B1(0),
                    A2(0) ,B2(0),
                    A3(0) ,B3(0),
                    A4(0) ,B4(0),
                    A5(0) ,B5(0);
    
    readLineInt( v );
    for(auto &a : v)
    {
        if( a % 10 == 0 )
        {
            A1 += a ;B1++;
        }
        if( a % 5 == 1)
        {
            A2 += nextFlag() * a ;B2++;

        }
        if( a % 5 == 2)
        {
            A3 += 1 ;B3++;
        }
        if( a % 5 == 3)
        {
            A4 += a ;B4++;
        }
        if( a % 5 == 4)
        {
            A5 = ( A5 > a ) ? A5 : a ;B5++;
        }
    }
    print(A1,B1);print(A2, B2);print(A3, B3);
    
    if(B4)printf("%0.1f ",double(A4)/B4);
    else cout << "N ";
    if(B5)cout << A5 ;
    else cout << "N";

    
    
    return 0;
}
/*
 the analysis website:
 http://wenku.baidu.com/link?url=HcVZ5gKObEaYADVvBzFPr4GPGWsx2xpfRBuIwGLmHbKSYSZ9Mj2zWwWGkthJSqQlWsrd4mWTev8rl0PfAufUfulcKS2k64PhHRJD0znHzV_
 
 */
#include <iostream>
using namespace std ;

int main()
{
    int D,P;
    cin >> D >> P;
    if(P==3)cout<< D-1 ;
    else cout << D-P/2-1;
    
    return 0;
}
//
//  mainx.cpp
//  cppprogram
//
//  Created by thomas on 15/11/27.
//  Copyright © 2015年 thomas. All rights reserved.
//

#include <iostream>
#include <string>
#include <list>
#include <utility>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    map<char,int> m;
    string line1,line2;
    cin>>line1>>line2;
    for(char i='0';i<='9';i++){
        m[i]=0;
    }
    for(char i='a';i<='z';i++){
        m[i]=0;
    }
    for(char i='A';i<='Z';i++){
        m[i]=0;
    }
    
    for(int i=0;i<line1.length();i++){
        m[line1[i]]+=1;
    }
    for(int i=0;i<line2.length();i++){
        m[line2[i]]-=1;
    }
    
    int needed=0;
    for(map<char,int>::iterator iter=m.begin();iter!=m.end();iter++){
        if(iter->second<0)needed-=iter->second;
    }
    if(needed!=0)cout<<"No "<<needed;
    else{
        cout<<"Yes "<<line1.length()-line2.length();
    }
    return 0;
}
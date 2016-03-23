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
    string s;
    cin>>s;
    int length=s.length();
    int col=(length+2)/3;
    int row=length+2-col*2;
    auto iter1=s.begin();auto iter2=s.end()-1;
    for(int i=0;i<col-1;i++){
        cout<<*iter1;
        for(int i=2;i<row;i++)cout<<" ";
        cout<<*iter2<<endl;
        iter1++;iter2--;
    }
    cout<<string(iter1,iter2+1);
    return 0;
}
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

using namespace std;


int main()
{
    double value;
    int exp;
    list<pair<double,int>> a,b,c;
    int count;
    cin>>count;
    for(int i=0;i<count;i++){
        cin>>exp>>value;
        a.emplace_back(value,exp);
    }
    cin>>count;
    for(int i=0;i<count;i++){
        cin>>exp>>value;
        b.emplace_back(value,exp);
    }
    auto iter1=a.begin();
    auto iter2=b.begin();
    
    while(1){
        if(iter1==a.end()&&iter2==b.end()){
            break;
        }
        else if(iter1==a.end()){
            c.splice(c.end(), b, iter2,b.end());
            break;
        }
        else if(iter2==b.end()){
            c.splice(c.end(), a, iter1,a.end());
            break;
        }
        if(iter1->second>iter2->second){
            c.push_back(*iter1);
            iter1++;
        }
        else if(iter1->second<iter2->second){
            c.push_back(*iter2);
            iter2++;
        }
        else{
            if(iter1->first+iter2->first==0);
            else{
                c.emplace_back(iter1->first+iter2->first,iter1->second);
            }
            iter1++;iter2++;
        }
    }
    cout<<c.size();
    for(auto &content:c){
        printf(" %d %.1f",content.second,content.first);
    }
    return 0;
}
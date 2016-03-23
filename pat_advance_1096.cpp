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

using namespace std;

//#define MAX 501
//
//int visit[MAX];
//int map[MAX];
//
//void Dfs(int vertex,int num){
//    visit[vertex]=1;
//    for(int i=0;i<num;i++){
//        if(graph[vertex][i]==1){
//            if(!visit[i]){
//                Dfs(i, num);
//            }
//        }
//    }
//}
//
//
//int main()
//{
//    
//}

#include <cstring>

void print(int i){
    if(i<10)cout<<i;
    else if(i>=10)printf("%c",'A'+i-10);
}

void printNum(int i){
    print(i/13%13);
    print(i%13);
}

int main(){
    int r,g,b;

    cin>>r>>g>>b;
    cout<<"#";
    printNum(r);
    printNum(g);
    printNum(b);
    return 0;
}
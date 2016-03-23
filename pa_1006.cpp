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
struct record{
    string id;
    int time;
};

int main(){
    int N;
    scanf("%d",&N);
    string maxId,minId;
    int min=3600*25,max=0;
    for(int i=0;i<N;i++){
        char name[100];
        int time1[3],time2[3];
        scanf("%s %d:%d:%d %d:%d:%d",name,&time1[0],&time1[1],&time1[2],&time2[0],&time2[1],&time2[2]);
//        for(int i=0;i<3;i++){
//            cout<<time1[i]<<" "<<time2[i]<<endl;
//        }
        int t1=time1[0]*3600+time1[1]*60+time1[2];
        int t2=time2[0]*3600+time2[1]*60+time2[2];
        if(t2>max){
            max=t2;maxId=name;
        }
        if(t1<min){
            min=t1;minId=name;
        }
    }
    cout<<minId<<" "<<maxId;
}
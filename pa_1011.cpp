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
double mul(double x,double y){
    double result=x*y;
    double decimal;
    char out[100];
    sprintf(out, "%.2f",result);
    sscanf(out, "%lf", &decimal);
    if(result-decimal>0.005){
        decimal+=0.01;
    }
    return decimal;
}
int main(void){
    double input[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>input[i][j];
        }
    }
    double result=1;
    for(int i=0;i<3;i++){
        auto iter=std::max_element(begin(input[i]), begin(input[i])+3);
        switch (iter-begin(input[i])) {
            case 0:
                cout<<"W ";
                break;
            case 1:
                cout<<"T ";
                break;
            case 2:
                cout<<"L ";
                break;
            default:
                break;
        }
        result=mul(result,*iter);
    }
    
    printf("%.2f",(mul(result,0.65)-1)*2);
    return 0;
}
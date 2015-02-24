/*
 * first.cpp
 *
 *  Created on: 2015年2月5日
 *      Author: thomas
 */

#include <iostream>
#include <string>
using namespace std;

class check{
public:
    check(string s):checkstring(s){}
    check()=default;
    bool firstRule(const string& s);
    bool secondRule(const string& s);
    void assignment(string s){checkstring=s;}
private:
    string checkstring;
};

bool check::firstRule(const string& s){
    for(auto i:s){
        if(i!='P'&&i!='A'&&i!='T')
            return false;
    }
    return true;
}

bool check::secondRule(const string& s){
    auto i=s.begin();
    auto j=s.end()-1;
    while(*i!='P'){
        if(*i!='A'||i==s.end()-1)return false;
        ++i;
    }
    while(*j!='T'){
        if(*j!='A'||j==s.begin())return false;
        --j;
    }
    auto firstA=i-s.begin();
    auto lastA=s.end()-j-1;
    auto middleA=j-i-1;
    if(lastA==middleA*firstA&&middleA!=0)return true;
    else return false;
    
}


int main(){
    int i;
    cin>>i;
    check c;
    string s;
    for(int j=0;j<i;j++){
        cin>>s;
        c.assignment(s);
        if(!c.firstRule(s))cout<<"NO"<<endl;
        else if(!c.secondRule(s))cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}



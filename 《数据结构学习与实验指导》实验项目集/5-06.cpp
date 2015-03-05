/*
 5-06. 航空公司VIP客户查询（25）
 Two of the testcases are passed because the RAM is over limit.
 */

#include <iostream>
#include <map>
#include <string>
using namespace std;


int main(void)
{
    map<string,int> accountData;
    
    int N,K;
    cin >> N >> K;
    string idNumber;
    int miles;
	
    
    for(int i=0;i < N;i++)
    {
        cin >> idNumber >> miles;
        
        miles =(miles<500)?500:miles;
        auto ret = accountData.insert({idNumber,miles});
        if(!ret.second)
            ret.first->second += miles;
    }
    
    int M;
    cin>>M;
    
    for(int i = 0;i < M;i++)
    {
        cin >> idNumber;
        auto ret = accountData.find(idNumber);
        if(ret==accountData.end())
            cout << "No Info" <<endl;
        else cout << ret->second << endl;
    }
    
    return 0;
}
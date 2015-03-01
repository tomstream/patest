/*5-05. QQ帐户的申请与登陆（25）
 */

#include <iostream>
#include <map>
#include <string>
using namespace std;


int main(void)
{
    map<long int,string> accountData;
    
    int N;
    cin >> N;
    char choice;long int qqCount;string keyWord;
    
    for(int i = 0; i < N;i++)
    {
        cin >> choice>>qqCount>>keyWord;
        switch (choice) {
            case 'L':
            {
                if(accountData.find(qqCount)==accountData.end())
                    cout<<"ERROR: Not Exist"<<endl;
                else if(accountData.find(qqCount)->second==keyWord)
                    cout<<"Login: OK"<<endl;
                else cout<<"ERROR: Wrong PW"<<endl;
                break;
            }
            case 'N':
            {
                auto ret = accountData.insert({qqCount,keyWord});
                if(!ret.second)
                    cout<<"ERROR: Exist"<<endl;
                else cout<<"New: OK"<<endl;
                break;
            }
            default:break;
        }
    }
    return 0;
}
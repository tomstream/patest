#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int> &a){
    if(a.size()<=1)return;
    int temp;
    for(auto p=a.begin();p!=a.end()-1;p++){
        for(auto q=p;q!=a.end()-1;q++){
            if(*q<*(q+1)){
                temp=*q;
                *q=*(q+1);
                *(q+1)=temp;
            };
        }
    }
}
int main(){
    int a[101]{0};
    vector<int> checkedNumber;
    vector<int> numberToBeChecked;
    int K,n;

    cin>>K;
    
    for(int i=0;i<K;i++){
        cin>>n;
        numberToBeChecked.push_back(n);
        while(n!=1){
            if(n%2)n=(3*n+1)/2;
            else n/=2;
            a[n]=1;
        }
    }
    for(auto i:numberToBeChecked){
        if(!a[i])checkedNumber.push_back(i);
    }
    sort(checkedNumber);
    
    for(auto &i:checkedNumber){
        cout<<i;
        if(i!=*(checkedNumber.end()-1))cout<<" ";
    }
    
    return 0;
}
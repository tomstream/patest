/*7-07. PAT排名汇总（25）*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

struct testScore
{
    int classNumber;
    long int id;
    int score;
    int privateRank;
    int publicRank;
};

bool isHigher(const testScore &a,const testScore &b)
{
    if(a.score == b.score)return a.id < b.id;
    else return a.score > b.score;
}

void privateRank(vector<testScore>::iterator beg,vector<testScore>::iterator end)
{
    int rank(1);
    beg->privateRank = rank;
    ++beg;
    while(beg!=end)
    {
        ++rank;
        if(beg->score == (beg-1)->score)beg->privateRank=(beg-1)->privateRank;
        else beg->privateRank = rank;
        ++beg;
    }
}

void publicRank(vector<testScore>::iterator beg,vector<testScore>::iterator end)
{
    int rank(1);
    beg->publicRank = rank;
    ++beg;
    while(beg!=end)
    {
        ++rank;
        if(beg->score == (beg-1)->score)beg->publicRank=(beg-1)->publicRank;
        else beg->publicRank = rank;
        ++beg;
    }
}

int main(void)
{
    size_t N;
    cin >> N;
    vector<testScore> t;
    size_t K;
    size_t lastSize;
    
    for (int i = 0;i < N;i ++)
    {
        cin >> K;
        lastSize=t.size();
        t.resize(lastSize+K);
        for(int j = 0;j < K;j ++)
        {
            cin >> t[lastSize+j].id >> t[lastSize+j].score;
            t[lastSize+j].classNumber=i+1;
        }
        sort(t.begin()+lastSize,t.end(),isHigher);
        privateRank(t.begin()+lastSize, t.end());
    }
    sort(t.begin(),t.end(),isHigher);
    publicRank(t.begin(), t.end());
    
    cout<<t.size()<<endl;
    for(auto &i:t){
        cout << i.id << ' ' << i.publicRank << ' ' << i.classNumber << ' ' << i.privateRank << endl;
    }
    
    return 0;
}
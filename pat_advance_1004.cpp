#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;

struct pedigree
{
    pedigree();
    map<int, set<int>> idStorage;
    vector<int> numOfSum;
    void childNum(const int&,int herachy);
};

void pedigree::childNum(const int& ID,int herachy)
{
    if (numOfSum.size() <= herachy)
    {
        numOfSum.push_back(0);
    }
    if (idStorage.find(ID) == idStorage.end())
    {
        ++numOfSum[herachy];
    }
    else
    {
        for (int item : idStorage[ID])
        {
            childNum(item, herachy + 1);
        }
    }
}

pedigree::pedigree()
{
    int nodeNum,nonleafNodeNum;
    int ID, SubID,SubNodeNum;
    cin >> nodeNum >> nonleafNodeNum;
    for (int i = 0; i < nonleafNodeNum; i++)
    {
        cin >> ID;
        cin >> SubNodeNum;
        for (int j = 0; j < SubNodeNum; j++)
        {
            cin >> SubID;
            idStorage[ID].insert(SubID);
        }
    }
}

int main()
{
    pedigree pd;
    pd.childNum(1,0);
    int size = pd.numOfSum.size();
    for (int i = 0; i < size; i++)
    {
        cout << pd.numOfSum[i];
        if (i != size - 1)cout << " ";
    }
    return 0;
}
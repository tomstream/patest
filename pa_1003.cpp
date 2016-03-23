#include <iostream>
#include <string>
using namespace std;

const int N = 500;
const int INF = 100000000;

int graph[N][N];

bool isVisited[N];

int teamNum[N];

int dis[N];

int path_num=0;

int maxTeamNum=0;

void initData(){
    int i,j;
    for(i=0;i<N;i++){
        isVisited[i]=false;
        teamNum[i]=0;
        dis[i]=INF;
        for(j=0;j<N;j++){
            graph[i][j]=INF;
        }
    }
}


void Dijstra(int n, int src, int des){
    dis[src]=0;
    for(int i=0;i<n;i++){
        dis[i]=graph[src][i];
        
    }dis[src]=0;
    isVisited[src]=true;
    for(int i=0;i<n;i++){
        int minDis=INF;
        int cur;
        for(int j=0;j<n;j++){
            if(!isVisited[j]&&dis[j]<minDis){
                minDis=dis[j];
                cur=j;
            }
        }
        
        if(minDis==INF)return;
        isVisited[cur]=true;
        for(int j=0;j<n;j++){
            if(j!=i&&graph[cur][j]<INF&&graph[cur][j]+dis[cur]<dis[j]){
                if(j==0){
                   cout<<"1"<<endl;
                    int m;
                    cout<<m;
                }
                    dis[j]=graph[cur][j]+dis[cur];
            }
        }
    }
}

void dfs(int n, int cId, int des, int curDis, int curTeamsNum){
    isVisited[cId]=true;
    
    if(cId==des){
        if(curDis==dis[des])
        {
            path_num++;
            if(curTeamsNum>maxTeamNum){
                maxTeamNum=curTeamsNum;
            }
        }
        return;
    }
    if(curDis>dis[des])return;
    for(int i=0;i<n;i++){
        if(dis[cId]+graph[cId][i]==dis[i]){
            dfs(n, i, des, curDis+graph[cId][i], curTeamsNum+teamNum[i]);
        }
    }
}
int main(){
    int n,M,C1,C2;
    initData();
    cin>>n>>M>>C1>>C2;
    for(int i=0;i<n;i++){
        cin>>teamNum[i];
    }
    for(int i=0;i<M;i++){
        int src,dst,len;
        cin>>src>>dst>>len;
        graph[dst][src]=graph[src][dst]=len;
    }
    Dijstra(n, C1, C2);
    dfs(n, C1, C2, 0, teamNum[C1]);
    cout<<path_num<<" "<<maxTeamNum;
}
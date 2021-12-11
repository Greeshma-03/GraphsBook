#include<bits/stdc++.h>
using namespace std;

#define INFI 1e9

//adjacency matrix
vector<vector<int>>vec(1);
vector<vector<int>>rvec(1);
int n,e;

int BFS(int start,int destination,vector<int>&parent){
    vector<int>visited(n+1,0);//intially all nodes arenot visited
    queue<int>que;

    que.push(start);
    visited[start]=1;
    parent[start]=-1;
    while(!que.empty()){
        int elem=que.front();
        que.pop();

        for(int i=1;i<=n;i++){
            int it=rvec[elem][i];
            if(visited[i]==0 && it>0){
                parent[i]=elem;
                if(i==destination){//if we got to the final destination node
                    return 1;
                }                
                que.push(i);
                visited[i]=1;
            }
        }
    }

    return 0;
}

int Ford_Fulkerson(int s,int t){
    int max_flow=0;
    vector<int>parent(n+1,-1);//to store the path
    while(BFS(s,t,parent)){
        int path_flow=INFI;
        int v=t;
        while(v!=s){
            int u=parent[v];
            path_flow=min(path_flow,rvec[u][v]);           
            v=u;
        }

        v=t;
        //updating the values each time
        while(v!=s){
            int u=parent[v];
            rvec[u][v]-=path_flow;
            rvec[v][u]+=path_flow;
            v=u;
        }

        max_flow+=path_flow;
    }
    return max_flow;
}

void DFS(int start, vector<int> &visited)
{
    visited[start] = 1;
    cout<<start<<" ";
    
    for(int i=1;i<=n;i++)
    {
        int it=rvec[start][i];
        if (it>0 && visited[i]==0)
        {
            DFS(i, visited);
        }
    }
    return;
}

int main(){
    int s,t;//source and destination
    cin>>n>>e>>s>>t;
    vec.resize(n+1,vector<int>(n+1,0));
    rvec.resize(n+1,vector<int>(n+1,0));

    for(int i=1;i<=e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        vec[u][v]=wt;
        rvec[u][v]=wt;
    }

    cout<<Ford_Fulkerson(s,t)<<endl;
    vector<int>visited(n+1,0);
    
    //min-cut in the graph 
    DFS(s,visited);
    cout<<endl;
    
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cout<<i<<" ";
        }        
    }
    cout<<endl;

    return 0;
}

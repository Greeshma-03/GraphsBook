#include<bits/stdc++.h>
using namespace std;

//****************GRAPH***********************************
//********************************************************

int n,e;                        //vertices and edges
vector<vector<int>> vec(1);     //adjacency list for graphs
vector<int>bfs;                 //Order of BFS on some node

//*********************************************************
//*********************************************************

void BFS(int start){  
    vector<int>visited(n+2,0);
    queue<int>que;

    que.push(start);
    visited[start]=1;

    while(!que.empty()){
        int elem=que.front();
        que.pop();
        bfs.push_back(elem);

        for(auto it:vec[elem]){
            if(!visited[it]){
                que.push(it);
                visited[it]=1;
            }
        }
    }
    return;
}

int main(){
    int flag=1;//change flag to 0 for directed graph
    cin>>n>>e;
    int start;
    cin>>start;
    
    vec.resize(n+2);
    
    int u,v;
    for(int i=1;i<=e;i++){
        cin>>u>>v;
       vec[u].push_back(v);
       if(flag)
       vec[v].push_back(u);     
    }
    
    BFS(start);
    
    for(auto it:bfs){
        cout<<it<<" ";
    }
    cout<<endl;


    return 0;
}
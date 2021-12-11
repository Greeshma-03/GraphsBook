#include<bits/stdc++.h>
using namespace std;

int n,e;
vector<vector<int>>vec(1);//adjacency list
vector<int>Dfs;//this vector conatins elements in DFS Order


void DFS(int start){

    vector<int>visited(n+2,0);  //No nodes are initially visited
    stack<int>s;
    s.push(start);
    Dfs.push_back(start);

    visited[start]=1;
    int pop=1;

    while(!s.empty()){
        pop=1;
        int elem=s.top();
        for(auto it:vec[elem]){
            if(visited[it]==0){
                pop=0;
                Dfs.push_back(it);
                s.push(it);
                visited[it]=1;
                break;          
            }
        }
        
        if(pop){
            s.pop();
        }     

        // PrintStack(s);
    }
    return;
}

int main(){
    int flag=1;//change flag to 0 for directed graph
    
    cin>>n>>e;
    int u,v,start;
    cin>>start;
    vec.resize(n+2); //allocating n+2 adjacent lists
    for(int i=1;i<=e;i++){
       cin>>u>>v;
       vec[u].push_back(v);
       if(flag)
       vec[v].push_back(u);
    }

    
    
    DFS(start);
    
    for(auto it:Dfs){
        cout<<it<<" ";
    }
    cout<<endl;

    return 0;
}
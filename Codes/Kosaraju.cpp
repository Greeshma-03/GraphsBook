#include<bits/stdc++.h>
using namespace std;

//adjacency list
vector<vector<int>>vec(1);
vector<vector<int>>scc;
vector<vector<int>>rev_graph(1);
int n,e;


void DFS(int i,vector<int> &visited,stack<int>&s){
    visited[i]=1;
    for(auto it:vec[i]){
        if(!visited[it]) 
        DFS(it,visited,s);
    }
    s.push(i);
    return;
}

void DFS2(int i,vector<int>&visited,vector<int>&use){
    visited[i]=1;
    use.push_back(i);
    for(auto it:rev_graph[i]){
        if(!visited[it])
        DFS2(it,visited,use);
    }
    return;
}

void reverse_graph(){
    for(int i=1;i<=n;i++){
        for(auto it:vec[i]){
            rev_graph[it].push_back(i);
        }
    }
    return;
}

void Kosaraju(){
    
    //step-1:perform DFS and push to stack accordingly
    vector<int>visited(n+1,0);
    stack<int>s;
    for(int i=1;i<=n;i++){
        if(!visited[i])
        DFS(i,visited,s);
    }

    for(int i=1;i<=n;i++)
    visited[i]=0;

    //step-2:reverse the graph
    reverse_graph();

    //step-3:perform DFS and seperate out the SCC
    while(!s.empty()){
        int top=s.top();
        if(!visited[top]){
            vector<int>use;
            DFS2(top,visited,use);
            scc.push_back(use);
        }
        s.pop();
    }
    
    for(auto it:scc){
        for(auto it2:it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
    
    return;
}


int main(){
    cin>>n>>e;
    int flag=0;//directed graph
    vec.resize(n+1);
    rev_graph.resize(n+1);

    for(int i=1;i<=e;i++){
        int u,v;
        cin>>u>>v;
        vec[u].push_back(v);
        if(flag)
        vec[v].push_back(u);
    }
    Kosaraju();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

//Given input n=number of nodes and e=number of edges
//and the edges list (u,v) indicating an directed edge from vertex u to v //1 indexing

void DFS(int i,vector<vector<int>> &vec,stack<int> &s,vector<int> &visited){ //Note we are passing '&' so changes do reflect
   visited[i]=1;          
   for(auto it:vec[i]){//traversing all edges directed to that vertex
        if(!visited[it]){
           DFS(it,vec,s,visited);
        }
   }

    s.push(i);
    return;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>Adj_list;
    
    for(int i=0;i<=n;i++){
       vector<int> vec={};
       Adj_list.push_back(vec);
    }

    int e;
    cin>>e;
    int u,v;
    for(int i=1;i<=e;i++){
      cin>>u>>v;
      Adj_list[u].push_back(v);
    }
    
    stack<int> Stack;
    vector<int>visited(n+1,0);

    for(int i=1;i<=n;i++){ //traversing each of the edge
       if(!visited[i]){
           DFS(i,Adj_list,Stack,visited);           
       }
    }
    
    //we assumed 1-indexing
    while(!Stack.empty()){
        cout<<Stack.top()<<" ";
        Stack.pop();
    }
    
    cout<<endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int n,e;
vector<vector<int>> vec(1);//adjacency lsit
vector<int>visited(1);


int DFS(int node,int parent){
    visited[node]=1;
    for(auto it:vec[node]){
        
        if(it==node)
        return 1;

        if(!visited[it]){
            if(DFS(it,node))
            return 1;
        }
        else if(it!=parent && parent!=-1)
        return 1;
    }
    return 0;
}

int DFS_all(){
    for(int i=1;i<=n;i++){
        if(!visited[i]){
        if(DFS(i,-1))//node i having no parent
        return 1;
        }
    }

    return 0;

}

int main(){
    cin>>n>>e;
    int u,v,start;
    vec.resize(n+2); //allocating n+2 adjacent lists
    visited.resize(n+2,0); //initially all nodes aren't visited
    for(int i=1;i<=e;i++){
       cin>>u>>v;
       vec[u].push_back(v); 
       vec[v].push_back(u);
    }
    
    int Is_cyclic=DFS_all();
    cout<<Is_cyclic<<endl;
    return 0;
}
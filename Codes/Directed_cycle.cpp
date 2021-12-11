#include<bits/stdc++.h>
using namespace std;

//implemented using DFS

int n,e;
vector<vector<int>> vec(1);//adjacency lsit
vector<int>color(1);

//-1 indicates not yet explored
//0 indicates in the stage of exploring but not yet completed
//1 indicates explored

int DFS_color(int node){
    color[node]=0;//in progress
    for(auto it:vec[node]){//traversing nodes in adjacency list
       if(color[it]==-1){
           if(DFS_color(it)){
           return 1;
           }
       }
       else if(color[it]==0) //you again reached a node in process 
       return 1;
    }
    return 0;
}


int DFS_all(){
   for(int i=1;i<=n;i++){
       if(color[i]==-1){
       if(DFS_color(i)==1)
       return 1;
       }
   }
   return 0;
}

int main(){
    cin>>n>>e;
    int u,v,start;
    vec.resize(n+2); //allocating n+2 adjacent lists
    color.resize(n+2,-1); //initially all nodes aren't visited
    for(int i=1;i<=e;i++){
       cin>>u>>v;
       vec[u].push_back(v);       
    }
    
    int Is_cyclic=DFS_all();
    cout<<Is_cyclic<<endl;
    

    return 0;
}
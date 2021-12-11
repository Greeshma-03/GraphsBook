#include<bits/stdc++.h>
using namespace std;

#define INFI 1e9
typedef pair<int,int> pii;

int n,e;
vector<vector<pair<int,int>>> vec;//adjacency list

void Dijkshtra(int source){
    set<pii> pq; //first element refers to the node weight and second element is the node    
    vector<pii>processed(n+1,{0,-1});//first element refers to state of processing and second element is parent 
    vector<int>node_wts(n+1,INFI);//array to know the weight of node 
    
    node_wts[source]=0;
    pq.insert({0,source});

    while(!pq.empty()){
        pii top=*pq.begin();
        int top_node=top.second;
        int top_node_wt=top.first;

        pq.erase(pq.begin());
        processed[top_node].first=1;

        for(auto it:vec[top_node]){
            int node=it.first;
            int wt=it.second;
            if(processed[node].first==1)//if there is a self loop
            continue;
            else{
                if(node_wts[node]>top_node_wt+wt){    

                    if(node_wts[node]!=INFI)//if element is present remove it inorder to update
                      pq.erase(pq.find({node_wts[node],node}));
                    node_wts[node]=top_node_wt+wt;
                    pq.insert({node_wts[node],node});
                    processed[node].second=top_node;//Top node has updated it                                           
                }
            }
        }
    }

    for(int i=1;i<=n;i++){

        cout<<node_wts[i]<<" ";
        //comment out the below code if u wanna know shortest path sequencefrom source to given node
        //----------------------------------
        // vector<int>path;
        // int dest=i;
        // while(dest!=-1){
        //     path.push_back(dest);
        //     dest=processed[dest].second;
        // }
        // reverse(path.begin(),path.end());

        // for(auto it:path){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        //-----------------------------------
    }
    cout<<endl;
    return;
}


int main(){
    int flag=1;//change flag to 0 for a directed graph
    // int source;//source node to find shortest paths to..
    cin>>n>>e;
    vec.resize(n+1);

    for(int i=1;i<=e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        vec[u].push_back({v,wt});
        if(flag==1)//undirected graph
        vec[v].push_back({u,wt});
    }
    for(int source=1;source<=n;source++)
    Dijkshtra(source);

    return 0;
}
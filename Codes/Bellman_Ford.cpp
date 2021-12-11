#include<bits/stdc++.h>
using namespace std;

#define INFI 1e9
typedef pair<int,int> pii;

int n,e;

void Bellman_Ford(int source,vector<vector<int>> &vec){

    vector<pii>node(n+1,{INFI,-1});//initilaise all node_weights to Infinity and parents as -1
    node[source].first=0;

    int count=1;
    while(count<=n){
    int changed=0;
    for(auto it:vec){
        int u=it[0],v=it[1],wt=it[2];

        if(v==source)//don't update for the source node
        continue;

        if(node[v].first>node[u].first+wt){
            node[v].first=node[u].first+wt;
            node[v].second=u;//updating the parent
            changed=1;
        }
    }
    if(!changed)
    break;
    count++;
    }
    
    if(count==n+1){
        cout<<"-1"<<endl; //detected negative edge cycle
    }

    for(int i=1;i<=n;i++){
        cout<<node[i].first<<" ";
        // comment out to get shortesr path from source to destination
        // ------------------------------
        // int dest=i;
        // vector<int>path;
        // while(dest!=-1){
        //     path.push_back(dest);
        //     dest=node[dest].second;//going to parent
        // }
        // reverse(path.begin(),path.end());

        // for(auto it:path){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // ------------------------------        
    }
    cout<<endl;
    return;
}

int main(){
    int source;//source node to find shortest paths to..
    cin>>n>>e>>source;

    //Edge list Representation
    int flag=1;//change flag to 0 for a directed graph
    
    vector<vector<int>>vec(e);
    if(flag)
    vec.resize(2*e);
    int count=0;
    for(int i=1;i<=e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        vec[count].push_back(u);
        vec[count].push_back(v);
        vec[count].push_back(w);
        if(flag){
            count++;
            vec[count].push_back(v);
            vec[count].push_back(u);
            vec[count].push_back(w);
        }
        count++;
    }

    Bellman_Ford(source,vec);
    return 0;
}
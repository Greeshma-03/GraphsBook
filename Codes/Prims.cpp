#include<bits/stdc++.h>
using namespace std;

#define INFI 1e9
typedef pair<int,int> pii;


int n, e;                   //vertices and edges
vector<vector<pii>> vec(1); //adjacency list for graphs

int Prims(){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    //used to get the nodes to add at each step
    //each element has key value and it's vertex number i.e pair=key,vertex
    //pq sorted in ascending order w.r.t key

    int wt=0,maxi=0;
    pq.push({0,1});
    vector<int>mst(n+1,0);
    vector<int>key(n+1,INFI);
    key[1]=0;

    while(maxi!=n){//till all nodes are present in mst
        pii top=pq.top();
        if(mst[top.second]==1)//removing the excess elements in th heap
        {
        pq.pop();
        continue;
        }
        pq.pop();        
        wt+=top.first;
        maxi++;
        mst[top.second]=1;//include that vertex in MST

        //relaxing the edges of the nodes present in MST and pushing them to heap
        for(auto it:vec[top.second]){
            int node=it.first;
            int wt=it.second;

            if(mst[node]==0 && key[node]>wt){
                key[node]=wt;
                pq.push({wt,node});
            }
        }
    }
    return wt;
}

int main(){
    //using adjacency list
    cin>>n>>e;
    vec.resize(n+1);

    int u,v,w;
    for (int i = 1; i <= e; i++)
    {
        cin >> u >> v>>w;
        vec[u].push_back({v,w});
        vec[v].push_back({u,w});
    }
    cout<<Prims()<<endl;

    return 0;
}
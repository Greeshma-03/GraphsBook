#include<bits/stdc++.h>
#define long long ll
using namespace std;

int n,e;

bool my_sort(const vector<int>&vec1,const vector<int>&vec2){
    return vec1[2]<vec2[2];
}

int find(int node,vector<pair<int,int>> &vec){
    while(vec[node].first!=-1){
        node=vec[node].first;
    }
    return node;
}


void Union(int x,int y,vector<pair<int,int>> &vec){//union two sets containing x and y respectively
    int ap1=find(x,vec);
    int ap2=find(y,vec);
    if(ap1==ap2)
    return;
    if(vec[ap1].second<vec[ap2].second)//if tree2 has more rank
    {
    vec[ap1].first=ap2;//making absolute parent 1 point to absolute parent 2
    vec[ap2].second++;//increasing rank 
    }
    else{
    vec[ap2].first=ap1;//making absolute parent 1 point to absolute parent 2
    vec[ap1].second++;
    }
    
    return;
}

int MST(vector<vector<int>> &vec){
    int wt=0,maxi=0;

    vector<pair<int,int>>DS(n+1,{-1,0});
    for(auto it:vec){
        if(maxi==n-1)
        break;
        int ap1=find(it[0],DS);
        int ap2=find(it[1],DS);

        if(ap1!=ap2){//add edge only if doesn't form a cycle
            Union(ap1,ap2,DS);
            wt+=it[2];
            maxi++;
        }
    }
    return wt;
}


int main(){
    //Edge list representation
    cin>>n>>e;
    vector<vector<int>>vec(e);
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        vec[i].push_back(u);
        vec[i].push_back(v);
        vec[i].push_back(w);        
    }

    sort(vec.begin(),vec.end(),my_sort);

    
    cout<<MST(vec)<<endl;
    return 0;
}
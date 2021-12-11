#include<bits/stdc++.h>
using namespace std;

//adjacency list
vector<vector<int>>vec(1);
int n,e;

int ToLeaf(int x,vector<int>&node,int parent){    
    if(node[x]!=-1)//value is already computed
    return node[x];
    
    for(auto it:vec[x]){
    if(it==parent)
    continue;
    node[x]=max(node[x],ToLeaf(it,node,x));
    }
    node[x]++;
    return node[x];
}


int main(){
    cin>>n>>e;
    vec.resize(n+1);
    int flag=1;//undirected graph
    if(e>n-1)//not a tree
    return 0;
    for(int i=1;i<=e;i++){
        int u,v;
        cin>>u>>v;
        vec[u].push_back(v);
        if(flag)
        vec[v].push_back(u);
    }
    vector<int>node(n+1,-1);//ToLeaf and MaxLength values 
    
    int diameter,start;
    
    for(int i=1;i<=n;i++){
        if(vec[i].size()>=2){
            start=i;
            break;
        }        
    }    

    vector<int>use;
    for(auto it:vec[start])
    use.push_back(ToLeaf(it,node,start));

    sort(use.begin(),use.end());
    reverse(use.begin(),use.end());
    
    if((vec[start].size())==1)
    {    
    diameter=use[0];        
    diameter++;
    }
    else if((vec[start].size())>=2){
    diameter=use[0]+use[1];        
    diameter+=2;
    }

    cout<<diameter<<endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

//adjacency list
vector<vector<int>>vec(1);
vector<vector<int>>scc;
int n,e,timer=0;

void DFS(int i,stack<int> &s,vector<vector<int>> &info){
    info[i][0]=timer;
    info[i][1]=timer;
    info[i][2]=1;
    timer++;
    s.push(i);

    for(auto it:vec[i]){
        if(info[it][0]==-1){//element not yet discovered
           DFS(it,s,info);
           info[i][1]=min(info[it][1],info[i][1]);
        }

        else if(info[it][2]==1){ //for back edge
            info[i][1]=min(info[it][0],info[it][1]);
        }
        //we ignore cross edge processing
    }

    if(info[i][0]==info[i][1]){//head node
        vector<int>use;
        use.push_back(i);
        while(s.top()!=i){
            int top=s.top();
            use.push_back(top);
            info[top][2]=0;//popped out from stack
            s.pop();
        }
        info[i][2]=0;
        s.pop();
        scc.push_back(use);
    }    

    return;
}

void Tarjan(){
    vector<vector<int>>info(n+1,{-1,-1,0});//stores disc time,low time,Is_in_stack
    stack<int>s;//to store elemnts in dfs traversal

    for(int i=1;i<=n;i++){
        if(info[i][0]==-1)
        DFS(i,s,info);
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

    for(int i=1;i<=e;i++){
        int u,v;
        cin>>u>>v;
        vec[u].push_back(v);
        if(flag)
        vec[v].push_back(u);
    }
    Tarjan();
    return 0;
}
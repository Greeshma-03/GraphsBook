#include<bits/stdc++.h>
using namespace std;

#define INFI 1e9


//adjacency list represntation
int n,e;

void Floyd_Warshall(vector<vector<int>> &dp){
    for(int i=1;i<=n;i++){//including each node as an intermediate node
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(j==i || k==i)//no difference upon including that node itself
                continue;

                dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);//update accordingly
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return;
}

int main(){
    int flag=1;//undirected graph
    cin>>n>>e;
    vector<vector<int>> dp;

    dp.resize(n+1,vector<int>(n+1,INFI));//resizing 2d vector
    //creating n+1 elements where each element is vector of n+1 integers of value INFI

    for(int i=1;i<=n;i++){
        dp[i][i]=0;//no self loops
    }
     
    for(int i=1;i<=e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        dp[u][v]=wt;
        if(flag)
        dp[v][u]=wt;
    }

    Floyd_Warshall(dp);

    return 0;
}
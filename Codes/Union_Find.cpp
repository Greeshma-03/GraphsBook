#include<bits/stdc++.h>
using namespace std;


int find(int node,vector<int> &parent){
    if(parent[node]==-1)
    return node;
    else
    return find(node,parent);
}

void Union(int x,int y,vector<int> &parent){//union two sets containing x and y respectively
    int ap1=find(x,parent);
    int ap2=find(y,parent);
    if(ap1==ap2)
    return;
    
    parent[ap1]=ap2;//making absolute parent 1 point to absolute parent 2
    return;
}

int main(){
    int n;//number of nodes
    cin>>n;
    vector<int>parent(n+1,-1); //initialising all parents to -1
    
    while(1){
        cout<<"Enter any operation:\n1.Find\n2.Union\n3.List\n";

        int op;
        cin>>op;

        if(op==1){
            int x;
            cin>>x;
            cout<<"Absolute Parent: "<<find(x,parent)<<endl;;
        }
        else if(op==2){
            int x,y;
            cin>>x>>y;
            Union(x,y,parent);
            cout<<"Done!!\n";
        }
        else if(op==3){
            for(int i=1;i<=n;i++){
                cout<<parent[i]<<" ";
            }
            cout<<endl;
        }
        else{
            break;
        }
    }

    return 0;
}
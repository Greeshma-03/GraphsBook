#include<bits/stdc++.h>
using namespace std;

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


int main(){
    int n;//number of nodes
    cin>>n;
    vector<pair<int,int>> vec(n+1,{-1,0}); //stores information about the parent/AP and rank
    
    while(1){
        cout<<"Enter any operation:\n1.Find\n2.Union\n3.List\n";

        int op;
        cin>>op;

        if(op==1){
            int x;
            cin>>x;
            cout<<"Absolute Parent: "<<find(x,vec)<<endl;;
        }
        else if(op==2){
            int x,y;
            cin>>x>>y;
            Union(x,y,vec);
            cout<<"Done!!\n";
        }
        else if(op==3){
            for(int i=1;i<=n;i++){
                cout<<vec[i].first<<" ";
            }
            cout<<endl;
        }
        else{
            break;
        }
    }

    return 0;
}
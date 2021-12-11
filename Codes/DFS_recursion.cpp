#include <bits/stdc++.h>
using namespace std;

//****************GRAPH***********************************
//********************************************************

int n, e;                   //vertices and edges
vector<vector<int>> vec(1); //adjacency list for graphs
vector<int> dfs;            //Order of DFS on some node

//*********************************************************
//*********************************************************

void DFS(int start, vector<int> &visited)
{
    visited[start] = 1;
    dfs.push_back(start);
    for (auto it : vec[start])
    {
        if (!visited[it])
        {
            DFS(it, visited);
        }
    }
    return;
}

int main()
{
    int flag = 1; //change flag to 0 for directed graph
    cin >> n >> e;
    int start;
    cin >> start;

    vec.resize(n + 2);

    int u, v;
    for (int i = 1; i <= e; i++)
    {
        cin >> u >> v;
        vec[u].push_back(v);
        if (flag)
            vec[v].push_back(u);
    }
    vector<int> visited(n + 1, 0);

    DFS(start, visited);
    for (auto it : dfs)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int number=1e3+5;

vector<vector<int>>graph(number);
 bool visited[number];

void dfs(int v)
{
    visited[v]=true;
    cout<<v;

    for(auto i=graph[v].begin();i!=graph[v].end();i++)
    {
        if(!visited[*i])
            dfs(*i);
    }

    return;

}

int main()
{



    int num_vertices,num_edges;
    cin>>num_vertices>>num_edges;

    for(int i=0;i<num_edges;i++)
    {
        int n,m;

        cin>>n>>m;

        graph[n].push_back(m);
        graph[m].push_back(n);
    }



    int src;

    cout<<"Enter source:"<<endl;
    cin>>src;
      dfs(src);

    return 0;
}

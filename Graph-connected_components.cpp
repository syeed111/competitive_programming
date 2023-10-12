#include<bits/stdc++.h>
using namespace std;

const int N=1e3+5;
vector<int>graph[N];
bool visited[N];


vector<int>current_vertex;
vector<vector<int>>vector_of_cv;


void dfs(int vertex)
{
    visited[vertex]=true;
    current_vertex.push_back(vertex);
    // cout<<vertex<<" ";

        for(auto i=graph[vertex].begin(); i!=graph[vertex].end(); i++)
    {
        if(visited[*i]) continue;
        dfs(*i);
    }
    return ;
}

int main()
{
    int v,e;
    cin>>v>>e;
    for(int i=0; i<e; i++)
    {
        int n,m;
        cin>>n>>m;

        graph[n].push_back(m);
        graph[m].push_back(n);

    }
   /* dfs
    int src;
    cout<<"Enter src node:\n";
    cin>>src;
    cout<<"The nodes are:";
    dfs(src);
    cout<<" "<<endl;
    */

    for(int i=1;i<=v;i++)
    {
        current_vertex.clear();
        if(!visited[i])
        {
            dfs(i);
            vector_of_cv.push_back(current_vertex);
        }
    }

    cout<<"Number of connected components:"<<vector_of_cv.size()<<endl;
    cout<<"The connected components are:\n";
    for(auto it: vector_of_cv)
   {

       for(int ij: it)
    {
        cout<<ij<<" ";
    }
    cout<<endl;
   }

    return 0;
}

/* connected
4 5
0 1
0 2
1 2
2 3
3 3
*/



/* disconnected
8 5
1 2
2 3
2 4
3 5
6 7

*/

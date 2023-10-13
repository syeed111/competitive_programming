#include<bits/stdc++.h>
using namespace std;

const int N=1e3+5;
vector<int>graph[N];
bool visited[N];


vector<int>current_vertex;
vector<vector<int>>vector_of_cv;


bool dfs(int vertex,int par)
{


    visited[vertex]=true;
    cout<<vertex<<" ";
    bool is_cycle=false;
    //current_vertex.push_back(vertex);
    // cout<<vertex<<" ";

        for(auto i=graph[vertex].begin(); i!=graph[vertex].end(); i++)
    {

        if(visited[*i] && *i ==par)
            continue;

        if(visited[*i]) return true;

        is_cycle |= dfs(*i,vertex);
    }

    return is_cycle;
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


    bool isCycle=false;
    for(int i=1;i<=v;i++)
    {
        if(visited[i])continue;
        if(dfs(i,-1))
        {
            cout<<"Cycle exist\n";
        isCycle=true;
          break;
        }


    }
    if(!isCycle)
        cout<<"No cycle exist\n";



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
8 6
1 2
2 3
2 4
3 5
6 7
1 5


8 5
1 2
2 3
2 4
3 5
6 7


*/


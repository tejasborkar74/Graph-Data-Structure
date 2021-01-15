#include <bits/stdc++.h>
using namespace std;

class graph
{
    map<int,list<int> > adjList;

    public:

    void addEdge(int u,int v,bool bi=false)
    {
        adjList[u].push_back(v);

        if(bi)
        {
            adjList[v].push_back(u);
        }
    }
//=============================================================================================================//
    void helper(int src, map<int,bool > &visited,list<int> &ans)
    {
        visited[src]=true;

        for(auto neigh : adjList[src])
        {
            if(!visited[neigh])
            {
                helper(neigh,visited,ans);
            }
        }

        ans.push_front(src);
    }

    void dfs_topological_sort()
    {
        map<int,bool > visited;
        list<int> ans;
        for( auto i : adjList)
        {
            if(!visited[i.first])
            {
                helper(i.first,visited,ans);
            }
        }

        for(auto i : ans)
        {
            cout<<i <<" ";
        }
    }
//================================================KADAN'S_ALGO======================================================//

void bfs_topological_sort()
{
    map<int,bool > visited;
    map<int,int> indegree;

    queue<int> q;

    for(auto i: adjList)
    {
        int temp=i.first;
        visited[temp]=false;
        indegree[temp]=0;
    }

    //calc the indegree for all nodes

    for(auto i:adjList)
    {
        for(auto neigh : i.second)
        {
            indegree[neigh]++;
        }
    }

    //find all the nodes with indegree 0

    for(auto i:adjList)
    {
        if(indegree[i.first]==0)
        {
            q.push(i.first);
        }
    }

    //BFS

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        cout<<node<<" ";

        for(auto neigh : adjList[node])
        {
            indegree[neigh]--;
            if(indegree[neigh]==0)
            {
                q.push(neigh);
            }
        }
    }
}
};
int main() {
    graph g;

    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(3,2);
    g.addEdge(3,5);
    g.addEdge(3,6);
    g.addEdge(3,7);
    g.addEdge(2,4);
    g.addEdge(4,7);
    g.addEdge(7,8);
    g.addEdge(5,8);
    g.addEdge(6,8);

    g.dfs_topological_sort();

    cout<<endl;

    g.bfs_topological_sort();

}

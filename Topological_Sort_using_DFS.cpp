#include <bits/stdc++.h>
using namespace std;

class graph
{
    map<int, list<int> > adjList;

    public:

    void addEdge(int u,int v,int bidi=false)
    {
        adjList[u].push_back(v);

        if(bidi)
        {
            adjList[v].push_back(u);
        }
    }

    void helper(int src,map<int,bool > &visited,list<int> &ans)
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

   void dfs_topologicalSort()
    {
        map<int,bool > visited;
        list<int> ans;

        for(auto i : adjList)
        {
            if(!visited[i.first])
            {
                helper(i.first,visited,ans);
            }
        }

        for(auto i : ans)
        {
            cout<<i<<" ";
        }
        cout<<endl;

    }
};
int main()
{
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

    g.dfs_topologicalSort();
}

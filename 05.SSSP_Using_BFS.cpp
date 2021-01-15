#include <bits/stdc++.h>
using namespace std;

class graph
{
    map<int,list<int > > adjList;

    public:

    void addEdge(int u,int v,bool bidi=true)
    {
        adjList[u].push_back(v);

        if(bidi)
        {
            adjList[v].push_back(u);
        }
    }

    void sssp_using_bfs(int src)
    {
        queue<int> q;
        map<int,int> dist,parent;

        for(auto i : adjList)
        {
            dist[i.first]=INT_MAX;
        }

        q.push(src);
        dist[src]=0;
        parent[src]=src;

        while(!q.empty())
        {
            int f = q.front();
            q.pop();

            for(int neigh : adjList[f])
            {
                if(dist[neigh]==INT_MAX)
                {
                    q.push(neigh);

                    dist[neigh]=dist[f]+1;
                    parent[neigh]=f;
                }
            }
        }

        //print distance from src

        for(auto i : adjList)
        {
            cout<<"Distance of "<<i.first<<" from "<<src<<" is "<<dist[i.first]<<endl;
        }
    }
};
int main() {
    graph g;

    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(2,1);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(4,3);
    g.addEdge(5,3);

    g.sssp_using_bfs(0);
}

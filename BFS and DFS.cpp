#include<bits/stdc++.h>
using namespace std;

class graph
{
    map<int,list<int> > adjList;

public:
    void addEdge(int u,int v,bool isbi=true)
    {
        adjList[u].push_back(v);

        if(isbi)
        {
            adjList[v].push_back(u);
        }
    }

    void BFS(int src)
    {
        queue<int> q;
        q.push(src);
        q.push(-1);

        map<int,bool> visited;
        visited[src]=true;

        while(!q.empty())
        {
            int f = q.front();
            if(f==-1)
            {
                cout<<endl;
                q.pop();
                if(q.empty())
                {
                    break;
                }
                q.push(-1);
            }

            f=q.front();

            q.pop();

            cout<<f<<" ";

            for(auto neigh : adjList[f])
            {
                if(visited[neigh]==false)
                {
                    q.push(neigh);
                    visited[neigh]=true;
                }
            }
        }
    }

    void dfshelper(int node , map<int,bool> &visited)
    {
        visited[node]=true;

        cout<<node<<" ";

        for(int neigh : adjList[node])
        {
            if(!visited[neigh])
            {
                dfshelper(neigh,visited);
            }
        }
    }

    void DFS(int src)
    {
        map<int,bool> visited;

        dfshelper(src,visited);
    }

};
int main()
{
     graph g;

    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(3,1);
    g.addEdge(3,4);
    g.addEdge(4,1);
    g.addEdge(2,3);
    g.addEdge(2,1);

    //g.BFS(0);

    g.DFS(4);

}

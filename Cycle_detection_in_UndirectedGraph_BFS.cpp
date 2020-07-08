#include <bits/stdc++.h>
using namespace std;

class graph
{
    map<int,list<int> > adjList;

    public:

    void addEdge(int u,int v,bool bi=true)
    {
        adjList[u].push_back(v);

        if(bi)
        {
            adjList[v].push_back(u);
        }
    }


bool isCyclicBFS(int src)
{
    map<int,bool> visited;

    map<int,int> parent;

    queue<int> q;

    q.push(src);

    visited[src]=true;
    parent[src]=src;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

      for(auto neigh : adjList[node])
      {
          if(!visited[neigh])
          {
              visited[neigh]=true;
              parent[neigh]=node;

              q.push(neigh);
          }
          else if(visited[neigh]==true && parent[node]!=neigh)
          {
              return true;
          }
      }
    }

    return false;
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



    cout<<g.isCyclicBFS(0);

}

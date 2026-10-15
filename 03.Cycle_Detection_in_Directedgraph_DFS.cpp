#include <bits/stdc++.h>
using namespace std;

/*
If you want to find out cycle is present or not in the directed graph using BFS
then Apply topological sort (khans algo)

Reason: Since we know topological sort can only be applied in DAG 
so if cycle is present then it will fail -> fail meaning -> do not produce topo sort of v vertices
*/

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


    bool helper(int src ,  map<int,bool> &visited,map<int,bool> &instack)
    {
        visited[src]=true;
        instack[src]=true;

        for(auto neigh : adjList[src])
        {
            if(instack[neigh]==true || (!visited[neigh] && helper(neigh,visited,instack)))
                return true;
        }

        instack[src]=false;
        return false;
    }

    bool isCyclicDFS()
    {
        map<int,bool> visited;
        map<int,bool> instack;

        for(auto i:adjList)
        {
            if(!visited[i.first])
            {
                bool cyclePresent = helper(i.first,visited,instack);

                if(cyclePresent)return true;
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



    cout<<g.isCyclicDFS();

}

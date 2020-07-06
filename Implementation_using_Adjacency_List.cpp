#include<bits/stdc++.h>
using namespace std;

class graph
{
    map<int,list<int> > adjList;

public:
    graph()
    {    }

    void addEdge(int u,int v,bool isbidi=true)
    {
        adjList[u].push_back(v);

        if(isbidi)
        {
            adjList[v].push_back(u);
        }
    }

    void printGraph()
    {
        for(auto i : adjList)
        {
            cout<<i.first<<"-->";
            for(int neig : i.second)
            {
                cout<<neig<<" ,";
            }

            cout<<endl;
        }
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

    g.printGraph();
}

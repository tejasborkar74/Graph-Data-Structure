/*
TIme Complexity 0(VE)
and E id proportional to V^2 == O(v^3)

The Bellman-Ford algorithm is used to find the shortest paths from a single source node to all other nodes in a weighted graph, even when the graph contains negative edge weights.

🔍 When to use Bellman-Ford instead of Dijkstra?
    If the graph has negative weight edges
    If you want to detect negative weight cycles
    If the graph is sparse (low number of edges compared to nodes)
*/


#include <bits/stdc++.h>
using namespace std;

class Edge
{
    public:
    int src,dest,wt;
};

class graph
{
    int v,e;
    Edge *edge;

    public:

    graph(int vertices,int edges)
    {
        v = vertices;
        e = edges;
        edge = new Edge[e];
    }

    void addedge(int src ,int dest,int wt,int i)
    {
        edge[i].src = src;
        edge[i].dest = dest;
        edge[i].wt = wt;
    }

    void BellmanFord(int source)
    {
        map<int,int> distance;

        for(int i=0;i<v;i++)
        {
            if(i==source)
            {
                distance[i] = 0;
            }
            else
            {
                distance[i] = INT_MAX;
            }
        }


        //relax v-1 times

        for(int i=0;i<v-1;i++)
        {
            for(int j=0;j<e;j++)
            {
                int src = edge[j].src;
                int dest = edge[j].dest;
                int wt = edge[j].wt;

                if(distance[src]!=INT_MAX && (distance[dest] > distance[src]+wt))
                {
                    distance[dest] = distance[src]+wt;
                }
            }
        }


        //one more time for -ve weight cycle

         for(int j=0;j<e;j++)
            {
                int src = edge[j].src;
                int dest = edge[j].dest;
                int wt = edge[j].wt;

                if(distance[src]!=INT_MAX && (distance[dest] > distance[src]+wt))
                {
                   cout<<"Graph has negetive weight cycle!!\n";
                }
            }


            //print distance array

            for(int i=0;i<v;i++)
            {
                cout<<"distance of "<<i<<" from "<<source<< " is "<<distance[i]<<endl;
            }

    }

};
int main() {
    graph g(5,7);

    g.addedge(1,0,-1,0);
    g.addedge(0,2,3,1);
    g.addedge(3,0,4,2);
    g.addedge(0,4,2,3);
    g.addedge(1,2,4,4);
    g.addedge(3,2,5,5);
    g.addedge(4,3,-3,6);

    g.BellmanFord(1);
}

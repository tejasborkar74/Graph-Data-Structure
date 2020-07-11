#include <bits/stdc++.h>
using namespace std;

class graph
{
    map<int,list<pair<int,int> > > adjList;

    public:

    void addEdge(int u,int v,int dist,bool bi=true)
    {
        adjList[u].push_back(make_pair(v,dist));

        if(bi)
        {
             adjList[v].push_back(make_pair(u,dist));
        }
    }

    void dijkstraSSP(int src)
    {
        map<int,int> dist;

        for(auto i : adjList)
        {
            dist[i.first]=INT_MAX;
        }

        dist[src]=0;

        set<pair<int,int> > s;

        s.insert(make_pair(dist[src],src));

        while(!s.empty())
        {
            auto f = *(s.begin());

            int node = f.second;
            int nodedist = f.first;

            s.erase(s.begin());

            for(auto neigh : adjList[node])
            {
                if(dist[neigh.first] > nodedist + neigh.second)
                {
                    //delete exisiting set

                    auto temp = s.find(make_pair(dist[neigh.first] , neigh.first));
                    if(temp!=s.end())s.erase(temp);

                    //update values

                    dist[neigh.first] = nodedist + neigh.second;
                    s.insert(make_pair(nodedist + neigh.second , neigh.first));

                }
            }
        }

        for(auto i : dist)
        {
            cout<<i.first<<" is at distance of "<<i.second<<endl;
        }

    }
};
int main()
{
    graph g;

    g.addEdge(0,1,4);
    g.addEdge(0,2,1);
    g.addEdge(2,1,2);
    g.addEdge(3,1,8);
    g.addEdge(4,3,3);
    g.addEdge(5,4,2);
    g.addEdge(2,5,1);

    g.dijkstraSSP(0);

}

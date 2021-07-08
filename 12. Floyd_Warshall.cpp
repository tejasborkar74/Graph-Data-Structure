// Find all pair shortest path
// Also check -ve weight cycle => after complete ans if d[i][i] < 0 => -ve weight cycle
// Time Complexity O(v^3)
// Space Complexity O(v^2)

#include <bits/stdc++.h>
using namespace std;

#define V 6

void pre_fast()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void floyd_warshall(int graph[V][V])
{
    int dist[V][V];

    // At this pt dist conatin only neigh distane and all are INT_MAX
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    // Algo
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)continue;
                else dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    //check -ve cycle
    for (int i = 0; i < V; i++)
    {
        if (dist[i][i] < 0)
        {
            cout << "-ve weight cycle is present\n";
        }
    }

    //Print Shortest Path Graph
    //(Values printed as INT_MAX defines there is no path)
    for (int i = 1; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cout << i << " to " << j << " distance is " << dist[i][j] << "\n";
    }



}


int main()
{
    pre_fast();
    int graph[V][V] = { {0, 1, 4, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, 0, 4, 2, 7, INT_MAX},
        {INT_MAX, INT_MAX, 0, 3, 4, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 4},
        {INT_MAX, INT_MAX, INT_MAX, 3, 0, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 5, 0}
    };

    floyd_warshall(graph);
    return 0;
}

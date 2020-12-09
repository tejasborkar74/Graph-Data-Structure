#include<bits/stdc++.h>
using namespace std;
#define ll long long

class graph
{
public:
	int v;
	list<pair<int, int> >  *adjList ; //for storing adj ele and weight

	graph(int v)
	{
		this->v = v;
		adjList = new list<pair<int, int> > [v];
	}

	void addEdge(int u, int v, int w)
	{
		adjList[u].push_back(make_pair(v, w));
		adjList[v].push_back(make_pair(u, w));
	}

	int findMinVertex(int *weight , bool * visited)
	{
		int minVertex = -1;

		for (int i = 0; i < v; i++)
		{
			if (!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex]))
			{
				minVertex = i;
			}
		}

		return minVertex;
	}
	void Prims()
	{
		bool *visited = new bool[v];
		int *parent = new int [v];
		int *weight = new int[v];

		for (int i = 0; i < v; i++)
		{
			visited[i] = false;
			weight[i] = INT_MAX;
		}

		//start with 0 vertex

		parent[0] = -1;
		weight[0] = 0;



		for (int i = 0; i < v; i++)//select v-1 edges
		{
			int minVertex = findMinVertex(weight, visited);

			visited[minVertex] = true;

			for (auto neigh : adjList[minVertex])
			{
				if (!visited[neigh.first])
				{
					if (weight[neigh.first] > neigh.second)
					{
						parent[neigh.first] = minVertex;
						weight[neigh.first] = neigh.second;
					}
				}
			}
		}

		//cout << v << endl;



		for (int i = 1; i < v; i++)
		{
			cout << i << " --> " << parent[i] << " with weight " << weight[i] << endl;
		}

	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt" , "r" , stdin);
	freopen("output1.txt" , "w" , stdout);
#endif


	int v, e;
	cin >> v >> e;

	//cout << "Asd";

	graph g(v);

	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		g.addEdge(u, v, w);

	}

	g.Prims();

}
/*
	* Used to find MST from
	* Greedy Algo
	* For Udirected and weighted graph
	* STEPS
		1. Find the edge of min weight
		2. Insert this edge for MST if and only if after inserting there is
		   no cycles forms in the Graph
*/
#include <bits/stdc++.h>
using namespace std;

class Edge
{
public :

	int src ;
	int dest ;
	int wt ;
};

bool compare(Edge e1 , Edge e2)
{
	return e1.wt < e2.wt;
}

int findparent(int v , int *parent)
{
	if (parent[v] == v)return v;

	return findparent(parent[v] , parent);
}

void kruskal(Edge *input , int  v , int  e)
{

	Edge  *output = new Edge[v - 1];

	sort(input , input + e , compare);

	int *parent = new int[v];

	for (int i = 0; i < v; i++)
	{
		parent[i] = i;
	}

	int i = 0, count = 0;

	while (count < v - 1)
	{
		Edge curr = input[i];

		//check if we can add this edge in MST(not form cycle)

		int srcparent = findparent(curr.src , parent);
		int destparent = findparent(curr.dest , parent);

		if (srcparent != destparent)
		{
			output[count] = curr;
			count++;
			parent[srcparent] = destparent; //Important
		}

		i++;
	}


	for (int i = 0; i < v - 1 ; i++)
	{
		cout << output[i].src << " " << output[i].dest << " " << output[i].wt << endl;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt" , "r" , stdin);
	freopen("output1.txt" , "w" , stdout);
#endif

	int v, e;
	cin >> v >> e;

	Edge *input = new Edge[e];

	for (int i = 0; i < e; i++)
	{
		int s, d, w;
		cin >> s >> d >> w;

		input[i].src  = s;
		input[i].dest = d;
		input[i].wt = w;
	}

	kruskal(input , v, e);

	//cout << "finids" << endl;

}
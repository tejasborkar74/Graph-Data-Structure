#include <bits/stdc++.h>
using namespace std;

void dfs1(int i , unordered_map<int, vector<int> > &adjList , vector<bool> &visited , stack<int> &st)
{
    visited[i] = true;

    for (int neigh : adjList[i])
    {
        if (!visited[neigh])
        {
            dfs1(neigh , adjList , visited , st);
        }
    }
    st.push(i);
}

void reverseGraph(unordered_map<int, vector<int> > adjList, unordered_map<int, vector<int> > &rev, int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int neigh : adjList[i])
        {
            rev[neigh].push_back(i);
        }
    }
}

void dfs2(int i , vector<bool> &visited , unordered_map<int, vector<int> > &rev)
{
    cout << i << " ";
    visited[i] = true;

    for (int neigh : rev[i])
    {
        if (!visited[neigh])
        {
            dfs2(neigh, visited, rev);
        }
    }
}

void kosarajuAlgo(unordered_map<int, vector<int> > adjList, int v)
{
    stack<int> st;

    vector<bool> visited(v, false);

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs1(i, adjList, visited, st);
        }
    }

    unordered_map<int, vector<int> > rev;
    reverseGraph(adjList, rev, v);

    for (int i = 0; i < v; i++)visited[i] = false;

    cout << "Strongly Connected Components are : \n";

    while (!st.empty())
    {
        int curr = st.top();
        st.pop();

        if (!visited[curr])
        {
            dfs2(curr, visited , rev);
            cout << endl;
        }
    }
}

int main()
{
    unordered_map<int, vector<int> > adjList;

    adjList[0].push_back(1);
    adjList[1].push_back(2);
    adjList[2].push_back(0);
    adjList[2].push_back(3);
    adjList[3].push_back(4);
    adjList[4].push_back(5);
    adjList[5].push_back(6);
    adjList[6].push_back(4);
    adjList[6].push_back(7);
    adjList[4].push_back(7);

    int v = 8;

    kosarajuAlgo(adjList, v);
}

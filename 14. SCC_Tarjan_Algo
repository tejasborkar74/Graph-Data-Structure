/*
    Strongly Connected Component is a component 
    in which you can reach from any node to any node in the component

    Time Complexity: O(V+E) // Single DFS
    Space Complexity: O(V); // Stack and vectors used

    In Kosaraju Time Complexity was: O(V^3) & Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int v = 7;
map<int, vector<int> > adj;

void help(int i, vector<int> &dis, vector<int> &low, vector<bool> &instack, stack<int> &st)
{
    static int t = 0;

    dis[i] = low[i] = t++;
    st.push(i);
    instack[i] = true;

    for (auto neigh : adj[i])
    {
        if (dis[neigh] == -1)
        {
            help(neigh, dis, low, instack, st);
            low[i] = min(low[i], low[neigh]);
        }
        else if (instack[neigh] == true)
        {
            // Back Edge
            low[i] = min(low[i], dis[neigh]);
        }
    }

    // Is head of a SCC
    if (low[i] == dis[i])
    {
        cout << "SCC is ";
        while (st.top() != i)
        {
            cout << st.top() << " ";
            instack[st.top()] = false;
            st.pop();
        }

        cout << st.top() << endl;
        instack[st.top()] = false;
        st.pop();
    }
}

void SCC_Tarjan()
{
    vector<int> dis(v, -1), low(v, -1);
    vector<bool> instack(v, false);
    stack<int> st;

    for (int i = 0; i < v; i++)
    {
        if (dis[i] == -1)
        {
            help(i, dis, low, instack, st);
        }
    }
}


int main()
{
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(0);
    adj[4].push_back(5);
    adj[4].push_back(6);
    adj[5].push_back(6);
    adj[6].push_back(5);
    adj[5].push_back(2);

    SCC_Tarjan();
}

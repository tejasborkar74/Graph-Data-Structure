/*
    Bipartite Graph : Graph is bipartite if it is possible to divide the vertices of graph 
    into 2 mutually exclusive (No commom vertices in 2 set) and 
    exhaustive (all vertices are covered) subsets 
    * All edges are across set
    
    Example: 

        0----3
        |    |        0,2 and 1,3  (Bipartite)
        1----2

        4----6
         \  /          4 and 5,6 (Not Bipartite)
          5

    Answer:
    * Every non cyclic graph is  bipartite
    * If cycle present 
            * cycle size => even => bipartite
            * cycle size => odd  => not bipartite


    => Non cyclic => bfs => put alternate level on alternate set

    CODE : 
    Do bfs level wise and color the nodes 0,1 alternate levels
*/
#include <bits/stdc++.h>0
using namespace std;


void pre_fast()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main()
{
    pre_fast();
   
}

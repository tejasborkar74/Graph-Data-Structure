/*
	* this return the wight of the MST
	* O(E LogV)
 	* STEPS:
		1. min priority_queue (weight)
  		2. push {0, src}
    		3. while !q.empty()
      		4. if top element is visited => continue 
		5. if not visited => add it in ans
  			a. iterate all the neigh and push the {wt, neigh}
 
*/
int spanningTree(int v, vector<vector<int>> adj[]) {
        
        vector<bool> visited(v, false);
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>> > q;
        
        // wt, node
        q.push({0, 0});
        
        int ans = 0;
        
        while(!q.empty()) {
            auto f = q.top();
            q.pop();
            int node = f.second;
            int wt = f.first;
            
            if(visited[node] == true)continue;
            
            // add it to MST
            ans += wt;
            
            visited[node] = true;
            for(auto it : adj[node]) {
                int neigh = it[0];
                int w = it[1];
                
                if(visited[neigh] == false) {
                    q.push({w, neigh});
                }
            }
        }
        
        return ans;
        
    }

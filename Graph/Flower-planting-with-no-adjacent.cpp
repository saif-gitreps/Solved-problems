// deleted prev lame attempt.

class Solution {
//this worked till  7 test cases, not working for more.
public:
    vector<bool> visited;
    vector<vector<int>> paths;
    Solution(){
        visited.resize(10000);
        paths.resize(10000);
    }
    void bfs(int source,int n,vector<int> &valid_path){
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while(q.empty()==false){
            int temp = q.front();
            q.pop();
            valid_path.push_back(temp);
            if(valid_path.size()==n){
                return;
            }
            for(auto s: paths[temp]){
                if(!visited[s]){
                    visited[s] = true;
                    q.push(s);
                }
            }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& a) {
        vector<int> valid_path;
        for(int i = 0 ; i < a.size(); i++ ){
            paths[a[i][0]].push_back(a[i][1]);
            paths[a[i][1]].push_back(a[i][0]);
        }
        bfs(1,n,valid_path);
        if(valid_path.size()<n){
            int existing_limit = valid_path.size();
            int k = 0;
            for(int i=0;i<n-existing_limit;i++){
                if(k >= existing_limit){
                    k = 0 ;
                }
                else{
                    valid_path.push_back(valid_path[k]);
                    ++k;
                }
            } 
        }
        return valid_path;
    }
};

class Solution {
// tried after 8 months again it seems. this time i had the right idea. It was related to the bipartite problem.
// The only thing i could not wrap my head around was the occupied parents or connected node but.
// happy to see having an intiotion tht is close. TC -> O(E + V)
public:
    void dfs(int src, vector<int> adj[], vector<int> &vis){
        for(int i = 1; i <= 4; i++){
            int taken = false;
            for(auto child: adj[src]){
                if(vis[child] != 0 && vis[child] == i){
                    taken = true;
                }
            }
            if(!taken){
                vis[src] = i;
                return;
            }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj[n];
        vector<int> vis(n, 0);

        for(int i = 0; i < paths.size(); i++){
            adj[paths[i][0] - 1].push_back(paths[i][1] - 1);
            adj[paths[i][1] - 1].push_back(paths[i][0] - 1);
        }

        for(int i = 0; i < n; i++){
            dfs(i, adj, vis);
        }

        return vis;
    }
};


class Solution {
// improved solution, wow. but this uses some extra memory so there is a trade off.
public:
    void dfs(int src, vector<int> adj[], vector<int> &vis){
        vector<bool> colorsUsed(5, false);
    for (auto child : adj[src]) {
        if (vis[child] != 0) {
            colorsUsed[vis[child]] = true;
        }
    }
    for (int color = 1; color <= 4; color++) {
        if (!colorsUsed[color]) {
            vis[src] = color;
            break;
        }
    }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj[n];
        vector<int> vis(n, 0);

        for(int i = 0; i < paths.size(); i++){
            adj[paths[i][0] - 1].push_back(paths[i][1] - 1);
            adj[paths[i][1] - 1].push_back(paths[i][0] - 1);
        }

        for(int i = 0; i < n; i++){
            dfs(i, adj, vis);
        }

        return vis;
    }
};

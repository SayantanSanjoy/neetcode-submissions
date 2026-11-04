class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1){
            return false;
        }
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        int count=0;

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int>q;
        q.push(0);
        vis[0]=1;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return count==n;
    }
};

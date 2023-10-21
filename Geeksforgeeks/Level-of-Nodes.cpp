// BFS traversal
// tc : O(V+E)
// sc : O(V) for queue, vis
class Solution {
public:
    int nodeLevel(int V,vector<int> adj[],int target){
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<bool> vis(V);
        vis[0] = true;

        while(not q.empty()){
            int curr = q.front().first;
            int level = q.front().second;
            q.pop();

            if(curr==target) return level;

            for(int neighbour : adj[curr]){
                if(not vis[neighbour]){
                    q.push({neighbour,level+1});
                    vis[neighbour] = true;
                }
            }
        }
        return -1;
    }
};
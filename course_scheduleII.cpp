class Solution {
public:
    
    void dfs(int node, int n,  vector<int> &vans, vector<int>v[100000], int vis[], int &flag){
        vis[node] = 1;
        
        for(int i = 0; i < v[node].size(); i++){
            
            if(vis[v[node][i]] == 1){
                flag = 1;
            }
            
            
            if(vis[v[node][i]] == 0){
                dfs(v[node][i], n, vans, v,vis,flag);
            }
            
        }
        
        vans.push_back(node);
        vis[node] = 2;
        
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vans;
        vans.clear();
        
        if(numCourses<= 0){
            return vans;
        }
        
        int n = numCourses;
        int parent[n],i,vis[n];
        memset(vis, '\0', sizeof(vis));
        
        for(i = 0; i < n; i++){
            parent[i] = -1;
        }
        
        vector<int> v[n];
        
        for(i = 0; i < prerequisites.size(); i++){
            
            int a1 = prerequisites[i][0];
            int a2 = prerequisites[i][1];
            v[a1].push_back(a2);
            parent[a2] = a1;
            
        }
        int flag = 0;
        
        for(i = 0; i < n; i++){
            
            
            if(parent[i] == -1 && (vis[i]==0)){
                dfs(i, n, vans, v, vis,flag);
                if(flag != 0){
                vans.clear();
                return vans;
            }
            }
        }
        
        if(vans.size() == n)
            return vans;
        
        vans.clear();
        return vans;
        
    }
};
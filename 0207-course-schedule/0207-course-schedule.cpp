class Solution {
public:
bool dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &pathVis)
    {
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:adj[node])
        {
            if(vis[it]==0)
            {
                if(dfs(it,adj,vis,pathVis)==true) return true;
            }
            else if(pathVis[it]==1)
            return true;
        }
        
        pathVis[node]=0;
        return false;
    }
    bool canFinish(int v, vector<vector<int>>& adjM) {
        vector<int> adj[v];
        for(auto it:adjM)
        {
            adj[it[1]].push_back(it[0]);
        }
        // for(int i=0;i<adjM.size();i++)
        // {
        //     for(auto it:adjM[i])
        //     {
        //         adj[]
        //     }
        // }
        // for(int i=0;i<v;i++)
        // {
        //     for(int j=0;j<v;j++)
        //     {
        //         if(adjM[i][j]==1&&i!=j)
        //         {
        //             adj[i].push_back(j);
        //         }
        //     }
        // }
        vector<int> vis(v,0);
        // int vis[v]={0};
        vector<int> pathVis(v,0);
        // int pathVis[v]={0};
        for(int i=0;i<v;i++)
        {
            if(vis[i]==0)
            {
                if(dfs(i,adj,vis,pathVis)==true) return false;
            }
        }
        return true;
        
    }
};
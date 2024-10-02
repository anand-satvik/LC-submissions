class Solution {
public:
bool bfs(int start,vector<int> adj[],int color[])
{
    queue<int> q;
    q.push(start);
    color[start]=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it: adj[node])
        {
            if(color[it]==-1)
            {
                color[it]=!color[node];
                q.push(it);
            }
            else if(color[it]==color[node])
            return false;
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> adj[v];
        for(int i=0;i<v;i++)
        {
            for(auto it:graph[i])
            adj[i].push_back(it);
        }
        int color[v];
        for(int i=0;i<v;i++)
        color[i]=-1;
        for(int i=0;i<v;i++)
        {
            if(color[i]==-1)
            {
                if(bfs(i,adj,color)==false)
                return false;
            }
        }
        return true;
    }
};
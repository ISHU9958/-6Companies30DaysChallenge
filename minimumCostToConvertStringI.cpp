#define ll long long


class elem{
    public:
    char u,v;
    int c;
    
};
class Solution {
    
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        vector<elem>graph;
        int n=changed.size();
        for(int i=0;i<n;i++){
            graph.push_back({original[i],changed[i],cost[i]});
        }
        
        vector<vector<ll>>dist(26,vector<ll>(26,LLONG_MAX));
        
        for(int i=0;i<26;i++) dist[i][i]=0;
        for(auto it:graph){
             int u = it.u - 'a';
            int v = it.v - 'a';
            ll wt = it.c;

            dist[u][v] = min(dist[u][v],wt);
            
        }
        
        
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    
                    if(dist[i][k]==LLONG_MAX || dist[k][j] == LLONG_MAX) continue;
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }

        ll total=0;
        for(int i=0;i<source.size();i++){
            char src=source[i];
            char tar=target[i];
            
            ll dis=dist[src-'a'][tar-'a'];
            
            if(dis==LLONG_MAX) return -1;

            total+=dis;
      
        }
        return total;
        
    }
};

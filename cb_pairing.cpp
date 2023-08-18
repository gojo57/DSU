#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define ones(x) __builtin_popcountll(x)
#define int long long
#define pii pair<int,int>
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
using namespace std;
const int mod = 1e9+7;

class Graph{
    int V;
    list<pair<int,int>> l;
public:
    Graph(int V){
        this->V = V;
    }
    void addEdge(int u,int v){
        l.push_back({u,v});
    }
    int findSet(int i,int parent[]){
        if(parent[i]==-1){
            return i;
        }
        // Path Compression
        return parent[i] =  findSet(parent[i],parent);
    }
    void unionSet(int x,int y,int parent[], int rank[]){
        int s1 = findSet(x,parent);
        int s2 = findSet(y,parent);
        if(s1!=s2){
            if(rank[s1]<rank[s2]){
                parent[s1] = s2;
                rank[s2]+=rank[s1];
            }
            else{
                parent[s2] = s1;
                rank[s1]+=rank[s2];
            }
        }
    }
    bool contains_cycle(){
        int *parent = new int[V];
        int *rank = new int[V];
        for(int i=0;i<V;i++){
            parent[i] = -1;
            rank[i] = 1;
        }
        for(auto edge:l){
            int i = edge.first;
            int j = edge.second;
            int s1 = findSet(i,parent);
            int s2 = findSet(j,parent);
            if(s1!=s2){
                unionSet(s1,s2,parent,rank);
            }
            else{
                return true;
            }
        }
        delete [] parent;
        delete [] rank;
        return false;
    }
    int pairing(){
        int *parent = new int[V];
        int *rank = new int[V];
        for(int i=0;i<V;i++){
            parent[i] = -1;
            rank[i] = 1;
        }
        for(auto edge:l){
            int i = edge.first;
            int j = edge.second;
            int s1 = findSet(i,parent);
            int s2 = findSet(j,parent);
            if(s1!=s2){
                unionSet(s1,s2,parent,rank);
            }
        }
        int ans = 0;
        for(int i=0;i<V;i++){
            ans+=V-rank[findSet(i,parent)];
        }
        delete [] parent;
        delete [] rank;
        return ans/2;
    }
};

int dfs(int node, vvi &adj, vi &vis){
    vis[node] = 1;
    int cnt = 1;
    for(auto child:adj[node]){
        if(!vis[child]){
            cnt+=dfs(child,adj,vis);
        }
    }
    return cnt;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //using dfs
    // int n,m; cin>>n>>m;
    // vvi adj(n+1);
    // for(int i=0;i<m;i++){
    //     int u,v; cin>>u>>v;
    //     adj[u].pb(v);
    //     adj[v].pb(u);
    // }
    // vi vis(n+1,0);
    // vi sz;
    // for(int i = 0; i<n; i++){
    //     if(!vis[i]){
    //         sz.pb(dfs(i,adj,vis));
    //     }
    // }
    // int ans = 0, sum = 0;
    // for(auto x:sz){
    //     ans+=sum*x;
    //     sum+=x;
    // }
    // cout<<ans<<endl;

    //using dsu
    int n,m; cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        g.addEdge(u,v);
    }
    cout<<g.pairing()<<endl;

    return 0;
}
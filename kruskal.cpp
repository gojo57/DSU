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
    int* parent;
    int* rank;
    vvi l;
public:
    Graph(int V){
        this->V = V;
        parent = new int[V];
        rank = new int[V];
        for(int i=0;i<V;i++){
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    void addEdge(int u,int v,int w){
        l.push_back({u,v,w});
    }
    int findSet(int i){
        if(parent[i]==-1){
            return i;
        }
        // Path Compression
        return parent[i] =  findSet(parent[i]);
    }
    void unionSet(int x,int y){
        int s1 = findSet(x);
        int s2 = findSet(y);
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
    int kruskal_mst(){
        int ans = 0;
        sort(all(l),[](vi a,vi b){
            return a[2]<b[2];
        });
        for(auto edge:l){
            int i = edge[0];
            int j = edge[1];
            int w = edge[2];
            int s1 = findSet(i);
            int s2 = findSet(j);
            if(s1!=s2){
                unionSet(s1,s2);
                ans+=w;
            }
        }
        return ans;
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Graph g(4);
    // g.addEdge(0,1,1);
    // g.addEdge(1,3,3);
    // g.addEdge(3,2,4);
    // g.addEdge(2,0,2);
    // g.addEdge(0,3,2);
    // g.addEdge(1,3,3);

    int n, m; cin>>n>>m;
    Graph g(n+1);
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }
    cout<<g.kruskal_mst()<<endl;
    return 0;
}
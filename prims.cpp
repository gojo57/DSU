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
    vpii *l;
    int V;
public:
    Graph(int n){
        this->V = n;
        l = new vpii[n];
    }
    void addEdge(int u,int v,int w){
        l[u].pb({v,w});
        l[v].pb({u,w});
    }
    int prims_mst(){
        int ans = 0;
        priority_queue<pii,vector<pii>,greater<pii>> q;
        bool *visited = new bool[V]{0};
        q.push({0,0});
        while(!q.empty()){
            auto best = q.top();
            q.pop();
            int to = best.second;
            int weight = best.first;
            if(visited[to]){
                continue;
            }
            ans+=weight;
            visited[to] = 1;
            for(auto x:l[to]){
                if(!visited[x.first]){
                    q.push({x.second,x.first});
                }
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

    int n,m;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u-1,v-1,w);
    }
    cout<<g.prims_mst()<<endl;    
    return 0;
}
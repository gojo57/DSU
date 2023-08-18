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

struct dsu{
    vector<int> parent;
    int n;
    dsu(int n){
        this->n = n;
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int findSet(int i){
        if(parent[i]==i){
            return i;
        }
        // Path Compression
        return parent[i] =  findSet(parent[i]);
    }
    void unionSet(int x,int y){
        x = findSet(x);
        y = findSet(y);
        if(x!=y){
            parent[x] = max(parent[x],parent[y]);
            parent[y] = max(parent[x],parent[y]);
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,q;
    cin>>n>>q;
    int l[q],r[q],c[q];
    for(int i=0;i<q;i++){
        cin>>l[i]>>r[i]>>c[i];
    }

    vi ans(n+2);
    dsu g(n+2);
    for(int i=q-1;i>=0;i--){
        int idx = g.findSet(l[i]);
        while(idx<=r[i]){
            ans[idx] = c[i];
            g.unionSet(idx,idx+1);
            idx = g.findSet(idx);
            if(idx>r[i]){
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
    
    return 0;
}
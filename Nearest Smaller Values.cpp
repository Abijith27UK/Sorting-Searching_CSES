//Nearest Smaller Values
//CSES Sorting and Searching
//Code by Abijith U K
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db long double
#define str string

using mpi = map<int,int>;
using mpl = map<ll,ll>;
using mpd = map<db,db>;

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<str>;
using vd = vector<db>;
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

#define input(type, ...) type __VA_ARGS__; cin >> __VA_ARGS__;
#define f(i,a,b) for ( ll i = a ; i < b ; i++ )
#define rf(i,a,b) for (ll i = b ; i > a; --i)
#define all(n) n.begin() , n.end()
#define r_all(n) n.rbegin() , n.rend()
#define no cout << "NO" << endl;
#define yes cout << "YES" << endl;
#define unique_sort(vec) sort(vec.begin(), vec.end()); vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
#define FILL(vec, value) fill(vec.begin(), vec.end(), value)
#define IOTA(vec, start) iota(all(vec), start)
#define endl "\n"
#define INF 1e18
const int MOD = 1e9 + 7;

ll pow(ll a , ll b){
    ll res = 1;
    while(b>0){
        if(b%2==1) res*=a;
        a *= a; b /= 2;
    }
    return res;
}

ll powerWithModulo(ll base, ll exponent, int mod) {
    ll result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

class DSU{
    vector<int> rank , parent , size;
public:
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i = 0 ; i <= n ; i++) parent[i] = i;
    }
    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void UnionByRank(int u , int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_v == ulp_u) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void UnionBySize(int u , int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_v == ulp_u) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

void solve(){
    int n; cin>>n;
    vi a(n+1);
    f(i,0,n) cin>>a[i+1];
    stack<pair<int,int>> st;
    vi ans;
    ans.push_back(0);
    st.push({a[1],1});
    f(i,2,n+1){
        while(!st.empty() && st.top().first>=a[i]) st.pop();
        if(!st.empty()) ans.push_back(st.top().second);
        else ans.push_back(0);
        st.push({a[i],i});
    }
    for(auto it : ans) cout<<it<<" ";
}

int32_t main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    ll t=1 ; //cin>>t;
    while(t--){
	    solve();
    }
}
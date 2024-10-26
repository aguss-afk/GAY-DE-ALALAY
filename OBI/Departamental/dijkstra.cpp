#include <bits/stdc++.h>

#define _USE_MATH_DEFINES
#define INF LLONG_MAX
#define MOD 1000000007

#define endl "\n"
#define sp " "

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define f1(i, x) for(auto &i : x)
#define f2(i, x, j) for(ll i = j; i < x; i++)

#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;

using namespace std;
using ll = long long;

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> arr(n);
    vector<ll> dis(n, INF);
    vector<bool> vis(n, 0);
    while(m--){
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
    }
    priority_queue<pair<ll, ll>> q;
    q.push({0, 0});
    dis[0] = 0;
    while(!q.empty()){
        pair<ll, ll> a = q.top();
        q.pop();
        if(vis[a.second]) continue;
        vis[a.second] = 1;
        f1(i, arr[a.second]){
            ll u = i.first, b = i.second;
            if(dis[u] > dis[a.second] + b){ 
                dis[u] = dis[a.second] + b;
                q.push({-dis[u], u});
            }
        }
    }
    f1(i, dis) cout << i << sp;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
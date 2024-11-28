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
ll n, m, num;
vector<vector<pair<ll, ll>>> arr;
vector<ll> dis;
void dijkstra(ll x){
    vector<bool> vis(n + 1, 0);
    dis.assign(n + 1, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, x});
    dis[x] = 0;
    while(!q.empty()){
        ll b = q.top().second;
        q.pop();
        if(vis[b]) continue;
        vis[b] = 1;
        f1(i, arr[b]){
            ll a = i.second, c = i.first;
            if(a + dis[b] < dis[c]){
                dis[c] = a + dis[b];
                q.push({dis[c], c});
            }
        }
    }
}
void solve(){
    cin >> n >> m; 
    arr.assign(n + 1, vector<pair<ll, ll>>(0));
    f2(i, m, 0){
        ll a, b, c;
        cin >> a >> b >> c;
        arr[a].push_back({b, c});
    }
    dijkstra(1);
    cout << dis[n];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}

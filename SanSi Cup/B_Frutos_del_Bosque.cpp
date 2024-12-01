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
    ll n;
    cin >> n;
    vector<vector<ll>> arr(n);
    f2(i, n - 1, 0){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    vector<ll> nof(n);
    vector<bool> vis(n, 0);
    f1(i, nof){
        cin >> i;
    }
    vector<ll> dis(n, 0);
    queue<ll> q;
    q.push(0);
    ll ma = 0;
    vis[0] = 1;
    while(!q.empty()){
        ll a = q.front();
        q.pop();
        f1(i, arr[a]){
            if(vis[i]) continue;
            vis[i] = 1;
            dis[i] = dis[a] + 1;
            ma = max(ma, dis[i]);
            q.push(i);
        }
    }
    ll tsum = 0, ans = 0;
    for(ll i = 0; i < n; i++){
        tsum += nof[i] * (dis[i] + 1);
    }
    for(ll i = 0; i < n; i++){
        ans = max(tsum - (nof[i] * (dis[i] + 1)) + (nof[i] * (ma + 1)), ans);
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
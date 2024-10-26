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
    int n, m, ans = 0;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    f1(i, arr)
        f1(j, i) cin >> j;
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    queue<pair<int, int>> q;
    f2(i, n, 0){
        f2(j, m, 0){
            if(arr[i][j] == '.' and !vis[i][j]){
                ans++;
                q.push({i, j});
                while(!q.empty()){
                    pair<int, int> a = q.front();
                    q.pop();
                    if(a.first == n or a.first < 0) continue;
                    if(a.second == m or a.second < 0) continue;
                    if(arr[a.first][a.second] != '.') continue;
                    if(vis[a.first][a.second]) continue;
                    vis[a.first][a.second] = 1;
                    q.push({a.first + 1, a.second});
                    q.push({a.first - 1, a.second});
                    q.push({a.first, a.second + 1});
                    q.push({a.first, a.second - 1});
                }
            }
        }
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}

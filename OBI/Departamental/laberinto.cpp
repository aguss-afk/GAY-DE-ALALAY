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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m));
    queue<pair<int, int>> q;
    f1(i, arr)
        f1(j, i)
            cin >> j;
    bool t = 1;
    f2(i, n, 0){
        f2(j, m, 0){
            if(arr[i][j] == 'A'){
                q.push({i, j});
                t = 0;
                break;
            }
        }
        if(!t) break;
    }
    while(!q.empty()){
        pair<int, int> a = q.front();
        q.pop();
        int i = a.first, j = a.second;
        if(i < 0 or i == n) continue;
        if(j < 0 or j == m) continue;
        if(arr[i][j] == '#') continue;
        if(vis[i][j]) continue;
        vis[i][j] = 1;
        arr[i][j] = 'A';
        q.push({i + 1, j});
        q.push({i - 1, j});
        q.push({i, j + 1});
        q.push({i, j - 1});
    }
    f1(i, arr){
        f1(j, i) cout << j;
        cout << endl;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
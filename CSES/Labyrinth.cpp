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
struct state {
    int x, y;
    string ans;
};

void solve(){
    int n, m, x, y;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    f2(i, n, 0){
        f2(j, m, 0){
            cin >> arr[i][j];
            if(arr[i][j] == 'A'){
                x = i;
                y = j;
            }
        }
    }
    queue<state> q;
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    q.push({x, y, endl});
    vis[x][y] = 1;
    vector<pair<int, int>> dir {{-1, 0}, {1, 0}, {-1, 0}, {1, 0}};
    string dir2 = "UDLR";
    while(!q.empty()){
        state a = q.front();
        q.pop();
        int i = a.x, j = a.y;
        if(arr[i][j] != 'A' and arr[i][j] != '.') continue;
        cout << a.x << sp << a.y << a.ans << endl;
        if(arr[i][j] == 'B'){
            cout << "YES" << endl;
            cout << a.ans.size() - 1;
            f1(p, a.ans) cout << p;
            return;
        }
        f2(i, 4, 0){
            int di = dir[i].first, dj = dir[i].second;
            char dirp = dir2[i];
            if(i + di >= n or i + di < 0 or j + dj >= m or j + dj < 0) continue;
            vis[i][j] = 1;
            state b;
            b.x = i;
            b.y = j;
            b.ans = a.ans + dir2[i];
            q.push(b);
        }
    }
    cout << "NO";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}

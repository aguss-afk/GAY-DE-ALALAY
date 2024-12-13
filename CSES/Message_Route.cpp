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
    vector<vector<int>> arr(n);
    vector<int> ans(n, -1);
    vector<bool> vis(n, 0);
    f2(i, m, 0){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        f1(i, arr[a]){
            if(vis[i]) continue;
            vis[i] = 1;
            q.push(i);
            ans[i] = a + 1;
        }
    }
    if(ans[n - 1] == -1){
        cout << "IMPOSSIBLE";
        return;
    }
    stack<int> s;
    s.push(n);
    int aux = n - 1;
    while(aux){
        s.push(ans[aux]);
        aux = ans[aux] - 1;
    }
    cout << s.size() << endl;
    while(!s.empty()){
        cout << s.top() << sp;
        s.pop();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}

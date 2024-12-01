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
    f2(i, m, 0){
        int a, b;
        cin >> a >> b;
        arr[a - 1].push_back(b - 1);
        arr[b - 1].push_back(a - 1);
    }
    int ans = 1e7;
    for(int i = 0; i < n; i++){
        vector<int> dis(n, -1);
        queue<int> q;
        q.push(i);
        dis[i] = 0;
        while(!q.empty()){
            int a = q.front();
            q.pop();
            f1(j, arr[a]){
                if(dis[j] == -1){
                    dis[j] = dis[a] + 1;
                    q.push(j);
                } else if(dis[j] >= dis[a]){
                    ans = min(ans, dis[a] + dis[j] + 1);
                }
            }
        }
    }
    if(ans == 1e7){
        cout << "-1" << endl;
        return;
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}

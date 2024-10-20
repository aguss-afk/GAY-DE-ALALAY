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
    vector<vector<int>> arr(n, vector<int>(m)), pos(n + 1, vector<int>(m + 1));
    map<ll, unordered_map<ll, ll>> ma;
    f1(i, arr)
        f1(j, i) cin >> j;
    ll aux = 0;
    f2(i, m, 0)
        pos[0][i] = ++aux;
    f2(i, n, 1)
        pos[i][0] = ++aux;
    f2(i, n + 1, 1){
        f2(j, m + 1, 1){
            pos[i][j] = pos[i - 1][j - 1];
            ma[pos[i][j]][arr[i - 1][j - 1]]++;
        }
    }
    unordered_multiset<bool> ans;
    f1(i, ma)
        ans.insert(i.second.size() == 1 ? 1 : 0);
    int q;
    cin >> q;
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        bool aux = (ma[pos[a][b]].size() == 1);
        ma[pos[a][b]][arr[a - 1][b - 1]]--;
        if(ma[pos[a][b]][arr[a - 1][b - 1]] == 0)
            ma[pos[a][b]].erase(arr[a - 1][b - 1]);
        arr[a - 1][b - 1] = c;
        ma[pos[a][b]][c]++;
        bool aux2 = (ma[pos[a][b]].size() == 1);
        ans.erase(ans.find(aux));
        ans.insert(aux2);
        if(ans.count(0)) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}

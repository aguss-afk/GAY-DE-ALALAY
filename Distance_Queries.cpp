#include <bits/stdc++.h>

#define _USE_MATH_DEFINES
#define endl "\n"
#define sp " "

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define f1(i, x) for (auto &i : x)
#define f2(i, x, j) for (int i = j; i < x; i++)

#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;

using namespace std;
using ll = long long;
vector<vector<int>> arr;
vector<int> id, depth, first;
vector<bool> vis;
vector<vector<pair<int, int>>> st;
int MAXN, k = 25;

void dfs(int a, int d) {
    id.push_back(a);
    depth.push_back(d);
    if (first[a] == -1) {
        first[a] = id.size() - 1;
    }
    f1(i, arr[a]) {
        if(vis[i]){
            continue;
        }
        vis[i] = 1;
        dfs(i, d + 1);
        id.push_back(a);
        depth.push_back(d);
    }
}

int lg(int p) {
    return p ? 31 - __builtin_clz(p) : -1;
}

void stable() {
    st.assign(k + 1, vector<pair<int, int>>(depth.size()));
    f2(i, depth.size(), 0) {
        st[0][i] = {depth[i], i};
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j + (1 << i) <= depth.size(); j++) {
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int query(int l, int r) {
    int i = lg(r - l + 1);
    pair<int, int> L = st[i][l], R = st[i][r - (1 << i) + 1];
    return (L < R) ? L.second : R.second;
}

void solve() {
    int q, n;
    cin >> n >> q;
    arr.assign(n, vector<int>());
    vis.assign(n, 0);
    first.assign(n, -1);
    f2(i, n - 1, 0) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    vis[0] = 1;
    dfs(0, 0);
    stable();
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int l = first[a], r = first[b];
        if (l > r) swap(l, r);
        int ans = query(l, r);
        cout << depth[l] + depth[r] - 2 * depth[first[id[ans]]] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
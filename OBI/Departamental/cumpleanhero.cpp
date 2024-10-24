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
    string x;
    cin >> x;
    vector<char> t1, t2;
    f2(i, n, 0) t1.push_back(x[i]);
    f2(i, n + m, n) t2.push_back(x[i]);
    reverse(all(t1));
    int v1 = 0, v2 = 0;
    set<int> ans;
    while(v1 < n and v2 < m){
        if(x[v1] == x[v2]) v2++;
        else if(x[v1] == 'P'){
            if(x[v2] == 'R') v2++;
            else v1++;
        } else if(x[v1] == 'R'){
            if(x[v2] == 'S') v2++;
            else v1++;
        } else {
            if(x[v2] == 'P') v2++;
            else v1++;
        }
 
    }
    for(v1; v1 < n; v1++) ans.insert(n - v1 - 1);
    for(v2; v2 < m; v2++) ans.insert(v2 + n + 1);
    v1 = 0, v2 = n;
    while(v1 < n and v2 < m){
        if(x[v1] == x[v2]) v1++;
        else if(x[v1] == 'P'){
            if(x[v2] == 'R') v2++;
            else v1++;
        } else if(x[v1] == 'R'){
            if(x[v2] == 'S') v2++;
            else v1++;
        } else {
            if(x[v2] == 'P') v2++;
            else v1++;
        }
 
    }
    for(v1; v1 < n; v1++) ans.insert(n - v1 - 1);
    for(v2; v2 < m; v2++) ans.insert(v2 + n + 1);
    cout << ans.size();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}

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
    int n, m, k, p = 0, a = 0, ans = 0;
    cin >> n >> m >> k;
    vector<int> pe(n), ap(m);
    f1(i, pe){
        cin >> i;
    } 
    f1(i, ap){
        cin >> i;
    }
    sort(all(pe));
    sort(all(ap));
    while(p < n and a < m){
        if(abs(pe[p] - ap[a]) <= k){
            ans++;
            p++;
            a++;
            continue;
        }
        if(pe[p] > ap[a]){
            a++;
            continue;
        }
        p++;
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}

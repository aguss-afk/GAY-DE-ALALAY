#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#define endl "\n"
#define sp " "
#define MOD 1000000007
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define f1(i, x) for(auto &i : x)
#define f2(i, x, j) for(ll i = j; i < x; i++)
#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;
#define INF LLONG_MAX
using namespace std;
typedef long long ll;
ll binpow(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b & 1){
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return res;
}
void solve(){
    ll a, b;
    cin >> a >> b;
    cout << binpow(a, b) << endl;
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

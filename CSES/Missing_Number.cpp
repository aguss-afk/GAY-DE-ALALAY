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
void solve(){
    ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2, sum2 = 0;
    f2(i, n - 1, 0){
        ll aux;
        cin >> aux;
        sum2 += aux;
    }
    cout << sum - sum2;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}

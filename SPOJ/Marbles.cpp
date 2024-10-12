#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#define endl "\n"
#define sp " "
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define f1(i, x) for(auto &i : x)
#define f2(i, x, j) for(ll i = j; i < x; i++)
#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;
#define INF LLONG_MAX
using namespace std;
typedef long long ll;
/*
    Te salvaste pero sigues siendo medio gay mejor anda ver al gay de palermo en twitter
*/
void solve(){
    ll n, m;
    cin >> n >> m;
    ll ans = 1, x = n - m;
    f2(i, n, x + 1){
        ans *= i;
        ans /= (i - x);
    }
    cout << ans << endl;
    // maldito codigo asqueroso porque funcionas que te pasa no deberias el anterior era mejor que mrd te pasa
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t;
    cin >> t;
    while(t--)
        solve();
}  

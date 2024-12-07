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
    ll n, sum = 0, r = 0, ans = INF;
    cin >> n; 
    vector<ll> arr(n), diff(n + 1);
    f1(i, arr){
        cin >> i;
    }
    sort(all(arr));
    f2(i, n - 1, 0){
        diff[i + 1] = arr[i + 1] - arr[i];
        sum += arr[i + 1] - arr[0];
    }
    ans = min(ans, sum);
    for(int i = 1; i < n; i++){
        sum -= diff[i] * (n - i);
        r += diff[i] * i;
        ans = min(ans, sum + r); 
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}

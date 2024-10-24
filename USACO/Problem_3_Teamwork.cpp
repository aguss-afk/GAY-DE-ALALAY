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
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n), c(n);
    f2(i, n, 0){
        cin >> arr[i];
        c[i] = arr[i];
    }
    f2(i, n, 0){
        ll cm = c[i];
        f2(j, k, 0){
            int a = i - j;
            if(a < 0) break;
            cm = max(cm, c[a]);
            arr[i] = max(arr[i], arr[a - 1] + cm * (j + 1));
        }
    }
    cout << arr[n - 1];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}

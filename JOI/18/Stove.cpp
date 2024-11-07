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
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n), sel;
    f1(i, arr){
        cin >> i;
    }
    vector<pair<ll, ll>> dur;
    f2(i, n - 1, 0){
        dur.push_back({arr[i + 1] - arr[i] - 1, i});
    }
    sort(rall(dur));
    f2(i, k - 1, 0){
        sel.push_back(dur[i].second);
    }
    sort(all(sel));
    if(!sel.size()){
        cout << arr[n - 1] + 1 - arr[0];
        return;
    }
    ll start = 0, j = 0, ans = 0;
    f2(i, n - 1, 0){
        if(j < sel.size()){
            if(i == sel[j]){
                j++;
                ans += arr[i] + 1 - arr[start];
                start = i + 1;
            }
        }
    }
    ans += arr[n - 1] + 1 - arr[start];
    cout << ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
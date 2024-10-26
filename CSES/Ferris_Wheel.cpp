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
    vector<int> arr(n);
    f1(i, arr){
        cin >> i;
    }
    sort(all(arr));
    int l = 0, r = n - 1, ans = 0;
    while(1){
        if(arr[l] + arr[r] <= k){
            l++;
        }
        r--;
        ans++;
        if(l > r){
            break;
        }
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}

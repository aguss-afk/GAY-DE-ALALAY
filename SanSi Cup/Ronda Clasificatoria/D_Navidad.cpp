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
ll k;
vector<ll> arr;
bool binsearch(ll mid){
    ll auxk = 0, auxsum = 0;
    for(ll i : arr){
        if(auxsum + i > mid){
            auxk++;
            auxsum = 0;
        }
        auxsum += i;
    }
    auxk++;
    return auxk <= k;
}
void solve(){
    ll n, sum = 0, ans;
    cin >> n;
    arr.assign(n, 0);
    f1(i, arr){
        cin >> i;
        sum += i;
    }
    cin >> k;
    ll r = sum , l = *max_element(arr.begin(), arr.end());
    while(l <= r){
        ll mid = (r + l) >> 1;
        if(binsearch(mid)){
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}

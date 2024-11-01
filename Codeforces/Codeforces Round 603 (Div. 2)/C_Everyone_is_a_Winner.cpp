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
vector<bool> ip(100000, 1);
vector<int> p;
void primes(){
    ip[0] = ip[1] = 0;
    for(ll i = 1; i <= 1e5; i++){
        if(ip[i] and i * i <= 1e5){
            for(ll j = i * i; j <= 1e5; j += i) ip[j] = 0;
        }
    }
    f2(i, 1e5, 0){
        if(ip[i]) p.push_back(i);
    }
}
void solve(){
    ll n;
    cin >> n; 
    set<ll> ans;
    ans.insert(0);
    for(int i = 0; i <= (n + 1) / 2; i++){
        ans.insert(n / p[i]);
    }
    ans.insert(n);
    cout << ans.size() << endl;
    f1(i, ans){
        cout << i << sp;
    }
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    primes();
    int t;
    cin >> t;
    while(t--)
        solve();
}

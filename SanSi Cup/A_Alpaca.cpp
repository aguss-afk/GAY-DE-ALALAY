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
    string x;
    cin >> x; 
    map<char, ll> ma;
    ll ans = INF;
    f1(i, x){
        if(i == 'A') ma['a']++;
        else if(i == 'P') ma['p']++;
        else if(i == 'L') ma['l']++;
        else if(i == 'C') ma['c']++;
    }
    ma['a'] /= 3;
    f1(i, ma){
        ans = min(ans, i.second);
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}

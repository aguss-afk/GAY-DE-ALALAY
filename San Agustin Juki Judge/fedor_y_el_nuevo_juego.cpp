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
void solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(m + 1);
    f1(i, arr) cin >> i;
    vector<string> diff;
    f1(i, arr){
        string x = "";
        while(i != 1){
            x += (i % 2 ? "1" : "0");
            i /= 2;
        }
        x += (i % 2 ? "1" : "0");
        int j = x.size();
        if(x.size() < n)
            for(int i = 0; i < n - j; i++) x += '0';
        diff.push_back(x);
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
        int aux = 0;
        for(int j = 0; j < diff[i].size(); j++) 
            if(diff[m][j] != diff[i][j]) aux++;
        if(aux <= k) ans++;
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    solve();
}
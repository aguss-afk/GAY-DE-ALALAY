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
    int n;
    cin >> n;
    if(n % 2){
        cout << -1;
        return;
    }
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);
    for(int i = 0; i < n - 1; i += 2){
        swap(arr[i], arr[i + 1]);
    }
    f1(i, arr) cout << i << sp;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    solve();
}
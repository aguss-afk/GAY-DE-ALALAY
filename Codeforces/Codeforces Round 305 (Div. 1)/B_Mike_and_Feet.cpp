#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#define endl "\n"
#define sp " "
#define MOD 1000000007
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define f1(i, x) for(auto &i : x)
#define f2(i, x, j) for(ll i = j; i < x; i++)
#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;
#define INF LLONG_MAX
using namespace std;
typedef long long ll;
void solve(){
    int n, ma = 0;
    cin >> n;
    vector<vector<int>> arr(n);
    f2(i, n, 0){
        int aux;
        cin >> aux;
        arr[0].push_back(aux);
        ma = max(aux, ma);
    }
    cout << ma << sp;
    for(int i = 0; i < n - 1; i++){
        ma = 0;
        for(int j = 0; j < arr[i].size() - 1; j++){
           int x = min(arr[i][j], arr[i][j + 1]);
           arr[i + 1].push_back(x);
           ma = max(ma, x);
        }
        cout << ma << sp;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}

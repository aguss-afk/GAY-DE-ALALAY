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
    double n;
    cin >> n;
    string x;
    cin >> x;
    if(ceil(sqrt(n)) != floor(sqrt(n))){
        cout << "No" << endl;
        return;
    }
    bool t = true;
    int y = sqrt(n);
    for(int i = 0; i < n; i++){
        if(i < y){
            if(x[i] != '1'){
                t = false;
                break;
            }
        } else if(i >= n - y){
            if(x[i] != '1'){
                t = false;
                break;
            }
        } else {
            if(i % y == y - 1 and x[i] != '1'){
                cout << 1;
                t = false;
                break;
            } else if(!(i % y) and x[i] != '1'){
                cout << 2;
                t = false;
                break;
            } else if(i % y and i % y != y - 1 and x[i] != '0'){
                t = false;
                break;
            }
        }
    }
    cout << (t ? "Yes" : "No") << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t;
    cin >> t;
    while(t--)
        solve();
}
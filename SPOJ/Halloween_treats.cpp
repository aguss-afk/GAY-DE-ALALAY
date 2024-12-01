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
int a, b;
void solve(){
    vector<ll> arr(b), s(b + 1);
    map<ll, vector<ll>> ma;
    f1(i, arr){
        cin >> i;
    }
    f2(i, b + 1, 1){
        s[i] = s[i - 1] + arr[i - 1];
        if(s[i] % a == 0){
            for(int j = 0; j < i; j++){
                cout << j + 1<< sp;
            }
            cout << endl;
            return;
        }
        ma[s[i] % a].push_back(i);
    }
    f1(i, ma){
        if(i.second.size() >= 2){
            for(int j = i.second[0] + 1; j <= i.second[1]; j++){
                cout << j << sp;
            }
            cout << endl;
            return;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    while(a and b){
        solve();
        cin >> a >> b;
    }
}
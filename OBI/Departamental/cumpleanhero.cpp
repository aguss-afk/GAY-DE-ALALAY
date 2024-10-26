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
    int n, m;
    cin >> n >> m;
    string x;
    cin >> x;
    string r1, l1, r2, l2;
    r1 = l1 = r2 = l2 = "";
    unordered_set<int> a;
    f2(i, n, 0)
        r1 += x[i];
    f2(i, n + m, n)
        l1 += x[i];
    reverse(all(l1));
    r2 = r1;
    l2 = l1;
    while(1){
        if(!r1.size() or !l1.size()) break;
        if(r1.back() == l1.back()) l1.pop_back();
        else if(r1.back() == 'P'){
            if(l1.back() == 'R') l1.pop_back();
            else r1.pop_back();
        } else if(r1.back() == 'R'){
            if(l1.back() == 'S') l1.pop_back();
            else r1.pop_back();
        } else {
            if(l1.back() == 'P') l1.pop_back();
            else r1.pop_back();
        }
    }
    f2(i, r1.size(), 0)
        a.insert(i);
    f2(i, l1.size(), 0)
        a.insert(n + m - i - 1);
    while(1){
        if(!r2.size() or !l2.size()) break;
        if(r2.back() == l2.back()) r2.pop_back();
        else if(r2.back() == 'P'){
            if(l2.back() == 'R') l2.pop_back();
            else r2.pop_back();
        } else if(r2.back() == 'R'){
            if(l2.back() == 'S') l2.pop_back();
            else r2.pop_back();
        } else {
            if(l2.back() == 'P') l2.pop_back();
            else r2.pop_back();
        }
    }
    f2(i, r2.size(), 0)
        a.insert(i);
    f2(i, l2.size(), 0)
        a.insert(n + m - i - 1);
    cout << a.size();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
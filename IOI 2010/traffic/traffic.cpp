#include "traffic.h"
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

int LocateCentre(int n, int p[], int s[], int d[]){
    vector<int> pref(n + 1);
    f2(i, n, 0){
        pref[i + 1] = p[i] + pref[i];
    }
    int ansa = 0, ma = pref[n];
    f2(i, n + 1, 1){
        int x = pref[i - 1];
        int y = pref[n] - pref[i];
        int t = max(x, y);
        if(t < ma){
            ansa = i - 1;
            ma = t;
        }
    }
    return ansa;
}
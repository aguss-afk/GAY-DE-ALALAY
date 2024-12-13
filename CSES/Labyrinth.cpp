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
    vector<vector<char>> arr(n, vector<char>(m)), ans(n, vector<char>(m, 'n'));
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    f1(i, arr){
        f1(j, i){
            cin >> j;
        }
    }    
    queue<pair<pair<int, int>, char>> q;
    int x, y, px, py;
    f2(i, n, 0){
        f2(j, m, 0){
            if(arr[i][j] == 'A'){
                x = i;
                y = j;
            }
            if(arr[i][j] == 'B'){
                px = i;
                py = j;
            }
        }
    }
    q.push({{x, y}, '\''});
    while(!q.empty()){
        int posx = q.front().first.first;
        int posy = q.front().first.second;
        char dir = q.front().second;
        q.pop();
        if(posx < 0 or posx == n) continue;
        if(posy < 0 or posy == m) continue;
        if(arr[posx][posy] == '#') continue;
        if(vis[posx][posy]) continue;
        vis[posx][posy] = 1;
        ans[posx][posy] = dir;
        q.push({{posx + 1, posy}, 'D'});
        q.push({{posx - 1, posy}, 'U'});
        q.push({{posx, posy + 1}, 'R'});
        q.push({{posx, posy - 1}, 'L'});
    }
    if(ans[px][py] == 'n'){
        cout << "NO";
        return;
    }
    string lans = "";
    while(py != y or px != x){
        lans += ans[px][py];
        if(ans[px][py] == 'D'){
            px--;
        } else if(ans[px][py] == 'U'){
            px++;
        } else if(ans[px][py] == 'R'){
            py--;
        } else if(ans[px][py] == 'L'){
            py++;
        }
    }
    cout << "YES" << endl;
    cout << lans.size() << endl;
    reverse(all(lans));
    cout << lans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}

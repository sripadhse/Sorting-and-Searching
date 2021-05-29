#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    map<ll,int> mp;
    mp[0]++;
    ll sum = 0, ans = 0;
    for (int x : a) {
        sum = (sum + x) % n;
        if (sum < 0) sum += n;
        ans += mp[sum];
        mp[sum]++;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}

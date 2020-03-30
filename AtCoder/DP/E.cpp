#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long LL;
const int N = 101;
const int V = 100001;

LL dp[N][V], w[N], v[N];

int main() {
    int n, wl;
    cin >> n >> wl;
    for(int i = 1; i <= n; ++i) cin >> w[i] >> v[i];

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < V; ++j) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            if(j >= v[i]) dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }
    int res = 0;
    for(int i = V - 1; i >= 0; --i) {
        if(dp[n][i] <= wl) {
            res = i; break;
        }
    }
    cout << res << endl;
    return 0;
}

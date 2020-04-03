#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long LL;
const int N = 101;
const int V = 100001;

LL dp[N][V], w[N], v[N];

int main() {
    freopen("a.txt", "r", stdin);
    int N, mod = 1e9 + 7;
    string s;
    cin >> N >> s;

    vector<vector<int> > dp(N + 1, vector<int>(N + 1, 0));
    dp[1][1] = 1;
    for(int i = 2; i <= N; ++i) {
        if(s[i - 2] == '<') {
            for(int j = 2; j <= i; ++j) {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % mod;
            }
        }
        else {
            for(int j = i - 1; j >= 1; --j) {
                dp[i][j] = (dp[i][j + 1] + dp[i - 1][j]) % mod;
            }
        }
    }

    int res = 0;
    for(int j = 1; j <= N; ++j) {
        res = (res + dp[N][j]) % mod;
    }
    cout << res << endl;
    return 0;
}

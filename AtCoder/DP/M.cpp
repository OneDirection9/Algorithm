#include <iostream>
#include <vector>

using namespace std;

int main() {
    // freopen("1.txt", "r", stdin);
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for(int i = 1; i <= N; ++i) cin >> a[i];
    
    vector<vector<int> > dp(N + 1, vector<int>(K + 1, 0));
    dp[0][0] = 1;
    int mod = 1e9 + 7, sum = 0;
    for(int i = 1; i <= N; ++i) {
        sum += a[i];
        for(int j = 0; j <= min(sum, K); ++j) {
            dp[i][j] = dp[i - 1][j];
            if(j > 0) {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
            }
            if(j - 1 - a[i] >= 0) {
                dp[i][j] = (dp[i][j] - dp[i - 1][j - 1 - a[i]] + mod) % mod;
            }
        }
    }
    cout << dp[N][K] << endl;
    return 0;
}
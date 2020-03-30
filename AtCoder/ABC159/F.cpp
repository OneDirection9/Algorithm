#include <iostream>
#include <vector>

using namespace std;

int main() {
    // https://atcoder.jp/contests/abc159/tasks/abc159_f
    // freopen("a.txt", "r", stdin);
    int mod = 998244353;
    int N, S, res = 0;
    cin >> N >> S;

    vector<int> A(N + 1, 0);
    for(int i = 1; i <= N; ++i) cin >> A[i];

    vector<int > dp(S+1, 0);
    for(int i = 1; i <= N; ++i) {
        for(int j = S; j >= A[i]; --j) dp[j] = (dp[j] + dp[j - A[i]]) % mod;
        if(S>=A[i]) dp[A[i]] = (dp[A[i]] + i) % mod;
        res = (res + 1ll * dp[S] * (N - i + 1)) % mod;
        dp[S] = 0;
    }
    cout << res << endl;
    return 0;
}

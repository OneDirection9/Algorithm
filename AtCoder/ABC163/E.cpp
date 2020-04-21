#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 2010;

pair<int, int> A[N];
LL dp[N][N];

LL solve(int idx, int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    LL res = max(
        1LL * A[idx].first * abs(A[idx].second - l) + solve(idx + 1, l + 1, r),
        1LL * A[idx].first * abs(A[idx].second - r) + solve(idx + 1, l, r - 1));
    dp[l][r] = res;
    return dp[l][r];
}

int main() {
    memset(dp, -1, sizeof(dp));
    freopen("a.txt", "r", stdin);
    int n, t;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> t;
        A[i] = {t, i};
    }
    sort(A + 1, A + n + 1, [&](pair<int, int> &p1, pair<int, int> &p2) {
        return p1.first > p2.first;
    });

    cout << solve(1, 1, n) << endl;
    return 0;
}

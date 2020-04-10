#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>
#include <cstring>
#include <functional>

using namespace std;

int count(int n) {
    int res = 0;
    while(n) {
        res += n & 1;
        n >>= 1;
    }
    return res;
}
int main() {
    // freopen("1.txt", "r", stdin);
    int N, mod = 1e9 + 7;
    cin >> N;
    int a = 1 << N;
    int C[N][N], dp[a];
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cin >> C[i][j];
    
    dp[0] = 1;
    for(int i = 1; i < a; ++i) {
        int ones = count(i);
        for(int j = 0; j < N; ++j) {
            if((i & (1 << j)) && C[ones - 1][j]) {
                dp[i] = (dp[i] + dp[i - (1 << j)]) % mod;
            }
        }
    }
    cout << dp[a - 1] << endl;
    
    return 0;
}

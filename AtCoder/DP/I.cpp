#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // freopen("1.txt", "r", stdin);
    int N;
    cin >> N;

    vector<double> p(N + 1);
    for(int i = 1; i <= N; ++i) cin >> p[i];

    int L = N / 2;
    vector<double> dp(L + 1, 0.0);
    dp[0] = 1.0;

    for(int i = 1; i <= N; ++i) {
        for(int j = min(i, L); j >= 0; --j) {
            dp[j] *= (1.0 - p[i]);
            if(j > 0)
                dp[j] += dp[j - 1] * p[i];
        }
    }
    double sum = 0;
    for(int i = 0; i <= L; ++i) sum += dp[i];
    printf("%.10f\n", 1 - sum);
    return 0;
}

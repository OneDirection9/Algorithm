#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>
#include <cstring>
#include <functional>

using namespace std;

typedef long long LL;

int main() {
    freopen("1.txt", "r", stdin);
    LL N;
    cin >> N; // N and N - 1 are relatively prime

    int res = 0;
    for(LL i = 2; i * i <= N - 1; ++i) {
        if((N - 1) % i == 0) {
            ++res;
            if(i * i != N - 1) ++res;
        }
    }
    if(N != 2) ++res; // N - 1;

    for(LL i = 2; i * i <= N; ++i) {
        if(N % i == 0) {
            LL n0 = N;
            while(n0 % i == 0) n0 /= i;
            if((n0 - 1) % i == 0) ++res;
        }
    }
    ++res;
    cout << res << endl;

    return 0;
}

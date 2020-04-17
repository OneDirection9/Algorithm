#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long LL;

int cnta[40010], cntb[40010];

void update(int *arr, int cnt) {
    for (int i = 1; i <= cnt; ++i) {
        arr[i] += cnt - i + 1;
    }
}

int main() {
    // freopen("1.txt", "r", stdin);
    int n, m, ab, cnt;
    LL k;
    cin >> n >> m >> k;

    memset(cnta, 0, sizeof(cnta));
    memset(cntb, 0, sizeof(cntb));

    cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> ab;
        if (ab == 1) {
            ++cnt;
        } else {
            update(cnta, cnt);
            cnt = 0;
        }
    }
    if (cnt) update(cnta, cnt);

    cnt = 0;
    for (int i = 0; i < m; ++i) {
        cin >> ab;
        if (ab == 1) {
            ++cnt;
        } else {
            update(cntb, cnt);
            cnt = 0;
        }
    }
    if (cnt) update(cntb, cnt);

    LL res = 0;
    for (int i = 1; i <= n; ++i) {
        if (k % i == 0 && k / i <= m) {
            res += 1LL * cnta[i] * cntb[k / i];
        }
    }
    cout << res << endl;

    return 0;
}

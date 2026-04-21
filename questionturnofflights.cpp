#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int l, int n, int k, const string& bulbs) {
    int ops = 0;
    for (int i = 0; i < n; ) {
        if (bulbs[i] == '1') {
            ops++;
            i += l; 
        } else {
            i++;
        }
        if (ops > k) return false;
    }
    return ops <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;
    string bulbs;
    cin >> bulbs;

    int low = 1, high = n, ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid, n, k, bulbs)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10000001;
int prime_count[MAXN];

void sieve() {
    for (int i = 2; i < MAXN; ++i) {
        if (prime_count[i] == 0) {
            for (int j = i; j < MAXN; j += i) {
                prime_count[j]++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        cin >> N;
        if (N == 1) {
            cout << 1 << "\n";
        } else {
            cout << (1LL << prime_count[N]) << "\n";
        }
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

string solve(int N, vector<int>& A) {

    sort(A.begin(), A.end(), greater<int>());

    long long alex_total = 0;
    long long bob_total = 0;
    set<int> consumed_sugar;
    bool alex_turn = true;

    for (int i = 0; i < N; ++i) {
        
        if (consumed_sugar.find(A[i]) == consumed_sugar.end()) {
            if (alex_turn) {
                alex_total += A[i];
            } else {
                bob_total += A[i];
            }
            consumed_sugar.insert(A[i]);
            alex_turn = !alex_turn; 
        }
    }

    if (alex_total > bob_total) return "Alex";
    else return "Bob";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        cout << solve(N, A) << endl;
    }
    return 0;
}

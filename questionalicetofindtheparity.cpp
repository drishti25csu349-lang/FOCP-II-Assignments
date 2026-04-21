#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> counts;
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        counts[A[i]]++;
    }

    vector<int> unique_sugar;
    for (auto const& [sugar, count] : counts) {
        unique_sugar.push_back(sugar);
    }
    sort(unique_sugar.rbegin(), unique_sugar.rend());

    long long alex_total = 0;
    long long bob_total = 0;
    bool alex_turn = true;

    for (int sugar : unique_sugar) {
        int available = counts[sugar];
        
      
        if (available >= 2) {
            alex_total += sugar;
            bob_total += sugar;
            
        } else if (available == 1) {
            if (alex_turn) {
                alex_total += sugar;
            } else {
                bob_total += sugar;
            }
            alex_turn = !alex_turn; 
        }
    }

    return (alex_total > bob_total) ? "Alex" : "Bob";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cout << solve() << endl;
    }
    return 0;
}


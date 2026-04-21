#include <iostream>

using namespace std;

int main() {
    long long L, R;
    if (!(cin >> L >> R)) return 0;

 
    long long odd_count;
    long long total_elements = R - L + 1;

    if (L % 2 != 0) {
       
        odd_count = (total_elements + 1) / 2;
    } else {
      
        odd_count = total_elements / 2;
    }

    if (odd_count % 2 == 0) {
        cout << "even" << endl;
    } else {
        cout << "odd" << endl;
    }

    return 0;
}

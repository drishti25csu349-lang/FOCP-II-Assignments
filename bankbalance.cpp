#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct account {
    int userid;
    int balance;
};

class Bank {
private:
    vector<account> accounts;

public:
    bool create(int x, int y) {
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i].userid == x) {
                accounts[i].balance += y;
                return false;
            }
        }
        account newacc;
        newacc.userid = x;
        newacc.balance = y;
        accounts.push_back(newacc);
        return true;
    }

    bool debit(int x, int y) {
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i].userid == x) {
                if (accounts[i].balance >= y) {
                    accounts[i].balance -= y;
                    return true;
                }
                return false;
            }
        }
        return false;
    }

    bool credit(int x, int y) {
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i].userid == x) {
                accounts[i].balance += y;
                return true;
            }
        }
        return false;
    }

    int balance(int x) {
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i].userid == x) {
                return accounts[i].balance;
            }
        }
        return -1;
    }
};

int main() {
    int q;
    if (!(cin >> q)) return 0;

    Bank b;

    for (int i = 0; i < q; i++) {
        string type;
        cin >> type;

        if (type == "CREATE") {
            int x, y;
            cin >> x >> y;
            if (b.create(x, y)) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        } 
        else if (type == "DEBIT") {
            int x, y;
            cin >> x >> y;
            if (b.debit(x, y)) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        } 
        else if (type == "CREDIT") {
            int x, y;
            cin >> x >> y;
            if (b.credit(x, y)) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        } 
        else if (type == "BALANCE") {
            int x;
            cin >> x;
            cout << b.balance(x) << endl;
        }
    }

    return 0;
}

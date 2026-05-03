#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct movie {
    int movieid;
    vector<int> bookedusers;
};

class MovieTicket {
private:
    vector<movie> movies;

    movie* findorcreatemovie(int y) {
        for (int i = 0; i < movies.size(); i++) {
            if (movies[i].movieid == y) {
                return &movies[i];
            }
        }
        movie newmovie;
        newmovie.movieid = y;
        movies.push_back(newmovie);
        return &movies.back();
    }

public:
    bool book(int x, int y) {
        movie* m = findorcreatemovie(y);
        
        for (int i = 0; i < m->bookedusers.size(); i++) {
            if (m->bookedusers[i] == x) {
                return false;
            }
        }
        
        if (m->bookedusers.size() >= 100) {
            return false;
        }
        
        m->bookedusers.push_back(x);
        return true;
    }

    bool cancel(int x, int y) {
        movie* m = findorcreatemovie(y);
        
        for (int i = 0; i < m->bookedusers.size(); i++) {
            if (m->bookedusers[i] == x) {
                m->bookedusers.erase(m->bookedusers.begin() + i);
                return true;
            }
        }
        return false;
    }

    bool is_booked(int x, int y) {
        movie* m = findorcreatemovie(y);
        
        for (int i = 0; i < m->bookedusers.size(); i++) {
            if (m->bookedusers[i] == x) {
                return true;
            }
        }
        return false;
    }

    int available_tickets(int y) {
        movie* m = findorcreatemovie(y);
        return 100 - m->bookedusers.size();
    }
};

int main() {
    int q;
    if (!(cin >> q)) return 0;

    MovieTicket mt;

    for (int i = 0; i < q; i++) {
        string type;
        cin >> type;

        if (type == "BOOK") {
            int x, y;
            cin >> x >> y;
            if (mt.book(x, y)) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        } 
        else if (type == "CANCEL") {
            int x, y;
            cin >> x >> y;
            if (mt.cancel(x, y)) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        } 
        else if (type == "IS_BOOKED") {
            int x, y;
            cin >> x >> y;
            if (mt.is_booked(x, y)) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        } 
        else if (type == "AVAILABLE_TICKETS") {
            int y;
            cin >> y;
            cout << mt.available_tickets(y) << endl;
        }
    }

    return 0;
}

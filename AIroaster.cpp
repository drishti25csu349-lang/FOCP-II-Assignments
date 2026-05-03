#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct roastentry {
    vector<string> templates;
};

class RoastGenerator {
private:
    roastentry data;

public:
    RoastGenerator() {
        data.templates.push_back("{name} writes code so slow that even a turtle switched to Python.");
        data.templates.push_back("If procrastination were an Olympic sport, {name} would already have a gold medal.");
        data.templates.push_back("{name}'s debugging style is basically staring at the screen until the bug gets embarrassed and leaves.");
        data.templates.push_back("{name}'s code runs so slowly that even dial-up internet feels fast.");
        data.templates.push_back("If laziness had a brand ambassador, it would be {name}.");
        data.templates.push_back("{name} doesn't debug code -- they negotiate with bugs.");
        data.templates.push_back("{name} thinks a bug is just an undocumented feature.");
        data.templates.push_back("If you look closely at {name}'s code, you can hear the processor sighing.");
        data.templates.push_back("{name} is the reason why computers need a 'rest' button.");
        data.templates.push_back("{name}'s code compiles only because the compiler is feeling generous today.");
    }

    void generateroast(string name) {
        if (name.empty()) {
            cout << "A name is required to generate a roast." << endl;
            return;
        }

        int index = rand() % data.templates.size();
        string selectedroast = data.templates[index];

        string placeholder = "{name}";
        size_t pos = selectedroast.find(placeholder);
        
        while (pos != string::npos) {
            selectedroast.replace(pos, placeholder.length(), name);
            pos = selectedroast.find(placeholder, pos + name.length());
        }

        cout << selectedroast << endl;
    }
};

int main() {
    srand(time(0));
    
    RoastGenerator rg;
    string username;
    
    cout << "Enter your name: ";
    getline(cin, username);
    
    rg.generateroast(username);
    
    return 0;
}

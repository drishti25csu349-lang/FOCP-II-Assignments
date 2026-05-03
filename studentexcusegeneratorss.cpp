#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct excusedata {
    vector<string> templates;
};

class ExcuseGenerator {
private:
    excusedata data;

public:
    ExcuseGenerator() {
        data.templates.push_back("{name} couldn't finish the assignment because the laptop decided to install updates for six hours.");
        data.templates.push_back("{name} was about to complete the homework when the Wi-Fi mysteriously disappeared.");
        data.templates.push_back("{name} tried finishing the assignment, but the computer keyboard suddenly stopped cooperating.");
        data.templates.push_back("{name} couldn't complete the assignment because the laptop battery died unexpectedly.");
        data.templates.push_back("{name} tried finishing the homework, but the internet stopped working.");
        data.templates.push_back("{name} was ready to submit the assignment when the file mysteriously disappeared.");
        data.templates.push_back("The dog chewed through {name}'s charger right when the assignment was 99% done.");
        data.templates.push_back("{name}'s operating system crashed and deleted the entire homework folder.");
        data.templates.push_back("{name} spent all night typing the assignment only for the power to go out before saving.");
        data.templates.push_back("A rogue browser tab froze {name}'s computer, wiping out all the assignment progress.");
    }

    void generateexcuse(string name) {
        if (name.empty()) {
            cout << "A name is required to generate an excuse." << endl;
            return;
        }

        int index = rand() % data.templates.size();
        string selectedexcuse = data.templates[index];

        string placeholder = "{name}";
        size_t pos = selectedexcuse.find(placeholder);
        
        while (pos != string::npos) {
            selectedexcuse.replace(pos, placeholder.length(), name);
            pos = selectedexcuse.find(placeholder, pos + name.length());
        }

        cout << selectedexcuse << endl;
    }
};

int main() {
    srand(time(0));
    
    ExcuseGenerator eg;
    string username;
    
    cout << "Enter student name: ";
    getline(cin, username);
    
    eg.generateexcuse(username);
    
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct excusedata {
    vector<string> templates;
};

class ExcuseGenerator {
private:
    excusedata data;

public:
    ExcuseGenerator() {
        data.templates.push_back("{name} couldn't finish the assignment because the laptop decided to install updates for six hours.");
        data.templates.push_back("{name} was about to complete the homework when the Wi-Fi mysteriously disappeared.");
        data.templates.push_back("{name} tried finishing the assignment, but the computer keyboard suddenly stopped cooperating.");
        data.templates.push_back("{name} couldn't complete the assignment because the laptop battery died unexpectedly.");
        data.templates.push_back("{name} tried finishing the homework, but the internet stopped working.");
        data.templates.push_back("{name} was ready to submit the assignment when the file mysteriously disappeared.");
        data.templates.push_back("The dog chewed through {name}'s charger right when the assignment was 99% done.");
        data.templates.push_back("{name}'s operating system crashed and deleted the entire homework folder.");
        data.templates.push_back("{name} spent all night typing the assignment only for the power to go out before saving.");
        data.templates.push_back("A rogue browser tab froze {name}'s computer, wiping out all the assignment progress.");
    }

    void generateexcuse(string name) {
        if (name.empty()) {
            cout << "A name is required to generate an excuse." << endl;
            return;
        }

        int index = rand() % data.templates.size();
        string selectedexcuse = data.templates[index];

        string placeholder = "{name}";
        size_t pos = selectedexcuse.find(placeholder);
        
        while (pos != string::npos) {
            selectedexcuse.replace(pos, placeholder.length(), name);
            pos = selectedexcuse.find(placeholder, pos + name.length());
        }

        cout << selectedexcuse << endl;
    }
};

int main() {
    srand(time(0));
    
    ExcuseGenerator eg;
    string username;
    
    cout << "Enter student name: ";
    getline(cin, username);
    
    eg.generateexcuse(username);
    
    return 0;
}

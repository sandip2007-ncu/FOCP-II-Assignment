// ============================================================
//  AIRoastGenerator.cpp
//  A console program that generates funny roasts based on name
//  Developed using AI (Claude) - Vibe Coding Assignment
// ============================================================
 
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()
#include <algorithm> // for find()
 
using namespace std;
 
// ----------------------------------------------------------
// Function: replacePlaceholder
// Replaces every occurrence of {name} in a template string
// with the actual user-provided name.
// ----------------------------------------------------------
string replacePlaceholder(string templ, const string& name) {
    const string placeholder = "{name}";
    size_t pos = 0;
    // Keep replacing until no more occurrences are found
    while ((pos = templ.find(placeholder, pos)) != string::npos) {
        templ.replace(pos, placeholder.length(), name);
        pos += name.length(); // advance past the inserted name
    }
    return templ;
}
 
// ----------------------------------------------------------
// Function: getRandomRoast
// Picks a random index that is different from the last one
// used, so consecutive runs always feel fresh.
// ----------------------------------------------------------
int getRandomRoast(int total, int lastIndex) {
    if (total == 1) return 0; // edge-case: only one template
    int idx;
    do {
        idx = rand() % total;
    } while (idx == lastIndex);
    return idx;
}
 
int main() {
    // Seed the random-number generator with the current time
    // so we get different results every run
    srand(static_cast<unsigned int>(time(nullptr)));
 
    // ----------------------------------------------------------
    // Roast template store (10 templates)
    // Use {name} as the placeholder for the user's name
    // ----------------------------------------------------------
    vector<string> roastTemplates = {
        "{name}'s code runs so slowly that even dial-up internet feels fast.",
        "If laziness had a brand ambassador, it would be {name}.",
        "{name} doesn't debug code — they negotiate with bugs.",
        "{name} writes code so slow that even a turtle switched to Python.",
        "If procrastination were an Olympic sport, {name} would already have a gold medal.",
        "{name}'s debugging style is basically staring at the screen until the bug gets embarrassed and leaves.",
        "Scientists studied {name}'s commit history and declared it a public health hazard.",
        "{name} asked ChatGPT for help and even the AI said 'I need a moment'.",
        "Rumour has it {name}'s first program printed 'Hello World' — three days later.",
        "{name} once used a for-loop to make a cup of tea. It never finished iterating."
    };
 
    // ----------------------------------------------------------
    // Input handling — guard against empty names
    // ----------------------------------------------------------
    string userName;
    cout << "========================================\n";
    cout << "       Welcome to the AI Roast Generator\n";
    cout << "========================================\n\n";
 
    cout << "Enter your name to get roasted: ";
    getline(cin, userName);
 
    // Bug fix: handle empty input gracefully
    if (userName.empty()) {
        cout << "\n[Error] You must enter a name to be roasted!\n";
        cout << "Please restart the program and try again.\n";
        return 1;
    }
 
    // ----------------------------------------------------------
    // Generate and display the roast
    // ----------------------------------------------------------
    int roastIndex = getRandomRoast(static_cast<int>(roastTemplates.size()), -1);
    string roast   = replacePlaceholder(roastTemplates[roastIndex], userName);
 
    cout << "\n🔥 ROAST OF THE DAY 🔥\n";
    cout << "----------------------------------------\n";
    cout << roast << "\n";
    cout << "----------------------------------------\n\n";
 
    // Optional: ask user if they want another roast
    char again = 'y';
    int  lastIndex = roastIndex;
 
    while (again == 'y' || again == 'Y') {
        cout << "Want another roast? (y/n): ";
        cin >> again;
        cin.ignore(); // clear newline from buffer
 
        if (again == 'y' || again == 'Y') {
            roastIndex = getRandomRoast(static_cast<int>(roastTemplates.size()), lastIndex);
            roast      = replacePlaceholder(roastTemplates[roastIndex], userName);
            lastIndex  = roastIndex;
 
            cout << "\n🔥 BONUS ROAST 🔥\n";
            cout << "----------------------------------------\n";
            cout << roast << "\n";
            cout << "----------------------------------------\n\n";
        }
    }
 
    cout << "\nThanks for playing! No feelings were permanently harmed.\n\n";
    return 0;
}
 

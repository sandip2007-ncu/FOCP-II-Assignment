// ============================================================
//  HomeworkExcuseGenerator.cpp
//  A console program that generates creative homework excuses
//  Developed using AI (Claude) - Vibe Coding Assignment
// ============================================================
 
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()
 
using namespace std;
 
// ----------------------------------------------------------
// Function: replacePlaceholder
// Replaces every occurrence of {name} in a template string
// with the actual user-provided name.
// ----------------------------------------------------------
string replacePlaceholder(string templ, const string& name) {
    const string placeholder = "{name}";
    size_t pos = 0;
    while ((pos = templ.find(placeholder, pos)) != string::npos) {
        templ.replace(pos, placeholder.length(), name);
        pos += name.length();
    }
    return templ;
}
 
// ----------------------------------------------------------
// Function: getRandomExcuse
// Picks a random index different from the last one used,
// so the same excuse never appears twice in a row.
// ----------------------------------------------------------
int getRandomExcuse(int total, int lastIndex) {
    if (total == 1) return 0;
    int idx;
    do {
        idx = rand() % total;
    } while (idx == lastIndex);
    return idx;
}
 
int main() {
    // Seed random number generator so results differ every run
    srand(static_cast<unsigned int>(time(nullptr)));
 
    // ----------------------------------------------------------
    // Excuse template store (10 templates)
    // {name} will be replaced with the actual student name
    // ----------------------------------------------------------
    vector<string> excuseTemplates = {
        "{name} couldn't complete the assignment because the laptop decided to install updates for six hours.",
        "{name} was about to submit the homework when the Wi-Fi mysteriously disappeared.",
        "{name} tried finishing the assignment, but the computer keyboard suddenly stopped cooperating.",
        "{name} had the homework fully written out, but the dog mistook it for a chew toy.",
        "{name} was ready to submit when the file vanished — probably stolen by a rogue cloud backup.",
        "{name} couldn't finish because the power went out exactly three minutes before the deadline.",
        "{name} spent four hours on the assignment, then accidentally saved it in a folder that no longer exists.",
        "{name} was going to submit last night, but got stuck in a two-hour loop of 'just one more YouTube video'.",
        "{name}'s printer ran out of ink, then paper, then the will to live.",
        "{name} completed the assignment but the submission portal said 'file too large' — it was a Word doc.",
        "{name} tried to email the assignment but autocorrect changed the teacher's address to a pizza place.",
        "{name} was working hard until the laptop screen went black and never came back on."
    };
 
    // ----------------------------------------------------------
    // Input — guard against empty names
    // ----------------------------------------------------------
    string studentName;
 
    cout << "==========================================\n";
    cout << "   Welcome to the Homework Excuse Generator\n";
    cout << "==========================================\n\n";
 
    cout << "Enter your name: ";
    getline(cin, studentName);   // getline handles full names with spaces
 
    // Bug fix: handle empty input gracefully
    if (studentName.empty()) {
        cout << "\n[Error] Name cannot be empty!\n";
        cout << "Please restart and enter your name.\n";
        return 1;
    }
 
    // ----------------------------------------------------------
    // Generate and display the excuse
    // ----------------------------------------------------------
    int excuseIndex = getRandomExcuse(static_cast<int>(excuseTemplates.size()), -1);
    string excuse   = replacePlaceholder(excuseTemplates[excuseIndex], studentName);
 
    cout << "\n📋 YOUR HOMEWORK EXCUSE 📋\n";
    cout << "------------------------------------------\n";
    cout << excuse << "\n";
    cout << "------------------------------------------\n\n";
 
    // ----------------------------------------------------------
    // Optional loop — ask if user wants another excuse
    // ----------------------------------------------------------
    char again = 'y';
    int  lastIndex = excuseIndex;
 
    while (again == 'y' || again == 'Y') {
        cout << "Want another excuse? (y/n): ";
        cin >> again;
        cin.ignore(); // clear leftover newline from buffer
 
        if (again == 'y' || again == 'Y') {
            excuseIndex = getRandomExcuse(static_cast<int>(excuseTemplates.size()), lastIndex);
            excuse      = replacePlaceholder(excuseTemplates[excuseIndex], studentName);
            lastIndex   = excuseIndex;
 
            cout << "\n📋 ANOTHER EXCUSE 📋\n";
            cout << "------------------------------------------\n";
            cout << excuse << "\n";
            cout << "------------------------------------------\n\n";
        }
    }
 
    cout << "\nGood luck explaining this to your teacher!\n\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, unordered_set<string>> movie_customers; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    while (q--) {
        string op;
        cin >> op;

        if (op == "BOOK") {
            string x, y;
            cin >> x >> y;
            if (movie_customers[y].count(x) || movie_customers[y].size() >= 100)
                cout << "false\n";
            else {
                movie_customers[y].insert(x);
                cout << "true\n";
            }
        } else if (op == "CANCEL") {
            string x, y;
            cin >> x >> y;
            cout << (movie_customers[y].erase(x) ? "true" : "false") << "\n";
        } else if (op == "IS_BOOKED") {
            string x, y;
            cin >> x >> y;
            cout << (movie_customers[y].count(x) ? "true" : "false") << "\n";
        } else {
            string y;
            cin >> y;
            cout << 100 - (int)movie_customers[y].size() << "\n";
        }
    }
    return 0;
}

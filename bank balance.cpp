#include <bits/stdc++.h>
using namespace std;

unordered_map<string, long long> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    while (q--) {
        string op, x;
        long long y;
        cin >> op >> x;

        if (op == "BALANCE") {
            cout << (mp.count(x) ? mp[x] : -1) << "\n";
        } else {
            cin >> y;
            if (op == "CREATE") {
                cout << (mp.count(x) ? "false" : "true") << "\n";
                mp[x] += y;
            } else if (op == "DEBIT") {
                cout << (mp.count(x) && mp[x] >= y ? (mp[x] -= y, "true") : "false") << "\n";
            } else {
                cout << (mp.count(x) ? (mp[x] += y, "true") : "false") << "\n";
            }
        }
    }
    return 0;
}

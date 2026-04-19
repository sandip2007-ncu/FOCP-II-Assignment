#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end(), greater<int>());

        long long alex = 0, bob = 0;
        int prev = 1000000000;

        for(int i = 0; i < n; i++) {

            int current = min(a[i], prev - 1);

            if(current <= 0)
                break;

            if(i % 2 == 0)
                alex += current;
            else
                bob += current;

            prev = current;
        }

        if(alex > bob)
            cout << "Alex\n";
        else
            cout << "Bob\n";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int Max = 10000000;
int primenumberCount[Max + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 2; i <= Max; i++) {
        if(primenumberCount[i] == 0) { 
            for(int j = i; j <= Max; j += i) {
                primenumberCount[j]++;
            }
        }
    }

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        cout << (1 << primenumberCount[n]) << "\n";
    }

    return 0;
}

#include <iostream>
using namespace std;

bool turnOff(string bulbs, int n, int k, int x) {
    int ope = 0;

    for (int i = 0; i < n; ) {
        if (bulbs[i] == '1') {
            ope++;
            if (ope > k)
                return false;

            for (int j = i; j < i + x && j < n; j++)
                bulbs[j] = '0';

            i += x;
        } else {
            i++;
        }
    }

    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    string bulbs;
    cin >> bulbs;

    int left = 1, right = n, ans = n;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (turnOff(bulbs, n, k, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
}


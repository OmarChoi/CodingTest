#include <iostream>
#include <cmath>
#include <array>

using namespace std;

constexpr int Max = 100'000'1;
array<bool, Max> primeArr;

void SetPrime()
{
    primeArr.fill(true);
    primeArr[0] = primeArr[1] = false;

    for (int i = 2; i <= sqrt(Max); ++i) {
        if (primeArr[i] == false) continue;
        for (int j = i * 2; j < Max; j = j + i) {
            primeArr[j] = false;
        }
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    SetPrime();

    int nTestCase = 0;
    cin >> nTestCase;

    while (nTestCase > 0) {
        nTestCase -= 1;

        int target = 0;
        cin >> target;

        int answer = 0;
        for (int i = 2; i <= (target / 2); ++i) {
            if (primeArr[i] && primeArr[target - i]) {
                answer += 1;
            }
        }

        cout << answer << "\n";
    }
}

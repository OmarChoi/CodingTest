#include <iostream>
#include <array>
#include <math.h>

using namespace std;

#define MaxNum 250'000

array<bool, 250'000> PrimeArray;
void InitPrimeArr() {
    for (int i = 2; i <= sqrt(MaxNum); ++i) {
        if (PrimeArray[i] == false) continue;
        for (int j = i * 2; j < MaxNum; j = j + i) {
            PrimeArray[j] = false;
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    fill(PrimeArray.begin(), PrimeArray.end(), true);
    InitPrimeArr();
    while (true) {
        int inputNum;
        cin >> inputNum;

        if (inputNum == 0)
            break;

        int nPrimeNum = 0;
        for (int i = inputNum + 1; i <= 2 * inputNum; ++i) {
            if (PrimeArray[i] == true)
                nPrimeNum += 1;
        }
        cout << nPrimeNum << "\n";
    }
}

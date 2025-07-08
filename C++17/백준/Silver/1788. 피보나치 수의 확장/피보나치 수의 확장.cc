#include <iostream>
using namespace std;

constexpr int MAX_NUM = 100'000'1;
int PlusFibo[MAX_NUM];
int MinusFibo[MAX_NUM];

void PrintNum(int i) {
    int result = 0;
    if (i == 0) {
        cout << "0\n";
    }
    else if (i > 0) {
        cout << "1\n";
        result = i;
    }
    else {
        cout << "-1\n";
        result = -i;
    }
    cout << result << "\n";
}

int main() {
    PlusFibo[0] = 0; PlusFibo[1] = 1;
    MinusFibo[0] = 0; MinusFibo[1] = 1;
    for(int i = 2; i < MAX_NUM; ++i) {
        PlusFibo[i] = (PlusFibo[i - 2] + PlusFibo[i - 1]) % 1'000'000'000;
        MinusFibo[i] = (MinusFibo[i - 2] - MinusFibo[i - 1]) % 1'000'000'000;
    }
    int targetNum;
    cin >> targetNum;
    
    if (targetNum < 0) 
        PrintNum(MinusFibo[-targetNum]);
    else 
        PrintNum(PlusFibo[targetNum]);
}
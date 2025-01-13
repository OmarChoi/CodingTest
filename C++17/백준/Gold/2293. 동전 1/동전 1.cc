#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nCoin, targetWon;
    cin >> nCoin >> targetWon;

    vector<int> dp(targetWon + 1, 0);
    vector<int> coins(nCoin);
    for (int i = 0; i < nCoin; ++i) {
        cin >> coins[i];
    }
    dp[0] = 1;

    for (int i = 0; i < nCoin; ++i) {
        for (int j = coins[i]; j <= targetWon; ++j) {
            // 기존에 저장된 값에 i번째 코인을 추가로 사용했을 때,
            // 나올 수 있는 경우의 수를 더해준다.
            dp[j] += dp[j - coins[i]];
        }
    }
    cout << dp[targetWon];
}

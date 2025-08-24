#include <iostream>
#include <vector>

using namespace std;

int N, M;

int CalSquare(const vector<string>& board) {
    int maxLength = min(N, M);
    // 한 변의 크기가 K은 정사각형을 순차적으로 탐색
    for (int k = maxLength; k > 0; --k) {
        for (int j = 0; j + k - 1 < N; ++j) {
            for (int i = 0; i + k - 1 < M; ++i) {
                char a = board[j][i];
                if (board[j][i + k - 1] == a &&
                    board[j + k - 1][i] == a &&
                    board[j + k - 1][i + k - 1] == a) {
                    return k * k;
                }
            }
        }
    }
    return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    vector<string> board(N);
    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }

    cout << CalSquare(board);
}

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// right, up, left, down
int dy[4] = { 0 ,-1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };
int N = 0;

bool IsValid(int y, int x) {
	if (y < 0 || y >= N) {
		return false;
	}

	if (x < 0 || x >= N) {
		return false;
	}

	return true;
}

void MakeBoard(int y1, int x1, int y2, int x2, 
	std::vector<std::vector<int>>& board) {

	int dir = 0;
	int dirCount = 0;
	int nChangeDir = 0;
	
	int count = 1;
	int currY = N / 2;
	int currX = N / 2;

	while (true) {
		if (IsValid(currY, currX) == false) {
			break;
		}
        
        // 출력 범위 내에 있을 경우에만 저장
		if ((currY >= y1 && currY <= y2) && 
			(currX >= x1 && currX <= x2)) {
			int y = currY - y1;
			int x = currX - x1;
			board[y][x] = count;
		}

        // 한 칸 이동
		currY = currY + dy[dir];
		currX = currX + dx[dir];
		count += 1;
		dirCount += 1;

		// 방향 전환 기준 (1, 1, 2, 2, 3, 3, 4, 4, ...)
		int maxChange = nChangeDir / 2 + 1;
        
        // 방향 전환
		if (dirCount == maxChange) {
			dir = (dir + 1) % 4;
			dirCount = 0;
			nChangeDir += 1;
		}

	}
}

void PrintRegion(int y1, int x1, int y2, int x2,
	const std::vector<std::vector<int>>& board) {
	
	// 자릿수 출력을 위한 최대 길이 
	int l1 = std::to_string(*(*board.begin()).begin()).length();
	int l2 = std::to_string(*(*board.rbegin()).rbegin()).length();
	int max = (l1 > l2) ? l1 : l2;
	
	for (const auto& r : board) {
		for (int c : r) {
			std::cout << std::setw(max) << std::right << c << ' ';
		}
		cout << "\n";
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	// 입력된 숫자 중 절댓값이 가장 큰 숫자 크기를 한 변으로 하는 정사각형 구하기
	
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	int yDist = r2 - r1;
	int xDist = c2 - c1;
	int m = std::max({ std::abs(r1), std::abs(c1), std::abs(r2), std::abs(c2) });
	N = m * 2 + 1;
	r1 += m; r2 += m; c1 += m; c2 += m;
	
	std::vector<std::vector<int>> board(yDist + 1, std::vector<int>(xDist + 1));
	MakeBoard(r1, c1, r2, c2, board);
	PrintRegion(r1, c1, r2, c2, board);
}

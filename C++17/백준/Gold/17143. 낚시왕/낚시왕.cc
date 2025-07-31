#include <iostream>
#include <map>
#include <array>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Shark;
class Board;

int Height, Width, nShark;
unordered_map<int, Shark*> sharks;
Board* board; // 해당 위치 상어의 Index

enum class Direction {
	Up = 0,
	Down = 1,
	Right = 2,
	Left = 3
};

class Shark
{
public:
	Shark(int i, int y, int x, int sp, int d, int sc) : index(i), yPos(y), xPos(x), speed(sp),
		dir(static_cast<Direction>(d)), score(sc) {};

public:
	void Update() {
		Move();
	}

	int GetScore() const { return score; }
	int GetIndex() const { return index; }
	pair<int, int> GetPos() const { return make_pair(yPos, xPos); }

private:
	void Move();

	void ChangeDirection() {
		switch (dir) {
		case Direction::Up:		dir = Direction::Down;	break;
		case Direction::Down:	dir = Direction::Up;	break;
		case Direction::Left:	dir = Direction::Right;	break;
		case Direction::Right:	dir = Direction::Left;	break;
		}
	}

private:
	int index;
	int yPos;
	int xPos;
	int speed;
	int score;
	Direction dir;
};

class Board
{
public:
	Board(int h, int w) : height(h), width(w) {
		currBoard.resize(Width);
	};

	void AddShark(const Shark* shark) {
		auto Pos = shark->GetPos();
		// 해당 좌표에 이미 상어가 있으면 작은 상어 삭제
		auto it = currBoard[Pos.second].find(Pos.first);
		if (it != currBoard[Pos.second].end()) {
			int prevIdx = it->second;
			auto sh = sharks.find(prevIdx);
			if (sh == sharks.end()) {
				std::cout << "Error : Shark Doesn't Exist\n";
				return;
			}
			if (sh->second->GetScore() < shark->GetScore()) {
				it->second = shark->GetIndex();
				eraseList.emplace(sh->second->GetIndex());
			}
			else {
				eraseList.emplace(shark->GetIndex());
			}
		}
		else {
			currBoard[Pos.second].emplace(Pos.first, shark->GetIndex());
		}
	}

	void RemoveShark() {
		for (int i : eraseList) {
			auto it = sharks.find(i);
			if (it == sharks.end()) {
				continue;
			}
			sharks.erase(it);
		}
		eraseList.clear();
	}

	int GetNearestShark(int xPos) {
		// 해당 열에 있는 가장 가까운 상어 삭제
		if (currBoard[xPos].size() == 0) return 0;
		int index = currBoard[xPos].begin()->second;
		auto it = sharks.find(index);
		if (it == sharks.end()) {
			std::cout << "Error : Shark Doesn't Exist\n";
			return -1;
		}
		int score = it->second->GetScore();
		sharks.erase(it);
		return score;
	}

	void ClearBoard() {
		for (auto& s : currBoard) {
			s.clear();
		}
	}

	bool CanGo(const int yPos, const int xPos) {
		if (yPos < 0 || yPos >= Height) return false;
		if (xPos < 0 || xPos >= Width) return false;
		return true;
	}

private:
	int height;
	int width;
	vector<map<int, int>> currBoard;		// 같은 열 기준으로 yPos - Index 데이터 추가
	unordered_set<int> eraseList;
};

class Player
{
public:
	void Update() {
		Move();
		CatchShark();
	}

	int GetScore() { return score; }

private:
	void Move() {
		xPos += 1;
	}

	void CatchShark() {
		score += board->GetNearestShark(xPos);
	}

private:
	int xPos{ -1 };
	int score{ 0 };
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> Height >> Width >> nShark;
	board = new Board(Height, Width);
	Player* player = new Player();

	for (int i = 0; i < nShark; ++i) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		Shark* sh = new Shark(i, r - 1, c - 1, s, d - 1, z);
		sharks.emplace(i, sh);
		board->AddShark(sh);
	}

	for (int i = 0; i < Width; ++i) {
		player->Update();
		board->ClearBoard();
		for (auto& sh : sharks) {
			sh.second->Update();
		}
		board->RemoveShark();
	}

	cout << player->GetScore();
}

void Shark::Move() {
	bool vertical = (dir == Direction::Up || dir == Direction::Down);
	int limit = vertical ? (Height - 1) : (Width - 1);
	int cycle = 2 * limit;	// 왕복 1바퀴 이동 후 제자리(시작과 같은 방향을 바라보며)로 돌아오는 경우
	int s = speed % cycle;	// Cycle만큼 이동하는 것은 제자리로 돌아오는 것이기 때문에 제외하고 나머지만 처리하면 된다.

	int nextPos;
	if (vertical) {
		nextPos = (dir == Direction::Down ? yPos + s : yPos - s);
	}
	else {
		nextPos = (dir == Direction::Right ? xPos + s : xPos - s);
	}

	nextPos = (nextPos % cycle + cycle) % cycle;
	if (nextPos > limit) {
		nextPos = cycle - nextPos;
		ChangeDirection();
	}

	if (vertical) {
		yPos = nextPos;
	}
	else {
		xPos = nextPos;
	}

	board->AddShark(this);
}
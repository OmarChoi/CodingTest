#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class IRoom
{
public:
	int cost;
	vector<int> nextRoomIndex;

	IRoom(int c) : cost(c) {}

	virtual void EnterRoom(int& currMoney) const = 0;
	void SetNextRoom(int roomIndex) { nextRoomIndex.emplace_back(roomIndex); }
};

class LepRoom : public IRoom
{
public:
	LepRoom(int c) : IRoom(c) {}

	void EnterRoom(int& currMoney) const override
	{
		if (currMoney < cost) {
			currMoney = cost;
		}
	}
};

class TrollRoom : public IRoom
{
public:
	TrollRoom(int c) : IRoom(c) {}
	void EnterRoom(int& currMoney) const override
	{
		currMoney -= cost;
	}
};

class EmptyRoom : public IRoom
{
public:
	EmptyRoom(int c) : IRoom(c) {}
	void EnterRoom(int& currMoney) const override {}
};

void ProcessInput(int nRoom, IRoom** rooms)
{
	for (int i = 1; i < nRoom; ++i)
	{
		char RoomType;
		cin >> RoomType;

		int cost;
		cin >> cost;

		switch (RoomType)
		{
		case 'E':
			rooms[i] = new EmptyRoom(cost);
			break;
		case 'L':
			rooms[i] = new LepRoom(cost);
			break;
		case 'T':
			rooms[i] = new TrollRoom(cost);
			break;
		}

		while (true)
		{
			int nextRoom = 0;
			cin >> nextRoom;
			if (nextRoom == 0)
				break;
			rooms[i]->SetNextRoom(nextRoom);
		}
	}
}

void DFS(IRoom** rooms, vector<bool>& visit, 
	int roomIndex, int currMoney, const int targetRoom)
{
	if (roomIndex > targetRoom) return;
	if (visit[roomIndex] == true) return;

	rooms[roomIndex]->EnterRoom(currMoney);
	if (currMoney < 0) return;

	visit[roomIndex] = true;
	if (visit[targetRoom] == true) return;
	
	for (int i : rooms[roomIndex]->nextRoomIndex)
	{
		if (visit[i] == true) continue;
		DFS(rooms, visit, i, currMoney, targetRoom);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) 
	{
		int targetRoom = 0;
		cin >> targetRoom;
		if (targetRoom == 0) break;

		IRoom** rooms = new IRoom* [targetRoom + 1];
		vector<bool> visit(targetRoom + 1, false);
		ProcessInput(targetRoom + 1, rooms);

		DFS(rooms, visit, 1, 0, targetRoom);
		
		if (visit[targetRoom])
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
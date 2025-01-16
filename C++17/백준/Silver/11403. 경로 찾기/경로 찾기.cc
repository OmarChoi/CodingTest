#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<bool>& reachable, const vector<vector<bool>>& connectVec, int index)
{
    for (int i = 0; i < connectVec[index].size(); ++i)
    {
        // i번째 정점과 현재 정점이 연결되어 있으면 DFS 탐색 실행
        if (connectVec[index][i] == true)
        {
            // 연결되어 있는 정점 중에 이미 방문한적 있는 경우 체크
            if (reachable[i] == true) continue;
            reachable[i] = true;
            DFS(reachable, connectVec, i);
        }
    }
}

void PrintAnswer(const vector<vector<bool>>& answer)
{
    for (const vector<bool>& vec : answer)
    {
        for (const bool b : vec)
            cout << b << " ";
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nVertex = 0;
    cin >> nVertex;

    vector<vector<bool>> connectVec(nVertex, vector<bool>(nVertex, false));

    for (int j = 0; j < nVertex; ++j) 
    {
        for (int i = 0; i < nVertex; ++i) 
        {
            bool connected = false;
            cin >> connected;
            connectVec[j][i] = connected;
        }
    }

    vector<vector<bool>> reachable(nVertex, vector<bool>(nVertex, false));
    for (int i = 0; i < nVertex; ++i)
        DFS(reachable[i], connectVec, i);

    PrintAnswer(reachable);
}
#include <iostream>
#include <vector>

using namespace std;

vector<int> numVec;
vector<int> increaseVec;

int SearchIndex(int value) 
{
    int startIndex = 0;
    int endIndex = increaseVec.size();

    while (startIndex < endIndex)
    {
        int midIndex = (startIndex + endIndex) / 2;
        if (increaseVec[midIndex] < value)
            startIndex = midIndex + 1;
        else
            endIndex = midIndex;
    }

    return endIndex;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nNum = 0;
    cin >> nNum;

    numVec.resize(nNum);
    increaseVec.reserve(nNum);

    for (int i = 0; i < nNum; ++i)
    {
        cin >> numVec[i];
    }
    
    increaseVec.emplace_back(numVec[0]);

    for (int i = 1; i < nNum; ++i) 
    {
        if (numVec[i] <= *increaseVec.rbegin())
        {
            int idx = SearchIndex(numVec[i]);
            increaseVec[idx] = numVec[i];
        }
        else
        {
            increaseVec.emplace_back(numVec[i]);
        }
    }

    cout << increaseVec.size();
}
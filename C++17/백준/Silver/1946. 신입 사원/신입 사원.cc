#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nTestCase;
    cin >> nTestCase;
    int testCount = 0;
    while (testCount < nTestCase) 
    {
        int nPerson;
        cin >> nPerson;
        int count = nPerson;
        vector<pair<int, int>> scoreVec(nPerson);

        for (int i = 0; i < nPerson; ++i)
        {
            cin >> scoreVec[i].first >> scoreVec[i].second;
        }

        sort(scoreVec.begin(), scoreVec.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first < b.first;
            });

        int highestScore = scoreVec[0].second;
        for (int i = 1; i < nPerson; ++i) 
        {
            if (highestScore > scoreVec[i].second)
                highestScore = scoreVec[i].second;
            else
                count -= 1;
        }

        cout << count << endl;
        testCount += 1;
    }
}
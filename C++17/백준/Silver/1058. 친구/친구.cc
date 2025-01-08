#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nPerson;
    cin >> nPerson;

    vector<vector<int>> connection(nPerson);
    vector<bool> alreadyFriend(nPerson, false);
    vector<int> nFriends(nPerson, 0);

    for (int i = 0; i < nPerson; ++i) {
        connection[i].reserve(nPerson);
        for (int j = 0; j < nPerson; ++j) {
            char isFriend;
            cin >> isFriend;
            if (isFriend == 'Y')
                connection[i].emplace_back(j);
        }
    }

    for (int i = 0; i < nPerson; ++i) {
        fill(alreadyFriend.begin(), alreadyFriend.end(), false);
        alreadyFriend[i] = true;
        for (int j : connection[i]) {
            alreadyFriend[j] = true;
            for (int k : connection[j]) {
                if (k == i) continue;
                if (alreadyFriend[k] == true) continue;
                alreadyFriend[k] = true;
            }
        }
        for (bool b : alreadyFriend) {
            if (b) nFriends[i] += 1;
        }
        nFriends[i] -= 1;
    }

    cout << *max_element(nFriends.begin(), nFriends.end());
}
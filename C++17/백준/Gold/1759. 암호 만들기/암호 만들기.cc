#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int passLength, nWord;
bool IsVower(const char alphabet)
{
    return (alphabet == 'a' || alphabet == 'e' || alphabet == 'i' 
        || alphabet == 'o' || alphabet == 'u');
}

void DFS(const vector<char>& words, int index, string password, int vowels, int consonants)
{
    password += words[index];

    if (IsVower(words[index]))
        vowels += 1;
    else
        consonants += 1;

    if (password.size() == passLength)
    {
        if (vowels >= 1 && consonants >= 2)
            cout << password << "\n";
        return;
    }

    for (int i = index + 1; i < nWord; ++i)
    {
        DFS(words, i, password, vowels, consonants);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> passLength >> nWord;

    vector<char> wordVec(nWord);
    for (int i = 0; i < nWord; ++i)
        cin >> wordVec[i];

    sort(wordVec.begin(), wordVec.end());

    for (int i = 0; i < nWord; ++i)
    {
        string passWord = "";
        DFS(wordVec, i, passWord, 0, 0);
    }
}
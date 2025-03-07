#include <string>
#include <vector>

using namespace std;

class Trie
{
private:
    Trie* nextWord[26];
    int nWord;

public:
    Trie() : nWord(0) {
        fill(nextWord, nextWord + 26, nullptr);
    }

    ~Trie() {
        for (Trie* trie : nextWord) {
            if (trie != nullptr)
                delete trie;
        }
    }

    void Insert(const char* word) {
        if (*word != 0) {
            int next = *word - 'a';
            if (nextWord[next] == nullptr) {
                nextWord[next] = new Trie();
            }
            nextWord[next]->Insert(word + 1);
        }
        nWord += 1;
    }

    int Find(const string& word, int idx) {
        if (word.length() == idx || nWord == 1) {
            return idx;
        }
        int next = word[idx] - 'a';
        return nextWord[next]->Find(word, idx + 1);
    }
};

int solution(vector<string> words) {
    int answer = 0;
    Trie Root;
    for (string word : words) {
        Root.Insert(word.c_str());
    }
    for (string word : words) {
        answer += Root.Find(word, 0);
    }
    return answer;
}

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool IsFirst = true;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ' ') {
            IsFirst = true;
            continue;
        }
        if (IsFirst) {
            if (islower(s[i])) {
                s[i] = toupper(s[i]);
            }
            IsFirst = false;
        }
        else if (isupper(s[i])) {
            s[i] = tolower(s[i]);
        }
    }
    return s;
}
#include <string>
#include <vector>
#include <array>
#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

unordered_map<string, string> nickName;
class Log
{
public:
    string userID;
    string func;
    
    Log(string f, string uid) : func(f), userID(uid) {};
    
    string GetLog() const {
        if (func == "Leave") {
            return nickName[userID] + "님이 나갔습니다.";
        }
        else {
            return nickName[userID] + "님이 들어왔습니다.";
        }
    }
};

void ProcessRecord(const string& str, array<string, 3>& arr) {
    istringstream ss(str);
    string tempStr;
    int index = 0;
    while (getline(ss, tempStr, ' ')) {
        arr[index++] = tempStr;
    }
}

void RecordLog(const array<string, 3>& arr, vector<Log>& logVec) {
    if (arr[0] == "Enter") {
        nickName[arr[1]] = arr[2];
        logVec.emplace_back(arr[0], arr[1]);
    }
    else if (arr[0] == "Leave") {
        logVec.emplace_back(arr[0], arr[1]);
    }
    else {
        nickName[arr[1]] = arr[2];
    }
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<Log> logVec;
    
    for (const string& str : record) {
        array<string, 3> strArr;
        ProcessRecord(str, strArr);
        RecordLog(strArr, logVec);
    }
    
    for (const Log& l : logVec) {
        answer.emplace_back(l.GetLog());
    }
    
    return answer;
}
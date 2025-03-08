#include <string>
#include <vector>
#include <array>
#include <stack>
#include <math.h>
#include <map>
#include <iostream>

using namespace std;

int ConvertTime(int hour, int minuate) {
    return hour * 60 + minuate;
}

class Car
{
public:
    stack<int> timeLog;
    int logCount = 0;
    int parkingTime = 0;
    
    void AddLog(int hour, int minuate) {
        timeLog.emplace(ConvertTime(hour, minuate));
        logCount += 1;
    }
    
    void CalculateParkingTime() {
        if (logCount % 2 == 1) {
            timeLog.emplace(ConvertTime(23, 59));
        }
        
        while (!timeLog.empty()) {
            int outTime = timeLog.top();
            timeLog.pop();
            int inTime = timeLog.top();
            timeLog.pop();
            
            parkingTime += (outTime - inTime);
        }
    }
    
    int CalculateFee(int defaultTime, int defaultFee, int  unitTime, int unitFee) {
        CalculateParkingTime();
        if (parkingTime <= defaultTime) {
            return defaultFee;
        }
        else {
            return defaultFee + ceil((static_cast<float>(parkingTime) - defaultTime) / unitTime) * unitFee;
        }
    }
};

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int, Car> carMap;
    for (const string& str : records) {
        int hour = stoi(str.substr(0, 2));
        int minuate = stoi(str.substr(3, 2));
        int carNum = stoi(str.substr(6, 4));
        string type = str.substr(11);
        carMap[carNum].AddLog(hour, minuate);
    }
    
    for(auto i = carMap.begin(); i != carMap.end(); ++i) {
        int fee = (*i).second.CalculateFee(fees[0], fees[1], fees[2], fees[3]);
        answer.emplace_back(fee);
    }
    
    return answer;
}
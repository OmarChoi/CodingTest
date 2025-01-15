#include <iostream>
#include <queue>
#include <deque>
#include <string>

using namespace std;

void InputOperators(queue<char>& acOpers)
{
    string opers = "";
    cin >> opers;

    for (char c : opers)
    {
        acOpers.emplace(c);
    }
}

void InputNumbers(deque<int>& numbers)
{
    int nNum;
    cin >> nNum;

    string inputNums = "";
    cin >> inputNums;

    string num = "";
    for (int i = 1; i < inputNums.length() - 1; ++i)
    {
        if (inputNums[i] == ',')
        {
            numbers.emplace_back(stoi(num));
            num = "";
        }
        else 
            num += inputNums[i];
    }

    if(num != "")
        numbers.emplace_back(stoi(num));
}

void PrintResult(const deque<int>& nums, bool IsForward)
{
    if (nums.size() == 0)
    {
        cout << "[]\n";
        return;
    }

    cout << "[";
    if (IsForward == true)
    {
        for (int i = 0; i < nums.size() - 1; ++i) 
            cout << nums[i] << ",";
        cout << *nums.rbegin() << "]\n";
    }
    else
    {
        for (int i = nums.size() - 1; i > 0; --i)
            cout << nums[i] << ",";
        cout << *nums.begin() << "]\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nTestCase;
    cin >> nTestCase;

    for (int k = 0; k < nTestCase; ++k) 
    {
        queue<char> acOpers;
        InputOperators(acOpers);

        deque<int> numbers;
        InputNumbers(numbers);
        
        bool IsForward = true;
        bool IsError = false;

        while (acOpers.empty() == false)
        {
            char currentOper = acOpers.front();
            acOpers.pop();

            if (currentOper == 'R') 
                IsForward = !IsForward;
            else if (currentOper == 'D') 
            {
                if (numbers.size() == 0) 
                {
                    IsError = true;
                    break;
                }

                if (IsForward == true)
                    numbers.pop_front();
                else
                    numbers.pop_back();
            }
        }

        if (IsError == false)
            PrintResult(numbers, IsForward);
        else
            cout << "error\n";
    }
}
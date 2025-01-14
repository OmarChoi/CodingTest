#include <iostream>
#include <vector>

using namespace std;

enum OP 
{
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    OPERATOR_NUM
};

vector<int> numbers;
int minValue = 100'000'000'0, maxValue = -100'000'000'0;

void ExecOperator(vector<int>& AvaiableOperator, OP oper, int index, int sum)
{
    AvaiableOperator[oper] -= 1;
    switch (oper) 
    {
    case OP::PLUS:
        sum += numbers[index];
        break;
    case OP::MINUS:
        sum -= numbers[index];
        break;
    case OP::MULTIPLY:
        sum *= numbers[index];
        break;
    case OP::DIVIDE:
        if (numbers[index] != 0)
            sum /= numbers[index];
        else 
        {
            cout << "Divide By Zero.\n";
            AvaiableOperator[oper] += 1;
            return;
        }
        break;
    }

    if (index == numbers.size() - 1)
    {
        // 마지막 값까지 연산이 끝났을 때
        if (sum > maxValue)
            maxValue = sum;
        if (sum < minValue)
            minValue = sum;
        AvaiableOperator[oper] += 1;
        return;
    }

    for (int i = 0; i < OP::OPERATOR_NUM; ++i)
    {
        if (AvaiableOperator[i] == 0) continue;
        ExecOperator(AvaiableOperator, static_cast<OP>(i), index + 1, sum);
    }
        
    // vector<int>의 &을 인자로 제공받기 때문에
    // 사용했던 Operator의 횟수를 돌아가면서 다시 추가해준다.
    AvaiableOperator[oper] += 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> nOperatorVec = vector<int>(OP::OPERATOR_NUM);
    vector<int> AvailableOperator(OP::OPERATOR_NUM, 0);

    int nNum = 0;
    cin >> nNum;
    numbers = vector<int>(nNum);

    for (int i = 0; i < nNum; ++i)
        cin >> numbers[i];

    for (int i = 0; i < OP::OPERATOR_NUM; ++i) 
    {
        cin >> nOperatorVec[i];
        AvailableOperator[i] = nOperatorVec[i];
    }

    for (int i = 0; i < OP::OPERATOR_NUM; ++i)
    {
        for (int i = 0; i < OP::OPERATOR_NUM; ++i)
            AvailableOperator[i] = nOperatorVec[i];
        if (AvailableOperator[i] == 0) continue;
        ExecOperator(AvailableOperator, static_cast<OP>(i), 1, numbers[0]);
    }
    cout << maxValue << "\n" << minValue << "\n";
}
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

class Date
{
public:
	int month;
	int day;

	Date() : month(0), day(0) {}
	Date(int m, int d) : month(m), day(d) {}

	bool operator > (const Date& rhs) const {
		if (month == rhs.month) {
			return day > rhs.day;
		}
		return month > rhs.month;
	}

	bool operator < (const Date& rhs) const {
		if (month == rhs.month) {
			return day < rhs.day;
		}
		return month < rhs.month;
	}

	bool operator <= (const Date& rhs) const {
		if (month == rhs.month) {
			return day <= rhs.day;
		}
		return month <= rhs.month;
	}
	
	Date& operator = (const Date& rhs) {
		month = rhs.month;
		day = rhs.day;
		return *this;
	}

	bool operator == (const Date& rhs) const {
		return (month == rhs.month) && (day == rhs.day);
	}

	bool operator != (const Date& rhs) const {
		return !(*this == rhs);
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	// 꽃이 피는 날짜를 기준으로 정렬
	// 꽃이 지는 날짜 전에 피는 꽃들 중에 가장 길게 피는 꽃 찾기

	int nFlower;
	std::cin >> nFlower;

	std::vector<std::pair<Date, Date>> flowers(nFlower);	// 피는 날짜, 지는 날짜

	for (auto& [start, end] : flowers) {
		std::cin >> start.month >> start.day >> end.month >> end.day;
	}

	std::sort(flowers.begin(), flowers.end(), 
		[](const std::pair<Date, Date>& a, const std::pair<Date, Date>& b) {
			// 시작 월이 빠른(작은) 순서
			if (a.first != b.first) {
				return a.first < b.first;
			}

			// 종료일이 늦은 순서
			if (a.second != b.second) {
				return a.second > b.second;
			}

			return false;
		});

	Date lastDate{ 3, 1 };	// 꽃이 피는 것이 보장되지 않은 첫번째 날
	Date endDate;
	int answer = 0;
	for (const auto& [start, end] : flowers) {
		if (start.month >= 12) {
			break;
		}

		// 꽃이 이미 포함된 영역에서 피고 지는 경우
		if (end < lastDate) {
			continue;
		}

		// 시작 지점이 영역 내에 있고 끝 지점이 last보다 뒤에 있으면 끝점 비교
		if (start <= lastDate) {
			if (endDate < end) {
				endDate = end;
			}
		}
		
		if (start > lastDate) {
			// 현재 꽃 이전까지의 꽃 중에서 제일 오래 살아 있는 꽃 선택
			// 해당 꽃을 기준으로 lastDate갱신
			if (start > endDate) {
				break;
			}

			if (endDate.month >= 12) {
				break;
			}
			answer += 1;
			lastDate = endDate;
			// 현재 꽃부터 다시 last를 넘지 않을 때까지 꽃 확인
			endDate = end;
		}
	}

	// 마지막에 피어있는 꽃 선택
	answer += 1;

	if (endDate.month < 12) {
		std::cout << "0";
	}
	else {
		std::cout << answer;
	}
}

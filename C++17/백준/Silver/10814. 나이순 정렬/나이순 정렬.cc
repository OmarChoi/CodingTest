#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int32_t nPerson;
	std::cin >> nPerson;

	std::vector<std::tuple<int, int, std::string>> person;	// age, index, name (비교 순서대로 삽입)
	person.reserve(nPerson);

	for (int i = 0; i < nPerson; ++i) {
		int32_t age;
		std::string name;
		std::cin >> age >> name;
		person.emplace_back(age, i, std::move(name));
	}

	std::sort(person.begin(), person.end());

	for (const auto& p : person) {
		std::cout << std::get<0>(p) << " " << std::get<2>(p) << "\n";
	}
}

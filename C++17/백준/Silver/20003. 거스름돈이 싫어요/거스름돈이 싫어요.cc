#include <iostream>
#include <numeric>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int nItem = 0;
	cin >> nItem;

	int64_t gcd = 0;
	int64_t lcm = 1;

	for (int i = 0; i < nItem; ++i) {
		int c, p;
		cin >> c >> p;

		int64_t g = std::gcd(c, p);
		int64_t child = c / g;
		int64_t parent = p / g;

		gcd = (i == 0) ? child : std::gcd(gcd, child);
		lcm = std::lcm(lcm, parent);
	}

	int64_t g = std::gcd(gcd, lcm);
	cout << (gcd / g) << ' ' << (lcm / g) << '\n';
}

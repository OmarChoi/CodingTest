#include <iostream>
#include <vector>

using namespace std;

int gcd(long long a, long long b)
{
	if (b == 0) {
		return a;
	}
	else {
		return (gcd(b, a % b));
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long num[2] = { 0, 0 };
	cin >> num[0] >> num[1];
	long long result = gcd(num[0], num[1]);

	for (int i = 0; i < result; ++i) {
		cout << 1;
	}
}
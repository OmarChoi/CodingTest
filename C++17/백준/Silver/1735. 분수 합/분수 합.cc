#include <iostream>
#include <array>

using namespace std;

constexpr int nNum = 2;
int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	array<array<int, 2>, nNum> nums;
	long long denominator = 1;
	long long numerator = 0;
	for (int i = 0; i < nNum; ++i) {
		cin >> nums[i][0] >> nums[i][1];
		denominator *= nums[i][1];
	}

	int n = gcd(nums[0][1], nums[1][1]);
	denominator /= n;

	for (int i = 0; i < nNum; ++i) {
		numerator += nums[i][0] * denominator / nums[i][1];
	}

	n = gcd(numerator, denominator);
	cout << numerator / n << " " << denominator / n;
}


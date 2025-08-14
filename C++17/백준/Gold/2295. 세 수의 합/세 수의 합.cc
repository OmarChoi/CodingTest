#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int64_t Search(const int32_t n, const vector<int64_t>& nums, const set<int32_t>& sumSet) {
    for (int j = n - 1; j >= 0; --j) {
        int64_t target = nums[j];
        for (const int32_t i : sumSet) {
            int64_t rem = target - i;
            int64_t rev = *lower_bound(nums.begin(), nums.end(), rem);
            if (rev == rem) {
                return target;
            }
        }
    }
    return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int32_t n;
    cin >> n;
    vector<int64_t> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    set<int32_t> sumSet;
    for (int j = 0; j < n; ++j) {
        for (int i = j; i < n; ++i) {
            sumSet.emplace(nums[i] + nums[j]);
        }
    }
    cout << Search(n, nums, sumSet);
}

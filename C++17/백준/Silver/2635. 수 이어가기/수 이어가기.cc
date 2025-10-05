#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	int n;
	std::cin >> n;

	size_t max = 0;
	std::vector<int> best;
    best.reserve(20);

    for (int i = n; i >= n / 2; --i) {
        std::vector<int> seq = { n, i };

        while (true) {
            int nxt = seq[seq.size() - 2] - seq.back();
            if (nxt < 0) {
                break;
            }
            seq.emplace_back(nxt);
        }

        if (seq.size() > max) {
            max = seq.size();
            best = std::move(seq);
        }
    }

    std::cout << max << "\n";
    for (int i : best) {
        std::cout << i << " ";
    }
}

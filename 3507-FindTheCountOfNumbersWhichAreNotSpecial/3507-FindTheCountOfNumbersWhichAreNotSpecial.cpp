// Last updated: 9/24/2025, 2:15:23 AM
class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int sqrtR = sqrt(r);
        vector<bool> is_prime(sqrtR + 1, true);
        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i * i <= sqrtR; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= sqrtR; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        set<long long> prime_squares;
        for (int i = 2; i <= sqrtR; i++) {
            if (is_prime[i]) {
                long long square = (long long)i * i;
                if (square >= l && square <= r) {
                    prime_squares.insert(square);
                }
            }
        }

        return (r - l + 1) - prime_squares.size();
    }
};
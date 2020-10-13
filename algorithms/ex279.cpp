#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        assert(n >= 1);
        if (n == 1) return 1;
        vector<int> dp(n+1);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            // vector<int> tmp;
            int min = 1000000;
            for (int k = 1; i - k * k >= 0; ++k) {
                if (i - k * k == 0)  {
                    dp[i] = 1;
                    break;
                } else {
                    min = (min < dp[i - k * k] + 1) ? min : dp[i - k * k] + 1;
                    dp[i] = min;
                }
            }
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    for (int i = 1; i <= 20; ++i) {
        cout << i << " : " << s.numSquares(i) << endl;
    }
    system("PAUSE");
    return 0;
}
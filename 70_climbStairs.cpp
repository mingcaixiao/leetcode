#include <vector>
#include <iostream>


class Solution {
public:
    int climbStairs(int n) {
        /// init
        std::vector<int> dp(n + 1, 0);
        if(n == 1)
            return 1;
        else
            dp[1] = 1;
        if(n == 2)
            return 2;
        else
            dp[2] = 2;
        for(int i = 3; i <= n; ++i){
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }
};


// class Solution {
// public:
//     int climbStairs(int n) {
//         /// init
//         if(1 == n) return 1;
//         if(2 == n) return 2;
//         return climbStairs(n - 1) + climbStairs(n - 2);
//     }
// };
int main()
{
    Solution s;
    std::cout << s.climbStairs(45) <<std::endl;
    return 1;
}
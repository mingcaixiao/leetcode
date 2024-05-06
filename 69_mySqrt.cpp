#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        if(x == 1) return 1;
        while(left + 1 < right){
            int middle = ((long long)left + (long long)right) / 2;
            if((long long)middle * (long long)middle <= (long long)x)left = middle;
            else right = middle;
        }
        return left;
    }
};


int main(){
    Solution s;
    std::cout << s.mySqrt(1) << std::endl;
    return 1;
}
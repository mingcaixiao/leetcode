#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        std::vector<int> result;
        int n = digits.size();
        result.resize(n + 1);
        int carry = 1;
        int i = 0;
        for(auto it = digits.rbegin(); it != digits.rend(); ++it){
            result[n - i] = (*it + carry) % 10;
            carry = (*it + carry) == 10 ? 1 : 0;
            ++i;
        }
        result[0] = carry;
        if(result.front() == 0) result.erase(result.begin());
        return result;
    }
};

void print(const std::vector<int>& d){
    for(auto i: d){
        std::cout << i;
    }
    std::cout << std::endl;
}

int main(){
    Solution s;
    print(s.plusOne(std::vector<int>{9,8,7,6,5,4,3,2,1,0}));
    return 1;
}
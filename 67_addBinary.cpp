#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        std::string result;
        int m = a.size(), n = b.size();
        result.reserve(m > n ? m + 1 : n + 1);
        int i = 1;
        int carry = 0;
        while(i <= m && i <= n){
            int sum = a[m - i] - '0' + b[n - i] - '0' + carry;
            int r = sum % 2;
            result += r + '0';
            carry = sum / 2;
            ++i; 
        }
        while(i <= m){
            int sum = a[m - i] - '0' + carry;
            int r = sum % 2;
            carry = sum / 2;
            result += r + '0';
            ++i;
        }
        while(i <= n){
            int sum = b[n - i] - '0' + carry;
            int r = sum % 2;
            carry = sum / 2;
            result += r + '0';
            ++i;
        }
        if(carry != 0) result += carry + '0';
        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main(){
    Solution s;
    std::cout << s.addBinary("1", "111") << std::endl;
    return 1;
}
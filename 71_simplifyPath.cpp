#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        std::stack<string> stk;
        size_t path_size = path.size();
        size_t i = 0, j = 1;
        while(i < path_size && j < path.size()){
            while(j < path_size && path[j] != '/'){ // find next '/'
                ++j;
            }
            std::string dir_string = path.substr(i + 1, j - i - 1);
            i = j;
            ++j;
            if(dir_string == "")continue;
            if(dir_string != std::string(".")){
                if(dir_string == std::string("..")){
                    if(!stk.empty())
                        stk.pop();
                }else 
                    stk.push(dir_string);
            }
        }
        std::vector<string> r;
        r.reserve(2 * stk.size());
        while(!stk.empty()){
            r.push_back(stk.top());
            r.push_back("/");
            stk.pop();
        }
        std::reverse(r.begin(), r.end());
        if(r.empty()) return "/";
        if(r.back() == "/") r.pop_back();
        std::string result;
        for(auto&str: r){
            result += str;
        }
        return result;
    }
};

int main()
{
    Solution s;
    // std::cout << s.simplifyPath("/a/./b/../../c/") <<std::endl;
    // std::cout << s.simplifyPath("/home/") <<std::endl;
    // std::cout << s.simplifyPath("/../") <<std::endl;
    // std::cout << s.simplifyPath("/home//foo/") <<std::endl;
    // std::cout << s.simplifyPath("/.../a/../b/c/../d/./") <<std::endl;
    // std::cout << s.simplifyPath("/../") <<std::endl;
    std::cout << s.simplifyPath("/") <<std::endl;
    return 1; 
}
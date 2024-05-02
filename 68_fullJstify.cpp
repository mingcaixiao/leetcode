#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int rightIndex = 0;
        int n = words.size();
        std::vector<string> result;
        while(rightIndex < n){
            int sumLen = 0;
            int newRightIndex = n;
            for(int i = rightIndex; i < n; ++i){
                sumLen += words[i].size() + 1;
                if(sumLen > maxWidth + 1){
                    newRightIndex = i;
                    break;
                }
            }
            int numWords = newRightIndex - rightIndex;

            int wordsLen = 0;
            for(int j = rightIndex; j < rightIndex + numWords; ++j){
                wordsLen += words[j].size();
            }
            int numSpaces = (maxWidth - wordsLen);
            
            //last line
            if(newRightIndex >= n){
                std::string cur_string;
                for(int j = 0; j < numWords; ++j){
                    if(j < numWords - 1)
                        cur_string += (words[j + rightIndex] + ' ');
                    else
                        cur_string += (words[j + rightIndex] + std::string(numSpaces - (numWords - 1), ' '));
                }
                result.push_back(cur_string);
            }else if(numWords == 1){  //just one word
                result.push_back(words[rightIndex] + std::string(numSpaces, ' '));
            }
            else{
                int numSpacesPerGap =  numSpaces / (numWords - 1);
                int numExtra = numSpaces % (numWords - 1);
                std::string curLine = "";
                for(int j = 0; j < numWords; ++j){
                    int spacesCount = j < numExtra ? numSpacesPerGap + 1 : numSpacesPerGap;
                    if(j < numWords - 1)
                        curLine += words[j + rightIndex] + std::string(spacesCount, ' ');
                    else
                        curLine += words[j + rightIndex];     
                }
                result.push_back(curLine);
            }
            rightIndex = newRightIndex;
        }
        return result;
    }
};


int main(){
    Solution s;
    // auto result = s.fullJustify(std::vector<string>{"This", "is", "an", "example", "of", "text", "justification."}, 16);
    // auto result = s.fullJustify(std::vector<string>{"What","must","be","acknowledgment","shall","be"}, 16);
    auto result = s.fullJustify(std::vector<string>{"Science","is","what","we","understand","well","enough","to",
        "explain","to","a","computer.","Art","is","everything","else","we","do"}, 20);
    for(auto str: result){
        std::cout <<"\"" << str << "\"" << std::endl;
    }
    return 1;
}
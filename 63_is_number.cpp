#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    enum State{
        Initial,
        IntSign,
        Int,
        Point,
        PointWithoutInt,
        Fraction,
        Exp,
        ExpSign,
        ExpNumber
    };

    enum CharType{
        NUMBER,
        EXP,
        POINT,
        SIGN,
        ILLEGAL
    };

    CharType GetCharType(char ch){
        if(ch >= '0' && ch <= '9'){
            return CharType::NUMBER;
        }else if(ch == 'e' || ch == 'E'){
            return CharType::EXP;
        }else if(ch == '+' || ch == '-'){
            return CharType::SIGN;
        }else if(ch == '.'){
            return CharType::POINT;
        }else{
            return CharType::ILLEGAL;
        }
    }

    bool isNumber(string s) {
        std::unordered_map<State, std::unordered_map<CharType, State>> transfer;
        transfer.insert({State::Initial, 
            std::unordered_map<CharType, State>{
                {CharType::NUMBER, State::Int}, 
                {CharType::POINT, State::PointWithoutInt},
                {CharType::SIGN, State::IntSign}}
            });
        transfer.insert({State::IntSign,
            std::unordered_map<CharType, State>{
                {CharType::NUMBER, State::Int},
                {CharType::POINT, State::PointWithoutInt}}
            });
        transfer.insert({State::Int, 
            std::unordered_map<CharType, State>{
                {CharType::NUMBER, State::Int},
                {CharType::POINT, State::Point},
                {CharType::EXP, State::Exp}}
            });
        transfer.insert({State::Point, 
            std::unordered_map<CharType, State>{
                {CharType::NUMBER, State::Fraction},
                {CharType::EXP, State::Exp}}
            });

        transfer.insert({State::PointWithoutInt, 
            std::unordered_map<CharType, State>{
                {CharType::NUMBER, State::Fraction}}
            });
        transfer.insert({State::Fraction, 
            std::unordered_map<CharType, State>{
                {CharType::EXP, State::Exp},
                {CharType::NUMBER, State::Fraction}}
            });
        transfer.insert({State::Exp, 
            std::unordered_map<CharType, State>{
                {CharType::SIGN, State::ExpSign},
                {CharType::NUMBER, State::ExpNumber}}
            });
        transfer.insert({State::ExpSign,
            std::unordered_map<CharType, State>{
                {CharType::NUMBER, State::ExpNumber}}
            });
        transfer.insert({State::ExpNumber, 
            std::unordered_map<CharType, State>{
                {CharType::NUMBER, State::ExpNumber}}
            });
        State st = State::Initial;

        for(char& ch:s){
            CharType chType = GetCharType(ch);
            if(transfer[st].find(chType) == transfer[st].end()) return false;
            st = transfer[st][chType];
        }
        return st == State::Int || st == State::Point || st == Fraction || st == ExpNumber;
    }
};

int main(){
    Solution s;
    std::cout << s.isNumber("2e0") << std::endl;
}
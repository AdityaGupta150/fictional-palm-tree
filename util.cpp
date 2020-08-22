#include "util.h"
#include "thisMath.h"
#include<iostream>
#include<list>
#include<string>
#include<algorithm>

namespace util
{

    bool replace_all(const std::string& oldVal, const std::string& newVal,std::string& s){
        size_t start = s.find(oldVal);

        if(start == std::string::npos){
            return false;   //oldval not found
        }
        while (start != std::string::npos)
        {
            s.replace(start, oldVal.size(), newVal);
            start = s.find(oldVal);
        }

        return true;
    }

    void trimZeroes(std::string &s){
        while (s.back() == '0')
        {
            s.pop_back();
        }
        if(s.back() == '.'){
            s.pop_back();
        }
    }

    class InvalidQueryException : public std::exception{
        public:
            const char* what(){
                return "Invalid query!";
            }
    };

    std::string evaluate(std::string& q){
        double a, b;
        //better trim q here -> NO NEED, std::stod already ignores whitespaces
        for(size_t i =0; i<q.size(); ++i){
            if( supportedOpr.find(q[i]) != supportedOpr.end() ){
                try{
                    a = std::stod(q.substr(0, i));
                    b = std::stod(q.substr(i+1));
                }catch(std::invalid_argument& e){
                    std::cerr<<e.what()<<"\nAt location "<<i<<" in query: "<<q<<std::endl;
                    throw InvalidQueryException();
                }

                return std::to_string(mathFunc.at(q[i])(a, b));
            }
        }

        return "";  //The query is simply ignored, if it doesn't throw exception and is wrong
    }

        //what this validate() is doing, now, is same as simple calculator, and that can be more easily implemented in just a single O(n) i believe,
            //But the advantage of this move is likely that here even BODMAS maybe implemented
    bool validator(std::string& s){
            //check if numOpening == numClosing Brackets
        int netBracket = 0;
        util::replace_all("**", "P", s);  //needs lvalue holding references
        for (auto &&c : s)
        {
            if(c=='(')  ++netBracket;
            else if(c==')') --netBracket;
            if(netBracket<0) return false; //should never be negative, logically
        }

        std::list<size_t> lastOpen, countOpr;
        for (size_t i = 0; i < s.size(); i++)
        {
            if(s[i] == '('){
                lastOpen.push_back(i);
                countOpr.push_back(0);
            }else if (s[i] == ')')
            {
                lastOpen.pop_back();
                countOpr.pop_back();
            }else if (supportedOpr.find(s[i]) != supportedOpr.end())
            {
                if(countOpr.back()>0){
                        //can also do using iterator, in that case we can insert a char directly
                    s.insert(lastOpen.back() + 1, "("); //Insert open bracket just after last Open bracket
                    s.insert(i+1, ")");

                    countOpr.back() = 0;
                    
                    i+=2;   //i shifted 2 positions, since two new characters inserted
                }

                ++countOpr.back();  //accounting for the current operation encountered
            }
            
        }
        
        return true;
    }
    
} // namespace util

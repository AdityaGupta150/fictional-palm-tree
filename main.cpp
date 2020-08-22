#include<iostream>
#include<list>
#include<string>
#include "thisMath.h"
#include "util.h"

using namespace std;

#define DEBUG false

#if (DEBUG)
    #include"thisDebug.hpp"
#endif

int main(){
    string (*eval)(string&) = util::evaluate;

    string s, smallerQuery, result;
    std::list<int> lastPos;

    if(DEBUG)   s = "982.45*34-87.452 + 23 - ( 23**2 ) + ( 9* (45.67 / 9))";
    else{
        cout<<"Enter something: ";
        getline(cin, s);
    }
    s.insert(s.begin(), '(');
    s.push_back(')');
    try{
        if(!util::validator(s)){
            cerr<<"Check your query and try again!"<<endl;
            return -1;
        }
        if(DEBUG) clog<<"Interpreted expression: "<<s<<'\n';

        for(long i =0 ; i<s.size(); ++i){
            if(s[i] == '('){
                lastPos.push_back(i);
            }else if(s[i] == ')'){
                //substr(start, count) -> [start, start+count)      !!WARNING -> 2nd param is not `end`
                smallerQuery = s.substr(lastPos.back()+1, i-(lastPos.back()+1));      
                result = eval(smallerQuery);
                if(DEBUG){
                    clog<<"Query picked is: "<<smallerQuery<<". Evaluates to: "<<result<<'\n';
                }
                s.replace(lastPos.back(), i+1-lastPos.back(), result);    //replace(start, count)     //similar to substr()... BUT, it has another form using iterators as well -> replace(sIter, eIter)            
                i = lastPos.back() + result.size() - 2;
                    // i >= 0 + -2
                if(i<-1)    i=-1;

                lastPos.pop_back();
            }
        }

    }catch(InvalidQueryException& e){
        cerr<<e.what()<<endl;
        return -1;
    }

    util::trimZeroes(s);
    cout<<s<<endl;

    return 0;
}

/*
. From C++11, data() and c_str() perform the same function.

. For unordered_set->
Internally, the elements are not sorted in any particular order, but organized into buckets. Which bucket an element is placed into depends entirely on the hash of its value. This allows fast access to individual elements, since once a hash is computed, it refers to the exact bucket the element is placed into.
Container `elements may not be modified` (even by non const iterators) since modification could change an element's hash and corrupt the container.

unordered_set::contains() has been introduced in C++20  WHOOH... itna late!
    Before that, use find() != .end()
*/
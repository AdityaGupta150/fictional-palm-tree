#pragma once

#include<cmath>
#include<unordered_map>
#include<unordered_set>

typedef unsigned long long ull;
typedef double (*mathPtr)(double, double);

inline double add(double a, double b){ return a+b; }
inline double subtract(double a, double b){ return a-b; }
inline double multiply(double a, double b){ return a*b; }
inline double divide(double a, double b){ return a/b; }

inline std::unordered_map<char, mathPtr> mathFunc = {
    {'+', add},
    {'A', add},
    {'-', subtract},
    {'S', subtract},
    {'*', multiply},
    {'M', multiply},
    {'/', divide},
    {'D', divide},
    {'\\', divide},
    {'%', fmod},
    {'P', pow},
    {'^', pow}
};
inline std::unordered_set<char> supportedOpr = {'+', 'A', '-', 'S', '*', 'M', '/', '\\', 'D', '%', '^', 'P'};

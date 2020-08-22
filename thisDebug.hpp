#pragma once

#include<iostream>
#include<string>

void printDebug(const std::string& s, int loc){  //For use with gdb, instead of two print i, print s commands we can directly call print printDebug(s,i)
    std::cout<<s<<std::endl;
    for (unsigned i = 0; i < loc; i++)
    {
        std::cout<<' ';
    }
    std::cout<<'|'<<std::endl;   
}

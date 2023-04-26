#pragma once

#include <iostream>
#include <cstring>
template<typename T>
T mult(T a,T b){
    return a * b;
}
template<>
std::string mult<std::string>(std::string a,std::string b){
    return a + " " + b;
}
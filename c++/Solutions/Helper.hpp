#pragma once

#include <algorithm>
#include <vector>

namespace Common
{

template<typename T, typename T2>
void showData(T data)
{
    std::for_each(data.begin(),data.end(),[](T2 &element){std::cout<<element<<" ";});
    std::cout<<"\n";
}
}
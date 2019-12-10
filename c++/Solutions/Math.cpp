#include "Math.hpp"

namespace Pow
{
    double Solution::myPowTimeOut(double x, int n)
    {
        if (n == 0)
            return 1;
        if (n < 0)
        {
            x = 1/x;
            n = 0 - n;
        }
        double result = x;
        for (auto i =1; i < n; i++)
        {
            result = result * x;
        }
        return result;   
    }
    double Solution::myPow(double x, int n)
    {
        if (0 == n)
            return 1;
        if (1 == n)
        {
            return x;
        }
        if (-1 == n)
        {
            return 1/x;
        }
        double half = myPow(x, n/2);
        double rest = myPow(x, n%2);
        return half * half * rest;   
    }
}
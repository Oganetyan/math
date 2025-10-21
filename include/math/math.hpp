#pragma once

#include <stdexcept>

namespace math
{
    constexpr double PI = 3.14159265358979323846264338327950288;
    constexpr double E = 2.71828182845904523536028747135266250;
    constexpr double PHI = 1.61803398874989484820458683436563812;

    double abs(double x)
    {
        if (x < 0)
        {
            x *= (-1);
        }
        return x;
    }

    int sign(double x)
    {
        if (x > 0)
        {
            return 1;
        }
        else if (x == 0)
        {
            return 0;
        }
        else
            return -1;
    }

    double max(double x, double y)
    {
        if (x > y)
        {
            return x;
        }
        else if (x < y)
        {
            return y;
        }
        else
            return x;
    }

    double min(double x, double y)
    {
        if (x > y)
        {
            return y;
        }
        else if (x < y)
        {
            return x;
        }
        else
            return x;
    }

    double remainder(double x, double y)
    {
        if (y == 0.0)
            return 0.0;

        return x - static_cast<int>(x / y) * y;
    }

    double normalize(double x)
    {

        return remainder(x, 2 * PI);
    }

    int factorial(int x)
    {
        int res = 0;
        for (int i = 1; i <= x; ++i)
            res *= i;

        return res;
    }

    double sin(double x)
    {
        x = normalize(x);
        double sq = x * x;
        double temp = x, res = temp;
        for (int i = 1; i < 20; ++i)
        {
            temp *= -sq / ((2 * i) * (2 * i + 1));
            res += temp;
        }
        return res;
    }

    double cos(double x)
    {
        x = normalize(x);
        double sq = x * x;
        double temp = 1;
        double res = temp;
        for (int i = 1; i < 20; ++i)
        {
            temp *= -sq / ((2 * i) * (2 * i - 1));
            res += temp;
        }
        return res;
    }

    double tan(double x)
    {
        return sin(x) / cos(x);
    }

    double exp(double x)
    {
        double sq = x * x;
        double temp = 1;
        double res = temp;
        for (int i = 1; i < 20; ++i)
        {
            temp *= x / i;
            res += temp;
        }
        return res;
    }

    double ln(double x)
    {
        if (x <= 0)
            throw std::domain_error("ln(x) requires x > 0 ");

        if (x < 0.5 || x > 2)
        {
            int count = 0;
            while (x > 2)
            {
                count++;
                x /= 2;
            }
            while (x < 0.5)
            {
                count--;
                x *= 2;
            }
            return ln(x) + count * ln(2.0);
        }
        else
        {
            double temp = x - 1;
            double res = temp;
            for (int i = 2; i < 100; i++)
            {
                temp *= -(x - 1);
                res += temp / i;
            }
            return res;
        }
    }

    double pow(double x, double y)
    {
        return exp(y * ln(x));
    }

    double log(double x, double y)
    {
        return ln(y) / ln(x);
    }

} // namespace math
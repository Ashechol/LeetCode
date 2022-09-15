// Created by Ashechol on 2022/9/14.
// 69. x 的平方根
// 题目链接：https://leetcode.cn/problems/sqrtx/
// 题解链接：https://www.wolai.com/4d217ahiXiWYHtpT8yCXAV#rSVuGVLuCjFurMSqWdS6Mk

#include <iostream>
#include <cmath>

using namespace std;

int mySqrt(int x);
int newtonSqrt(int x);

int main()
{
    int x;
    cin >> x;
    cout << mySqrt(x) << endl;
    cout << newtonSqrt(x) << endl;

    return 0;
}

int mySqrt(int x)
{
    double left{0}, right{ x * 1.0 };
    double mid{0};

    if (x == 1) return 1;

    while (abs(mid * mid - x) >= 0.01)
    {
        mid = ((right - left) * 0.5) + left;

        // cout << mid << endl;

        if (mid * mid == x) return static_cast<int>(mid);
        if (mid * mid < x) left = mid;
        if (mid * mid > x) right = mid;
    }

    return static_cast<int>(mid);
}

int newtonSqrt(int x)
{
    if (x == 0) return 0;

    double current{x * 1.0}, C{x * 1.0};

    while (true)
    {
        double next = 0.5 * (current + C / current);

        if (abs(current - next) < 1e-7) return static_cast<int>(current);

        current = next;
    }
}

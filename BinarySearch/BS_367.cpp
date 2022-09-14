// Created by Ashechol on 2022/9/15.
// 367. 有效的完全平方数
// 题目链接：https://leetcode.cn/problems/valid-perfect-square/
// 题解链接：

#include <iostream>

using namespace std;

bool isPerfectSquare(int num);
int mySqrt(int num);

int main()
{
    int num;
    cin >> num;
    cout << isPerfectSquare(num) << endl;
    return 0;
}

bool isPerfectSquare(int num)
{
    float x{static_cast<float>(mySqrt(num))};
    return static_cast<float>(num) / x == x;
}

int mySqrt(int num)
{
    int left{0}, right{num};

    if (num == 1) return 1;

    while (left < right)
    {
        int mid = ((right - left) >> 1) + left;

        if (num / mid > mid) left = mid + 1;
        else right = mid;
    }

    return left;
}

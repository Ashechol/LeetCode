// Created by Ashechol on 2022/9/28.
// 202. 快乐数
// 题解链接：https://www.wolai.com/euc6U5B9iVLcitUun2KCZr#bPLoRXVfQEyquH226n32x6

#include <iostream>
#include <unordered_set>

using namespace std;

bool isHappy(int n);
int sumOfSqure(int n);

int main()
{
    int n;
    cin >> n;

    cout << isHappy(n) << endl;
    return 0;
}

bool isHappy(int n)
{
    unordered_set<int> numSet;

    while (n != 1)
    {
        if (numSet.find(n) != numSet.end())
            return false;

        numSet.insert(n);
        n = sumOfSqure(n);
    }

    return true;
}

int sumOfSqure(int n)
{
    int sum = 0;

    while (n != 0)
    {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }

    return sum;
}

// Created by Ashechol on 2023/3/24.
// 415. 字符串相加
// https://leetcode.cn/problems/add-strings/

#include <iostream>
#include <algorithm>

using namespace std;

string addStrings(string num1, string num2)
{
    int next = 0;
    int i = num1.size() - 1, j = num2.size() - 1;
    string res;
    while (i >= 0 || j >= 0 || next != 0)
    {
        int a = i >= 0 ? num1[i] - '0' : 0;
        int b = j >= 0 ? num2[j] - '0' : 0;
        int add = a + b + next;
        next = add / 10;
        res += to_string(add % 10);
        --i; --j;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string num1, num2;
    cin >> num1 >> num2;
    string res = addStrings(num1, num2);
    cout << res << endl;
    return 0;
}

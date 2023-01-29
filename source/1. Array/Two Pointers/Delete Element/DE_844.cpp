// Created by Ashechol on 2022/9/16.
// 844. 比较含退格的字符串
// 题目链接：https://leetcode.cn/problems/backspace-string-compare/
// 题解链接：https://www.wolai.com/nFyn3sAMX3hbErJNQhT5Z3#qG24QE1Z4LEpKJb13UeWP3

#include <iostream>

using namespace std;

bool backspaceCompare(string s, string t);
void backspaceString(string& s);

int main()
{
    string s, t;

    cin >> s >> t;

    cout << backspaceCompare(s, t);

    return 0;
}

bool backspaceCompare(string s, string t)
{
    backspaceString(s);
    backspaceString(t);
    return s == t;
}

void backspaceString(string& s)
{
    int slow = 0;

    for (int fast = 0; fast < s.size(); fast++)
    {
        if (s[fast] != '#')
            s[slow++] = s[fast];
        else if (slow > 0) // 防止第一个字符为 # 时出现数组越界
            slow--;
    }

    s.resize(slow);
}
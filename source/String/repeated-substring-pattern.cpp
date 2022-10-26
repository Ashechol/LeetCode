// Created by Ashechol on 2022/10/26.
// 459. 重复的子字符串
// 题解链接：https://www.wolai.com/qKed6CrmVJa1SBc8CEiC2H#436phWunuGTJc9rzzHSdq1

#include <iostream>

using namespace std;

bool repeatedSubstringPattern(string s);

int main()
{
    string s;
    cin >> s;

    cout << repeatedSubstringPattern(s) << endl;

    return 0;
}

bool repeatedSubstringPattern(string s)
{
    int pre = -1;
    int next[s.length()];
    next[0] = pre;
    for (int cur = 1; cur < s.length(); cur++)
    {
        while (pre >= 0 && s[pre + 1] != s[cur]) pre = next[pre];

        if (s[pre + 1] == s[cur]) pre++;

        next[cur] = pre;
    }

    cout << pre << endl;

    if ((pre + 1) % (s.length() - pre - 1) == 0 && pre != -1)
        return true;

    return false;
}

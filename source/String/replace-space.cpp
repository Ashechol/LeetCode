// Created by Ashechol on 2022/10/9.
// 剑指 Offer 05. 替换空格
// 题解链接：https://www.wolai.com/qKed6CrmVJa1SBc8CEiC2H#i2cnPaTM1mqSDVJMfmKjjb

#include <iostream>

using namespace std;

string replaceSpace(string s);
string replaceSpace2(string s);

int main()
{
    string s;

    getline(cin, s);

    cout << replaceSpace2(s) << endl;

    return 0;
}

string replaceSpace(string s)
{
    int spaceCnt = 0;

    for (char c: s)
        if (c == ' ') spaceCnt++;

    // current指向旧字符串最后一个字符
    int cur = s.size() - 1;
    s.resize(s.size() + 2 * spaceCnt);
    // previous指向新字符串的尾部
    int pre = s.size() - 1;

    for (; pre < cur; cur--, pre--)
    {
        if (s[cur] != ' ')
            s[pre] = s[cur];
        else
        {
            s[pre--] = '0';
            s[pre--] = '2';
            s[pre] = '%';
        }
    }

    return s;
}

string replaceSpace2(string s)
{
    string res;

    for (char c: s)
    {
        if (c != ' ')
            res.push_back(c);
        else
            res += "%20";
    }

    return res;
}

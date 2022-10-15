// Created by Ashechol on 2022/10/10.
// 151. 反转字符串中的单词
// 题解链接：https://www.wolai.com/qKed6CrmVJa1SBc8CEiC2H#iK7BFvHaUAnkJWqyq1rjkN

#include <iostream>
#include <algorithm>

using namespace std;

string reverseWords(string s);
string reverseWords2(string s);

int main()
{
    string s;

    getline(cin, s);

    cout << reverseWords2(s) << endl;

    return 0;
}

string reverseWords(string s)
{
    string res;

    int l = s.length() - 1, r = l;

    while (l >= 0)
    {
        while (l >= 0 && s[l] == ' ') l--;
        if (l < 0) break;
        r = l;
        while (r >= 0 && s[r] != ' ') r--;

        res += s.substr(r + 1, l - r);
        res += ' ';
        l = r;
    }

    res.erase(res.end() - 1);

    return res;
}

void removeExtraSpace(string& s)
{
    int slow = 0;
    for (int fast = 0; fast < s.length(); fast++)
    {
        if (s[fast] == ' ' ) continue;

        if (slow != 0) s[slow++] = ' ';

        while (fast < s.length() && s[fast] != ' ')
            s[slow++] = s[fast++];
    }

    s.resize(slow);
}

string reverseWords2(string s)
{
    removeExtraSpace(s);

    reverse(s.begin(), s.end());

    int slow = 0;
    for (int fast = 0; fast <= s.length(); fast++)
    {
        if (s[fast] != ' ' && fast != s.length()) continue;

        reverse(s.begin() + slow, s.begin() + fast);
        slow = fast + 1;
    }

    return s;
}
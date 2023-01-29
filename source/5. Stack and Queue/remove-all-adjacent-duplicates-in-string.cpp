// Created by Ashechol on 2022/10/28.
// 1047. 删除字符串中的所有相邻重复项
// 题解链接：

#include <iostream>
#include <deque>

using namespace std;

string removeDuplicates(string s);

int main()
{
    string s;
    cin >> s;

    cout << removeDuplicates(s) << endl;

    return 0;
}

string removeDuplicates(string s)
{
    deque<char> dq;
    string res;

    for (char c: s)
    {
        if (dq.empty() || c != dq.back()) dq.push_back(c);

        else if (dq.back() == c) dq.pop_back();
    }

    while (!dq.empty())
    {
        res.push_back(dq.front());
        dq.pop_front();
    }

    return res;
}

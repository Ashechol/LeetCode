// Created by Ashechol on 2022/10/27.
// 20. 有效的括号
// 题解链接：

#include <iostream>
#include <stack>

using namespace std;

bool IsValid(string s);

int main()
{
    string s;
    cin >> s;

    cout << IsValid(s) << endl;

    return 0;
}

char GetRbrace(char lbrace)
{
    if (lbrace == '(')
        return ')';

    if (lbrace == '[')
        return ']';

    if (lbrace == '{')
        return '}';

    return ' ';
}

bool IsValid(string s)
{
    if (s.size() % 2 != 0) return false;

    stack<char> stk;

    for (char c: s)
    {
        if (!stk.empty() && c == GetRbrace(stk.top()))
            stk.pop();
        else
            stk.push(c);
    }

    return stk.empty();
}
// Created by Ashechol on 2022/10/27.
// 20. 有效的括号
// 题解链接：

#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s);
bool isValid_compact(string s);

int main()
{
    string s;
    cin >> s;

    cout << isValid_compact(s) << endl;

    return 0;
}

bool isValid(string s)
{
    if (s.length() % 2 != 0) return false;

    stack<char> s1, s2;

    for (char c: s) s1.push(c);

    while (!s1.empty())
    {
        if (s2.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        if ((s1.top() == '(' && s2.top() == ')')
            ||(s1.top() == '{' && s2.top() == '}')
            ||(s1.top() == '[' && s2.top() == ']'))
            s2.pop();
        else
            s2.push(s1.top());

        s1.pop();
    }

    return s2.empty();
}

char rbrace(char c)
{
    if (c == '(')
        return ')';

    if (c == '{')
        return '}';

    if (c == '[')
        return ']';

    return '\0';
}

bool isValid_compact(string s)
{
    stack<char> stk;

    for (char c : s)
    {
        if (!stk.empty() && c == stk.top())
            stk.pop();
        else
            stk.push(rbrace(c));
    }

    return stk.empty();
}
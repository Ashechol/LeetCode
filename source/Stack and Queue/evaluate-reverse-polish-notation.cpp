// Created by Ashechol on 2022/10/28.
// 150. 逆波兰表达式求值
// 题解链接：

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int evalRPN(vector<string>& tokens);

int main()
{
    vector<string> tokens;
    string t;

    while (cin >> t)
    {
        if (t == "-0") break;
        tokens.push_back(t);
    }

    cout << evalRPN(tokens) << endl;

    return 0;
}

int toNum(string s)
{
    int res = 0;
    int bit = 1;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] != '-')
        {
            res += (s[i] - '0') * bit;
            bit *= 10;
        }
        else
            res *= -1;
    }

    return res;
}

int evalRPN(vector<string>& tokens)
{
    stack<int> stk;

    for (string s: tokens)
    {
        if (s.back() >= '0' && s.back() <= '9') stk.push(stol(s));

        else
        {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();

            switch (s[0])
            {
                case '+':
                    stk.push(a + b);
                    break;

                case '-':
                    stk.push(a - b);
                    break;

                case '*':
                    stk.push(a * b);
                    break;

                case '/':
                    stk.push(a / b);
                    break;
            }
        }
    }

    return stk.top();
}

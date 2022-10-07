// Created by Ashechol on 2022/10/7.
// 344. 反转字符串
// 题解链接：https://www.wolai.com/qKed6CrmVJa1SBc8CEiC2H#qnhx881QU2tY3p7jnKvB3s

#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char>& s);

int main()
{
    int n;
    cin >> n;
    vector<char> s(n);

    for (char& c: s) cin >> c;

    reverseString(s);

    for (char c: s) cout << c;
    cout << endl;

    return 0;
}

void reverseString(vector<char>& s)
{
    int l = 0, r = s.size() - 1;

    while (l < r)
        swap(s[l++], s[r--]);
}
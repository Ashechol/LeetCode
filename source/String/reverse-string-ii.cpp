// Created by Ashechol on 2022/10/7.
// 541. 反转字符串 II
// 题解链接：https://www.wolai.com/qKed6CrmVJa1SBc8CEiC2H#cnk7SuPiTa1aiy5qUD3bCw

#include <iostream>

using namespace std;

string reverseStr(string s, int k);

int main()
{
    int k;
    string s;

    cin >> s >> k;

    cout << reverseStr(s, k) << endl;

    return 0;
}

string reverseStr(string s, int k)
{
    int cnt = 0;
    int l, r, len = (int) s.length();
    for (int i = 0; i < len; i++)
    {
        if (++cnt == 2 * k)
        {
            l = i - k * 2 + 1, r = i - k;

            while (l < r) swap(s[l++], s[r--]);

            cnt = 0;
        }
    }
    l = len - cnt;
    r = cnt > k ? len - (cnt - k) - 1: len - 1;

    while (l < r) swap(s[l++], s[r--]);

    return s;
}

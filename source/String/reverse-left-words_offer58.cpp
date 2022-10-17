// Created by Ashechol on 2022/10/17.
// 剑指 Offer 58 - II. 左旋转字符串
// 题解链接：https://www.wolai.com/qKed6CrmVJa1SBc8CEiC2H#8spJ4D7ZMLewALHiUVG5FW

#include <iostream>
#include <algorithm>

using namespace std;

string reverseLeftWords(string s, int n);
string reverseLeftWords2(string s, int n);

int main()
{
    int n;
    string s;
    cin >> s >> n;

    cout << reverseLeftWords2(s, n);

    return 0;
}

string reverseLeftWords(string s, int n)
{
    int pre = 0, cur = n;
    string tmp = s.substr(0, n);

    while(cur < s.length())
        s[pre++] = s[cur++];

    int i = 0;
    while(pre < s.length()) s[pre++] = tmp[i++];

    return s;
}

string reverseLeftWords2(string s, int n)
{
    reverse(s.begin(), s.begin() + n);
    reverse(s.begin() + n, s.end());
    reverse(s.begin(), s.end());

    return s;
}


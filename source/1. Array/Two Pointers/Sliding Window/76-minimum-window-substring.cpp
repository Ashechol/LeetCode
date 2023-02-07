// Created by Ashechol on 2022/9/18.
// 76. 最小覆盖子串
// https://leetcode.cn/problems/minimum-window-substring/

#include <iostream>
#include <unordered_map>

using namespace std;

string minSubString(string s, string t);

int main()
{
    string s, t;

    cin >> s >> t;

    cout << minSubString(s, t) << endl;

    return 0;
}

string minSubString(string s, string t)
{
    unordered_map<char, int> sCharCnt, tCharCnt;
    int minLen = INT32_MAX;
    string res;

    for (const char c: t) tCharCnt[c]++;

    int typeNum = 0;

    for (int l = 0, r = 0; r < s.size(); r++)
    {
        sCharCnt[s[r]]++;

        // 当前字符属于t，切数量等于t中的数量
        if (tCharCnt.find(s[r]) != tCharCnt.end() && sCharCnt[s[r]] == tCharCnt[s[r]])
            typeNum++;

        // 已满足覆盖条件
        while (typeNum == tCharCnt.size())
        {
            // 更新结果
            if (minLen > r - l + 1)
            {
                minLen   = r - l + 1;
                res = s.substr(l, r - l + 1);
            }

            // 向右更新左边界
            sCharCnt[s[l]]--;

            // 左边界对应字符数量不等于t中的数量时，退出循环
            if (tCharCnt.find(s[l]) != tCharCnt.end() && sCharCnt[s[l]] < tCharCnt[s[l]] )
                typeNum--;
            // 向右更新左边界
            l++;
        }
    }

    return res;
}

string minSubString_abbr(string s, string t)
{
    unordered_map<char, int> sCharCnt, tCharCnt;
    string res;

    for (char c: t) tCharCnt[c]++;

    for (int l = 0, r = 0, cnt = 0; r < s.size(); r++)
    {
        sCharCnt[s[r]]++;

        if (sCharCnt[s[r]] <= tCharCnt[s[r]]) cnt++;

        while (sCharCnt[s[l]] > tCharCnt[s[l]]) sCharCnt[s[l++]]--;

        if (cnt == t.length() && (res.empty() || res.length() > r - l + 1))
            res = s.substr(l, r - l + 1);
    }

    return res;
}
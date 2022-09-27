// Created by Ashechol on 2022/9/27.
// 438. 找到字符串中所有字母异位词
// 题解链接：https://www.wolai.com/euc6U5B9iVLcitUun2KCZr#mhfgGYhCw8YA8VbiiDkdBF

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> findAnagrams(string s, string p);

int main()
{
    string s, p;
    cin >> s >> p;

    vector<int> res = findAnagrams(s, p);

    for (int i: res) cout << i << endl;

    cout << "\b\n";

    return 0;
}

vector<int> findAnagrams(string s, string p)
{
    int sHash[26] = {}, pHash[26] = {};
    vector<int> res;

    for (char c: p) pHash[c - 'a']++;

    int len = 0;
    for (int l = 0, r = 0; r < s.length(); r++)
    {
        sHash[s[r] - 'a']++;

        if (sHash[s[r] - 'a'] <= pHash[s[r] - 'a']) len++;

        // 找到最小覆盖子串
        while (l < s.length() && sHash[s[l] - 'a'] > pHash[s[l] - 'a'])
            sHash[s[l++] - 'a']--;

        // 排除有非p中字符的子串
        while (r - l + 1 > p.length())
        {
            if (pHash[s[l] - 'a'] > 0)
                len--;

            sHash[s[l++] - 'a']--;
        }

        if (len == p.length())
            res.push_back(l);
    }

    return res;
}

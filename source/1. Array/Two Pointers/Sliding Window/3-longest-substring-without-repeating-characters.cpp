// Created by Ashechol on 2023/2/7.
// 3. 无重复字符的最长子串
// https://leetcode.cn/problems/longest-substring-without-repeating-characters/

#include <iostream>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(const string& s)
{
    int left = 0, right = 0;
    int res = 0;
    unordered_map<char, int> hash;

    while (right < s.length())
    {
        hash[s[right++]]++;

        while (hash[s[right - 1]] > 1)
            hash[s[left++]]--;

        if (right - left > res)
            res = right - left;
    }

    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
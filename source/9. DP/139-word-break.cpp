// Created by Ashechol on 2023/2/25.
// 139. 单词拆分
// https://leetcode.cn/problems/word-break/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict)
{
    unordered_map<string, bool> dp;
    dp[""] = true;

    for (int i = 1; i <= s.size(); i++)
    {
        for (const string& word: wordDict)
        {
            if (word.size() <= i && s.substr(i - word.size(), word.size()) == word)
            {
                if (!dp[s.substr(0, i)])
                    dp[s.substr(0, i)] = dp[s.substr(0, i - word.size())];
            }
        }
    }

    return dp[s];
}

int main()
{
    int n;
    cin >> n;
    vector<string> wordDict(n);
    for (string& word: wordDict) cin >> word;
    string s;
    cin >> s;

    cout << wordBreak(s, wordDict) << endl;

    return 0;
}

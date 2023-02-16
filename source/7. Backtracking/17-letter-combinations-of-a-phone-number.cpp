// Created by Ashechol on 2023/2/16.
// 17. 电话号码的字母组合
// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, string> key;
vector<string> ans;
string path;

void dfs(string& digits, int curInd)
{
    if (curInd == digits.size())
    {
        ans.emplace_back(path);
        return;
    }

    string s = key[digits[curInd] - '0'];

    for (char c: s)
    {
        path.push_back(c);
        dfs(digits, curInd+1);
        path.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    if (digits.empty()) return {};
    key[2] = "abc"; key[3] = "def"; key[4] = "ghi";
    key[5] = "jkl"; key[6] = "mno"; key[7] = "pqrs";
    key[8] = "tuv"; key[9] = "wxyz";

    dfs(digits, 0);
    return ans;
}

int main()
{
    string digits;
    cin >> digits;
    vector<string> res = letterCombinations(digits);

    for (const string& str: res) cout << str << " ";
    cout << '\b' << endl;
    return 0;
}
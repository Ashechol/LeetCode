// Created by Ashechol on 2022/9/26.
// 49. 字母异位词分组
// 题解链接：https://www.wolai.com/euc6U5B9iVLcitUun2KCZr#sWhqjCsP7YXi7obREUTquo

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs);
vector<vector<string>> groupAnagrams_arrayHash(vector<string>& strs);

int main()
{
    int n;
    cin >> n;

    vector<string> strs(n);
    for (int i = 0; i < n; i++)
        cin >> strs[i];

    vector<vector<string>> res = groupAnagrams_arrayHash(strs);

    for (const vector<string>& group: res)
    {
        for (const string& str: group)
            cout << str << " ";
        cout << "\b\n";
    }

    return 0;
}

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string, vector<string>> groups;
    vector<vector<string>> res;

    for (const string& str: strs)
    {
        string key = str;
        sort(key.begin(), key.end());
        groups[key].push_back(str);
    }

    for (pair<string, vector<string>> p: groups)
        res.push_back(p.second);

    return res;
}

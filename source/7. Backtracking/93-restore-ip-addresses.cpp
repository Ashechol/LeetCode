// Created by Ashechol on 2023/2/17.
// 93. 复原 IP 地址
// https://leetcode.cn/problems/restore-ip-addresses/

#include <iostream>
#include <vector>

using namespace std;

int cnt;
void dfs(const string& s, int bg, vector<string>&res, string path)
{
    if (bg == s.size() && cnt == 4)
    {
        path.pop_back();
        res.emplace_back(path);
        return;
    }

    if (cnt == 4 && bg < s.size())
        return;

    for (int i = bg; i < s.size() && i < bg + 3; i++)
    {
        string tmp = s.substr(bg, i-bg+1);

        if (stoi(tmp) > 255 || (s[bg] == '0' && i > bg)) return;

        cnt++;
        dfs(s, i+1, res, path+tmp+'.');
        cnt--;
    }
}

vector<string> restoreIpAddresses(const string& s)
{
    vector<string> res;
    if (s.size() > 12) return res;

    dfs(s, 0, res, "");
    return res;
}

int main()
{
    string s;
    cin >> s;

    vector<string> res  = restoreIpAddresses(s);

    for (string val: res)
        cout << val << endl;

    return 0;
}

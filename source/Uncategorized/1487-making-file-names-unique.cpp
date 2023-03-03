// Created by Ashechol on 2023/3/3.
// 1487. 保证文件名唯一
// https://leetcode.cn/problems/making-file-names-unique/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> getFolderNames(vector<string>& names)
{
    unordered_map<string, int> nameHash;
    vector<string> res;

    for (const string& name: names)
    {
        if (nameHash[name] == 0)
        {
            res.emplace_back(name);
            nameHash[name] = 1;
        }
        else
        {
            int i = nameHash[name];
            string index = "(" + to_string(i) + ")";
            while (nameHash[name+index] != 0)
            {
                i++; nameHash[name]++;
                index = "(" + to_string(i) + ")";
            }
            res.emplace_back(name+index);
            nameHash[name+index] = 1;
        }
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<string> names(n);
    for(string& name: names) cin >> name;

    names = getFolderNames(names);

    for (int i = 0; i < names.size(); i++)
        cout << names[i] << "\n "[i != names.size()-1];

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> record;

string longestPalindrome(string s)
{
    string res;

    record.resize(s.size(), vector<bool>(s.size(), false));

    for (int i = s.size() - 1; i >= 0; i--)
    {
        for (int j = i; j < s.size(); j++)
        {
            if (i == j) record[i][j] = true;
            else if (j - i == 1) record[i][j] = s[i] == s[j];
            else record[i][j] = record[i+1][j-1] && s[i] == s[j];

            if (record[i][j] && j - i + 1 > res.size())
                res = s.substr(i, j-i+1);
        }
    }

    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << longestPalindrome(s) << endl;
    return 0;
}
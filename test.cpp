#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n;

    int k;
    vector<pair<int, int>> frame, preFrame;
    map<pair<int, int>, int> cnt;
    int res = 1;

    while (n--)
    {
        cin >> m;
        cin >> k;
        frame.resize(k);
        for (auto& p: frame)
        {
            cin >> p.first >> p.second;
            ++cnt[p];
        }
        while (--m)
        {
            preFrame.assign(frame.begin(), frame.end());
            cin >> k;
            frame.resize(k);
            for (auto& p: frame)
            {
                cin >> p.first >> p.second;
                if (cnt.find(p) == cnt.end())
                    cnt[p]++;
                else if (find(preFrame.begin(), preFrame.end(), p) != preFrame.end())
                    cnt[p]++;
                else
                    cnt[p]--;

                res = max(cnt[p], res);
            }
        }
        cout << res << endl;
    }
    return 0;
}
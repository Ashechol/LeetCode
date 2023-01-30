// Created by Ashechol on 2023/1/30.
// 347. 前 K 个高频元素

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>


using namespace std;

vector<int> topKFrequency(vector<int>& nums, int k);

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int& num: nums) cin >> num;

    vector<int> res = topKFrequency(nums, k);

    for (int& num: res) cout << num << " ";
    cout << "\b\n";

    return 0;
}

struct cmp
{
    bool operator() (const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.second > b.second;
    }
};

vector<int> topKFrequency(vector<int>& nums, int k)
{
    unordered_map<int, int> hash;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;
    vector<int> res(k);

    for (int num: nums) hash[num]++;

    for (auto iter: hash)
    {
        que.emplace(iter);

        if (que.size() > k)
            que.pop();
    }

    for (int i = k - 1; i >= 0; i--)
    {
        res[i] = que.top().first;
        que.pop();
    }

    return res;
}
// Created by Ashechol on 2022/9/28.
// 349. 两个数组的交集
// 题解链接：https://www.wolai.com/euc6U5B9iVLcitUun2KCZr#o4cVXGt4sDPmDx1M9bJ63Z

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2);

int main()
{
    int m, n;
    cin >> m >> n;

    vector<int> numsA(m);
    vector<int> numsB(n);

    for (int& num: numsA) cin >> num;
    for (int& num: numsB) cin >> num;

    vector<int> res = intersection(numsA, numsB);

    for (int num: res) cout << num << " ";

    cout << "\b\n";

    return 0;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    unordered_map<int, int> numCnt1, numCnt2;
    vector<int> interSet;

    for (int num: nums1) numCnt1[num]++;
    for (int num: nums2) numCnt2[num]++;

    for (pair<int, int> p: numCnt1)
    {
        if (numCnt2[p.first] > 0)
            interSet.push_back(p.first);
    }

    return interSet;
}

vector<int> intersection_set(vector<int>& nums1, vector<int>& nums2)
{
    unordered_set<int> numSet(nums1.begin(), nums1.end());
    unordered_set<int> interSet;

    for (int num: nums1) numSet.insert(num);

    for (int num: nums2)
    {
        if (numSet.find(num) != numSet.end())
            interSet.insert(num);
    }

    vector<int> res(interSet.begin(), interSet.end());
    return res;
}

vector<int> intersection_arrayHash(vector<int>& nums1, vector<int>& nums2)
{
    int hash1[1005] = {};
    // int hash2[1005] = {};
    unordered_set<int> resSet;
    // vector<int> interSet;

    for (int num: nums1) hash1[num]++;
    // for (int num: nums2) hash2[num]++;

    // for (int i = 0; i < 1000; i++)
    // {
    //     if (hash1[i] > 0 && hash2[i] > 0)
    //         interSet.push_back(i);
    // }

    for (int num: nums2)
        if (hash1[num] > 0)
            resSet.insert(num);

    vector<int> interSet(resSet.begin(), resSet.end());
    return interSet;
}

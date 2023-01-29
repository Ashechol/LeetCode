// Created by Ashechol on 2022/9/29.
// 454. 四数相加 II
// 题解链接：https://www.wolai.com/euc6U5B9iVLcitUun2KCZr#nCq6VATcYBRzfWTBcNGCeb

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4);

int main()
{
    int n;
    cin >> n;

    vector<int> nums1(n), nums2(n), nums3(n), nums4(n);

    for (int& num: nums1) cin >> num;
    for (int& num: nums2) cin >> num;
    for (int& num: nums3) cin >> num;
    for (int& num: nums4) cin >> num;

    cout << fourSumCount(nums1, nums2, nums3, nums4) << endl;

    return 0;
}

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
{
    int cnt = 0;
    unordered_map<int, int> hash12, hash34;

    for (int num1: nums1)
        for (int num2: nums2)
            hash12[num1 + num2]++;

    for (int num3: nums3)
        for (int num4: nums4)
            hash34[num3 + num4]++;

    for (auto iter: hash12)
    {
        if (hash34.find(0 - iter.first) != hash34.end())
            cnt += iter.second * hash34[0 - iter.first];
    }

    return cnt;
}

int fourSumCount_saveMemory(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
{
    int cnt = 0;
    unordered_map<int, int> hash12;

    for (int num1: nums1)
        for (int num2: nums2)
            hash12[num1 + num2]++;

    for (int num3: nums3)
        for (int num4: nums4)
                cnt += hash12[0 - num3 - num4];

    return cnt;
}

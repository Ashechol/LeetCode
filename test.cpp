#include <iostream>
#include <vector>

using namespace std;

int res;
void quickSelect(vector<int>& nums, int bg, int ed, int targetInd)
{
    if (bg >= ed) return;

    int randInd = bg + rand() % (ed - bg);
    int pivot = nums[randInd];
    swap(nums[bg], nums[randInd]);

    int left = bg;
    for (int i = bg + 1; i < ed; i++)
    {
        if (nums[i] < pivot)
            swap(nums[i], nums[++left]);
    }
    swap(nums[bg], nums[left]);

    if (left == targetInd)
    {
        res = nums[left];
        return;
    }

    if (left < targetInd)
        quickSelect(nums, left+1, ed, targetInd);
    else
        quickSelect(nums, bg, left, targetInd);
}

int findKthLargest(vector<int>& nums, int k)
{
    quickSelect(nums, 0, nums.size(), nums.size()-k);
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);

    for (int& num: nums) cin >> num;

    cout << findKthLargest(nums, k) << endl;

    return 0;
}
#include <iostream>
#include <queue>

using namespace std;

struct Compare
{
    bool operator () (int a, int b)
    {
        return a > b;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int& num: nums) cin >> num;

    priority_queue<int, vector<int>, Compare> heap;

    for (int num: nums)
    {
        heap.push(num);
        if (heap.size() > k)
            heap.pop();
    }

    cout << heap.top() << endl;

    return 0;
}
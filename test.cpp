#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices)
{
    int maxProf = 0;
    int minPrice = prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
        minPrice = min(prices[i], minPrice);
        maxProf = max(maxProf, prices[i] - minPrice);
    }

    return maxProf;
}

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int& price: prices) cin >> price;
    cout << maxProfit(prices) << endl;
    return 0;
}
// Created by Ashechol on 2022/9/17.
// 904. 水果成篮
// 题目链接：https://leetcode.cn/problems/fruit-into-baskets/
// 题解链接：https://www.wolai.com/ktot9KqKvRKWvcJT5s15D3#3R4ZG7gZn7aoLTrCqjnyYd

#include <iostream>
#include <vector>

using namespace std;

int totalFruit(vector<int>& fruits);

int main()
{
    int n;
    cin >> n;

    vector<int> fruits(n);
    for (int& fruit: fruits) cin >> fruit;

    cout << totalFruit(fruits) << endl;

    return 0;
}

int totalFruit(vector<int>& fruits)
{
    int maxTotal = 0;
    int fruitTypes[] = {-1, -1};

    if (fruits.size() <= 2) return (int) fruits.size();

    for (int l = 0, r = 0; r < fruits.size(); r++)
    {
        if (fruitTypes[0] == -1)
            fruitTypes[0] = fruits[r];

        else if (fruitTypes[1] == -1 && fruitTypes[0] != fruits[r])
            fruitTypes[1] = fruits[r];

        else if (fruitTypes[0] != fruits[r] && fruitTypes[1] != fruits[r])
        {
            fruitTypes[0] = fruits[r - 1];
            fruitTypes[1] = fruits[r];

            l = r;
            while (fruits[l - 1] == fruitTypes[0]) l--;
        }

        if (maxTotal < r - l + 1) maxTotal = r - l + 1;
    }

    return maxTotal;
}



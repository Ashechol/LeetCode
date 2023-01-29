// Created by Ashechol on 2022/9/26.
// 242. 有效的字母异位词
// 题解链接：https://www.wolai.com/euc6U5B9iVLcitUun2KCZr#2eGiA8yZpwea694tV8RWtm

#include <iostream>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t);

int main()
{
    string s, t;
    cin >> s >> t;

    cout << isAnagram(s, t) << endl;
}

bool isAnagram(string s, string t)
{
    unordered_map<char, int> hashS, hashT;

    for (char c: s) hashS[c]++;

    for (char c: t) hashT[c]++;

    return hashS == hashT;
}

bool isAnagram_arrayHash(string s, string t)
{
    int charCnt[26]{};

    for (char c: s) charCnt[c - 'a']++;
    for (char c: t) charCnt[c - 'a']--;

    for (int i: charCnt)
        if (i != 0) return false;

    return true;
}

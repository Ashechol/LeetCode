// Created by Ashechol on 2022/10/18.
// 28. 找出字符串中第一个匹配项的下标
// 题解链接：https://www.wolai.com/qKed6CrmVJa1SBc8CEiC2H#vVnRuzHYfuVypgTkdkTpwy

#include <iostream>

using namespace std;

int strStr(string haystack, string needle);\
int* getNext(const string& str);
int strStr_KMP(string haystack, string needle);

int main()
{
    string haystack, needle;
    cin >> haystack >> needle;

    cout << strStr_KMP(haystack, needle) << endl;

    return 0;
}

int strStr(string haystack, string needle)
{
    int len = needle.length();

    if (len > haystack.length()) return -1;

    for (int i = 0; i < haystack.length() - len + 1; i++)
    {
        if (haystack.substr(i, len) == needle)
            return i;
    }

    return -1;
}

int* getNext(const string& str)
{
    int* next = new int[str.length()];

    int pre = -1;
    next[0] = pre;

    for (int suf = 1; suf < str.length(); suf++)
    {
        while (pre >= 0 && str[suf] != str[pre + 1]) pre = next[pre];

        if (str[suf] == str[pre + 1]) pre++;

        next[suf] = pre;
    }

    return next;
}

int strStr_KMP(string haystack, string needle)
{
    int* next = getNext(needle);

    for (int i = 0, j = -1; i < haystack.length(); i++)
    {
        while (j >= 0 && haystack[i] != needle[j + 1])
            j = next[j];

        if (haystack[i] == needle[j + 1]) j++;

        if (j == needle.length() - 1)
            return i - needle.length() + 1;
    }

    return -1;
}

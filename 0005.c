#include <string.h>

// 从中心向两边扩展，返回回文长度
int expandAroundCenter(char *s, int left, int right) {
    while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

char *longestPalindrome(char *s) {
    int n = strlen(s);
    if (n == 0) return "";

    int start = 0, maxLen = 1;

    for (int i = 0; i < n; i++) {
        // 奇数长度回文
        int len1 = expandAroundCenter(s, i, i);
        // 偶数长度回文
        int len2 = expandAroundCenter(s, i, i + 1);

        int len = len1 > len2 ? len1 : len2;
        if (len > maxLen) {
            maxLen = len;
            start = i - (len - 1) / 2;
        }
    }

    // LeetCode 要求返回新字符串
    char *result = (char *)malloc(sizeof(char) * (maxLen + 1));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';
    return result;
}
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int last[128];          // 记录字符最近出现的位置
    memset(last, -1, sizeof(last));

    int maxLen = 0;
    int left = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        char c = s[right];

        // 如果字符出现过，并且在当前窗口内
        if (last[c] >= left) {
            left = last[c] + 1;
        }

        last[c] = right;   // 更新最新位置
        int curLen = right - left + 1;
        if (curLen > maxLen) {
            maxLen = curLen;
        }
    }

    return maxLen;
}
//时间复杂度：O(n),空间复杂度：O(1)
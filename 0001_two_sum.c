/*给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。
你可以按任意顺序返回答案。
示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。*/
//建立整数数组
#include <stdlib.h>

typedef struct {
    int key;
    int val;
} HashNode;

int hash(int key, int size) {
    return (key % size + size) % size;
}

void insert(HashNode* table, int size, int key, int val) {
    int idx = hash(key, size);
    while (table[idx].val != -1) {
        idx = (idx + 1) % size;
    }
    table[idx].key = key;
    table[idx].val = val;
}

int find(HashNode* table, int size, int key) {
    int idx = hash(key, size);
    while (table[idx].val != -1) {
        if (table[idx].key == key) {
            return table[idx].val;
        }
        idx = (idx + 1) % size;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    // 哈希表大小取质数，减少冲突
    int tableSize = numsSize * 2;
    HashNode* table = (HashNode*)malloc(tableSize * sizeof(HashNode));

    // 初始化哈希表
    for (int i = 0; i < tableSize; i++) {
        table[i].val = -1;
    }

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int idx = find(table, tableSize, complement);

        if (idx != -1) {
            result[0] = idx;
            result[1] = i;
            free(table);
            return result;
        }
        insert(table, tableSize, nums[i], i);
    }

    *returnSize = 0;
    free(table);
    return NULL;
}
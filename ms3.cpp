#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// 方法1. C语言版本
int findRepeatNumber(int* nums, int numsSize){
    // 非法输入返回-1.
    if (!nums || numsSize <= 0) {
        return -1;
    }

    for (int i=0; i<numsSize; ++i) {
        if (nums[i]<0 || nums[i]>numsSize-1) {
            return -1;
        }
    }

    for (int i=0; i<numsSize; ++i) {
        while(nums[i] != i) {
            if (nums[i] == nums[nums[i]]){
                return nums[i];
            }

            // swap.
            int temp = nums[i];
            nums[i] = nums[temp];
            nums[temp] = temp;
        }
    }
    return -1;
}


// 方法1. C++语言版本
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        if (nums.empty()) {
            return -1;  // 非法的输入, 空数组.
        }

        for (int i=0; i<nums.size(); ++i) {
            while(nums[i] != i) {
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }

                // exchange.
                int temp = nums[i];
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }
        return -1;
    }
};


// 方法2. 排序
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        // 先排序，再判断.
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-1; ++i){
            if (nums[i] == nums[i+1]){
                return nums[i];
            }
        }
        return -1;
    }
};


// 方法3. 哈希表
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        // 使用哈希表, 没必要用unordered_map，用unordered_set即可.
        unordered_set<int> hash_set;
        for(auto num: nums){
            if (hash_set.find(num) != hash_set.end()){
                return num;
            }
            hash_set.insert(num);
        }
        return -1;
    }
};


// 方法3. vector模拟哈希表.
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }

        for (auto num: nums) {
            if (num < 0 || num > nums.size()-1) {
                return -1;
            }
        }

        vector<int> hash_set(nums.size(), 0);
        for (auto num: nums) {
            if (hash_set[num] != 0) {
                return num;
            }
            hash_set[num]+=1;
        }
        return -1;
    }
};



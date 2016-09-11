//
//  my_array.cpp
//  leetcode
//
//  Created by heyong on 16/9/1.
//  Copyright © 2016年 heyong. All rights reserved.
//

#include <algorithm>
#include <unordered_map>
#include "my_array.hpp"

std::vector<int> Solution::plus_one_1(std::vector<int> &digits)
{
    int i;
    for (i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] != 9) {
            ++digits[i];
            return digits;
        }
        else {
            digits[i] = 0;
        }
    }
    
    if (i < 0) {
        digits.insert(digits.begin(), 1);
    }
    
    return digits;
}

std::vector<int> Solution::plus_value(std::vector<int> &digits, int v)
{
    // 0 <= v <= 9
    int c = v;
    for (auto it = digits.rbegin(); it != digits.rend() && c > 0; ++it) {
        (*it) += c;
        c /= 10;
        (*it) %= 10;
    }
    
    if (c > 0) {
        digits.insert(digits.begin(), c);
    }
    
    return digits;
}

std::vector<std::vector<int> > Solution::permute(std::vector<int> &nums)
{
    std::vector<std::vector<int> > res;
    sort(nums.begin(), nums.end());
    
    do {
        res.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    
    return res;
}

std::vector<int> Solution::two_sum(std::vector<int> &nums, int target)
{
    std::unordered_map<int, int> mapping;
    std::vector<int> res;
    
    for (size_t i = 0; i < nums.size(); ++i) {
        mapping[nums[i]] = i;
    }
    
    for (size_t i = 0; i < nums.size(); ++i) {
        int gap = target - nums[i];
        if (mapping.find(gap) != mapping.end() && mapping[gap] > i) {
            res.push_back(i + 1);
            res.push_back(mapping[gap] + 1);
            break;
        }
    }
    
    return res;
}

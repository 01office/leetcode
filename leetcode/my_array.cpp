//
//  my_array.cpp
//  leetcode
//
//  Created by heyong on 16/9/1.
//  Copyright © 2016年 heyong. All rights reserved.
//

#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <stack>
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

double Solution::my_pow(double x, int n)
{
    if (n < 0) {
        return 1.0 / m_power(x, -n);
    }
    else {
        return m_power(x, n);
    }
}

double Solution::m_power(double x, int n)
{
    if (n == 0) {
        return 1.0;
    }
    double result = m_power(x, n / 2);
    if (n % 2 == 0) {
        return result * result;
    }
    else {
        return result * result * x;
    }
}

double Solution::my_sqrt(double N)
{
    double X = 1.0;
    while (fabs(X * X - N) > 0.0001) {
        X = (X + N / X) / 2;
    }
    
    return X;
}

int Solution::max_profit(std::vector<int> &prices)
{
    if (prices.size() < 2) {
        return 0;
    }
    int profit = 0;
    int cur_min = prices[0];
    
    for (size_t i = 1; i < prices.size(); ++i) {
        profit = (profit >= prices[i] - cur_min) ? profit : (prices[i] - cur_min);
        cur_min = cur_min > prices[i] ? prices[i] : cur_min;
    }
    
    return profit;
}

int Solution::max_profit_2(std::vector<int> &prices)
{
    int profit = 0;
    int diff;
    for (size_t i = 1; i < prices.size(); ++i) {
        diff = prices[i] - prices[i - 1];
        if (diff > 0) {
            profit += diff;
        }
    }
    
    return profit;
}

bool Solution::can_jump(std::vector<int> nums)
{
    if (nums.size() < 2) {
        return true;
    }
    
    int reach = 1;
    for (size_t i = 0; i < reach && i < nums.size(); ++i) {
        reach = (reach > (i + 1 + nums[i])) ? reach : (i + 1 + nums[i]);
    }
    
    return reach >= nums.size();
}

// divide and conquer: quick sort
void quick_sort(int nums[], int left, int right)
{
    if (left < right)
    {
        int i = left, j = right, tmp = nums[left];
        
        while (i < j)
        {
            while (i < j && nums[j] >= tmp)
            {
                j--;
            }
            if (i < j)
            {
                nums[i++] = nums[j];
            }
            
            while (i < j && nums[i] < tmp)
            {
                i++;
            }
            if (i < j)
            {
                nums[j--] = nums[i];
            }
        }
        
        nums[i] = tmp;
        quick_sort(nums, left, i - 1);
        quick_sort(nums, i + 1, right);
    }
}

int Solution::largest_rectangle_area(std::vector<int> &heights)
{
    size_t len = heights.size();
    int max_size = 0;
    
    for (int i = 0; i < len; ++i) {
        int min_height = heights[i];
        int cur_size = min_height;
        
        for (int j = i; j < len; ++j) {
            if (heights[j] < min_height) {
                min_height = heights[j];
            }
                cur_size = min_height * (j - i + 1);
            
            if (cur_size > max_size) {
                max_size = cur_size;
            }
        }
    }
    
    return max_size;
}

int Solution::largest_area(std::vector<int> &histogram)
{
    histogram.push_back(-1);
    int index = 0;
    int max_area = 0;
    std::stack<int> s;
    
    while (index < histogram.size()) {
        if (s.size() == 0 || histogram[s.top()] <= histogram[index]) {
            s.push(index);
            index += 1;
        }
        else {
            int top = s.top();
            int area = 0;
            if (s.size() == 0) {
                area = histogram[top] * index;
            }
            else {
                area = histogram[top] * (index - s.top() - 1);
            }
            
            max_area = (area > max_area) ? area : max_area;
        }
    }
    
    return max_area;
}

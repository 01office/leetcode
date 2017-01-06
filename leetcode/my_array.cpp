//
//  my_array.cpp
//  leetcode
//
//  Created by heyong on 16/9/1.
//  Copyright © 2016年 heyong. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <stack>
#include <string>
#include "my_array.hpp"

void Solution::m_swap(int &x, int &y)
{
    if (x != y) {
        x ^= y;
        y ^= x;
        x ^= y;
    }
}

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
    while (fabs(X * X - N) > 0.00001) {
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

//int Solution::largest_area(std::vector<int> &histogram)
//{
//    histogram.push_back(-1);
//    int index = 0;
//    int max_area = 0;
//    std::stack<int> s;
//    
//    while (index < histogram.size()) {
//        if (s.size() == 0 || histogram[s.top()] <= histogram[index]) {
//            s.push(index);
//            index += 1;
//        }
//        else {
//            int top = s.top();
//            int area = 0;
//            if (s.size() == 0) {
//                area = histogram[top] * index;
//            }
//            else {
//                area = histogram[top] * (index - s.top() - 1);
//            }
//            
//            max_area = (area > max_area) ? area : max_area;
//        }
//    }
//    
//    return max_area;
//}

int Solution::largest_area(std::vector<int> &histogram)
{
    std::stack<int> s;
    int max_area = 0;
    int tp;
    int area_with_tp;
    
    int idx = 0;
    while (idx < histogram.size()) {
        if (s.empty() || histogram[idx] >= histogram[s.top()]) {
            s.push(idx++);
        }
        else {
            tp = s.top();
            s.pop();
            area_with_tp = histogram[tp] * (s.empty() ? idx : (idx - s.top() - 1));
            max_area = area_with_tp > max_area ? area_with_tp : max_area;
        }
    }
    
    while (!s.empty()) {
        tp = s.top();
        s.pop();
        area_with_tp = histogram[tp] * (s.empty() ? idx : (idx - s.top() - 1));
        max_area = area_with_tp > max_area ? area_with_tp : max_area;
    }
    
    return max_area;
}

int Solution::manacher(std::string &str)
{
    int *p = new int[str.size()];
    
    int id = 0;
    int mx = 0;
    int i = 1;
    
    for (; i < str.size(); ++i) {
        if (i < mx) {
            p[i] = p[2 * id - 1] < (mx - i) ? p[2 * id - 1] : (mx - i);
        }
        else {
            p[i] = 0;
        }
        
        while (str[i + p[i] + 1] == str[i - p[i] - 1]) {
            p[i]++;
        }
        
        if (i + p[i] > mx) {
            id = i;
            mx = id + p[i];
        }
    }
    
    int max_length = 0;
    for (i = 0; i < str.size(); ++i) {
        max_length = p[i] > max_length ? p[i] : max_length;
    }
    
    return max_length;
}

int Solution::other_manacher(std::string &str)
{
    int *p = new int[str.size()];
    
    int mx = 0;
    int id = 0;
    int max_len = 0;
    
    for (int i = 1; i < str.size(); ++i) {
        if (i < mx) {
            p[i] = p[2 * id - i] < (mx - i) ? p[2 * id - i] : (mx - i);
        }
        else {
            p[i] = 1;
        }
        
        while (str[i + p[i] + 1] == str[i - p[i] - 1]) {
            p[i]++;
        }
        
        if (i + p[i] > mx) {
            mx = i + p[i];
            id = i;
        }
    }
    
    for (int j = 0; j < str.size(); ++j) {
        max_len = p[j] > max_len ? p[j] : max_len;
    }
    
    return max_len;
}

void MedianFinder::addNum(int num)
{
    left_heap.push(num);
    right_heap.push(left_heap.top());
    left_heap.pop();
    
    if (left_heap.size() < right_heap.size()) {
        left_heap.push(right_heap.top());
        right_heap.pop();
    }
}

double MedianFinder::findMedian()
{
    if (left_heap.size() == right_heap.size()) {
        return (left_heap.top() + right_heap.top()) / 2.0;
    }
    else {
        return left_heap.top();
    }
}

// Red:0 White:1 Blue:2
void Solution::dutch_flag(std::vector<int> &flags)
{
    if (flags.size() < 3) {
        std::cout << "The size must be large than 3." << std::endl;
        return;
    }
    
    int before = 0;
    int current = 0;
    int end = flags.size() - 1;
    while (current <= end) {
        if (flags[current] == 0) {
            m_swap(flags[before], flags[current]);
            before++;
            current++;
        }
        else if (flags[current] == 1) {
            current++;
        }
        else {
            m_swap(flags[current], flags[end]);
            end--;
        }
    }
}

int Get1ToN::i = 1;


bool is_prime(int n)
{
    for (int i = 2; i * i < (n + 1); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    
    return true;
}

void filter_prime()
{
    bool prime[NUM];
    for (int i = 2; i < NUM; i++) {
        if (i % 2) {
            prime[i] = true;
        } else {
            prime[i] = false;
        }
    }
    prime[2] = true;
    
    for (int i = 2; i * i < NUM; i++) {
        if (prime[i]) {
            for (int j = i + i; j < NUM; j += i) {
                prime[j] = false;
            }
        }
    }
    
    for (int i = 2; i < NUM; i++) {
        if (prime[i]) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}


EightQueen *EightQueen::m_pInstance = NULL;
EightQueen *EightQueen::Instance()
{
    if (m_pInstance == NULL) {
        m_pInstance = new EightQueen;
    }
    return m_pInstance;
}

int EightQueen::g_number = 0;

void EightQueen::print_queen(int ci[], int length)
{
    std::cout << "Solution " << g_number << ": ";
    for (int i = 0; i < length; i++) {
        std::cout << ci[i] << " ";
    }
    std::cout << std::endl;
}

bool EightQueen::check(int ci[], int length)
{
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if ((i - j == ci[i] - ci[j]) || (j - i == ci[i] - ci[j])) {
                return false;
            }
        }
    }
    return true;
}

void EightQueen::permutate(int ci[], int length, int index)
{
    if (index == length) {
        if (check(ci, length)) {
            g_number++;
            print_queen(ci, length);
        }
    } else {
        for (int i = index; i < length; i++) {
            int tmp = ci[i];
            ci[i] = ci[index];
            ci[index] = tmp;
            
            permutate(ci, length, index + 1);
            
            tmp = ci[i];
            ci[i] = ci[index];
            ci[index] = tmp;
        }
    }
}

void EightQueen::eight_queen()
{
    const int queens = 8;
    int ci[queens];
    for (int i = 0; i < queens; i++) {
        ci[i] = i;
    }
    
    permutate(ci, queens, 0);
}

bool is_even(int n)
{
    return (n & 1) == 0;
}


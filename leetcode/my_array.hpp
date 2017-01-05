//
//  my_array.hpp
//  leetcode
//
//  Created by heyong on 16/9/1.
//  Copyright © 2016年 heyong. All rights reserved.
//

#ifndef my_array_hpp
#define my_array_hpp

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

#define NUM 100

class Solution
{
public:
    std::vector<int> plus_one_1(std::vector<int> &digits);
    std::vector<int> plus_value(std::vector<int> &digits, int v);
    // permutations
    std::vector<std::vector<int> > permute(std::vector<int> &nums);
    
    // two sum
    std::vector<int> two_sum(std::vector<int> &nums, int target);
    
    // pow
    double my_pow(double x, int n);
    
    // Newton's Method
    double my_sqrt(double N);
    
    // best time to buy and sell stocks: one transaction
    int max_profit(std::vector<int> &prices);
    // best time to buy and sell stock II: multi transaction
    int max_profit_2(std::vector<int> &prices);
    
    // jump game I
    bool can_jump(std::vector<int> nums);
    // jump game II
    int can_jump_2(std::vector<int> nums);
    
    int largest_rectangle_area(std::vector<int> &heights);
    // O(n) excellent!
    int largest_area(std::vector<int> &histogram);
    
    int manacher(std::string &str);
    int other_manacher(std::string &str);
    
    // Dutch National Flag Problem
    void dutch_flag(std::vector<int> &flags);
    
private:
    double m_power(double x, int n);
    void m_swap(int &x, int &y);
};

void quick_sort(int nums[], int left, int right);

struct cmp1
{
    bool operator ()(int x, int y)
    {
        return x > y;
    }
};
struct cmp2
{
    bool operator ()(int x, int y)
    {
        return x < y;
    }
};

class MedianFinder
{
public:
    void addNum(int num);
    double findMedian();
    
private:
    std::priority_queue<int, std::vector<int>, std::less<int> > left_heap;
    std::priority_queue<int, std::vector<int>, std::greater<int> > right_heap;
};

class Get1ToN
{
    static int i;
    
public:
    Get1ToN()
    {
        std::cout << i++ << " ";
    }
};

template <typename T>
class Display {
public:
    void operator()(T &x)
    {
        std::cout << x << " ";
    }
};

bool is_prime(int n);
void filter_prime();

// eight queens
class EightQueen
{
public:
    static EightQueen *Instance();
    
    void eight_queen();
    void permutate(int ci[], int length, int index);
    bool check(int ci[], int length);
    void print_queen(int ci[], int length);
    
private:
    EightQueen(){}
    ~EightQueen(){}
    EightQueen(const EightQueen &);
    EightQueen &operator= (const EightQueen &);
    
    static EightQueen *m_pInstance;
    
    static int g_number;
};

#endif /* my_array_hpp */

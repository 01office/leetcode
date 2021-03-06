//
//  main.cpp
//  leetcode
//
//  Created by heyong on 16/9/1.
//  Copyright © 2016年 heyong. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

#include "my_array.hpp"
// #include "my_thread.hpp"

using namespace std;

void my_print(vector<int> &v)
{
    size_t n = v.size();
    for (size_t i = 0; i < n; ++i) {
        cout << v[i];
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    Solution solution;
    vector<int> result;
    vector<int> digits = {9, 9, 9};
    result = solution.plus_one_1(digits);
    
    my_print(result);
    
    vector<int> nums = {2, 7, 11, 15};
    vector<int> res = solution.two_sum(nums, 22);
    
    cout << solution.my_pow(5.0, 5) << endl;
    cout << solution.my_sqrt(15.0) << endl;
    
    vector<int> stocks = {2, 7, 3, 8, 25, 6};
    cout << solution.max_profit(stocks) << endl;
    cout << solution.max_profit_2(stocks) << endl;
    
    vector<int> stairs = {3, 2, 1, 1, 4};
    cout << solution.can_jump(stairs) << endl;
    
    // vector<int> heights = {2, 1, 5, 6, 2, 3};
    vector<int> heights = {6, 1, 5, 4, 5, 2, 6};
    cout << solution.largest_area(heights) << endl;
    
    priority_queue<int, vector<int>, less<int> > pq1;
    pq1.push(4);
    pq1.push(7);
    pq1.push(5);
    while (!pq1.empty()) {
        cout << pq1.top() << " ";
        pq1.pop();
    }
    cout << endl;
    
    MedianFinder mf;
    mf.addNum(6);
    cout << mf.findMedian() << endl;
    mf.addNum(5);
    mf.addNum(10);
    mf.addNum(7);
    cout << mf.findMedian() << endl;
    
    vector<int> dflags = {2, 1, 2, 0, 1, 1};
    solution.dutch_flag(dflags);
    my_print(dflags);
    
//    Get1ToN g1to100[100];
//    cout << endl;
    
    for_each(heights.begin(), heights.end(), Display<int>());
    cout << endl;
    
    vector<int> iv(heights);
    std::sort(iv.begin(), iv.end());
    std::replace(iv.begin(), iv.end(), 6, 9);
    for_each(iv.begin(), iv.end(), Display<int>());
    cout << endl;
    
    filter_prime();
    
//    EightQueen::Instance()->eight_queen();
    
    int as[] = {4, 3, 2, 1, 6, 9, 7};
    reorder_odd_even(as, 7);
    
    int ab[2][2] = {{2}, {7, 8}};
    cout << ab[0][1] << endl;   // 0
    
    return 0;
}

//
//  my_array.hpp
//  leetcode
//
//  Created by heyong on 16/9/1.
//  Copyright © 2016年 heyong. All rights reserved.
//

#ifndef my_array_hpp
#define my_array_hpp

#include <vector>

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
    
private:
    double m_power(double x, int n);
};

#endif /* my_array_hpp */

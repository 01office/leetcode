//
//  my_array.cpp
//  leetcode
//
//  Created by heyong on 16/9/1.
//  Copyright © 2016年 heyong. All rights reserved.
//

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

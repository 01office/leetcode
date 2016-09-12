//
//  main.cpp
//  leetcode
//
//  Created by heyong on 16/9/1.
//  Copyright © 2016年 heyong. All rights reserved.
//

#include <iostream>
#include <vector>

#include "my_array.hpp"

using namespace std;

void my_print(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; ++i) {
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
    
    cout << solution.my_sqrt(15.0) << endl;
    
    return 0;
}

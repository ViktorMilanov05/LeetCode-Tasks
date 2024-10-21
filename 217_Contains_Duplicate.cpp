#include <iostream>
#include <vector>
#include <algorithm>

/*Given an integer array nums, return true if any value appears at least 
    twice in the array, and return false if every element is distinct.*/

bool containsDuplicate(std::vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] == nums[i + 1])
            return true;
    }
    return false;
}

int main()
{
    std::vector<int> nums{ 1,2,3,1 };
    std::cout << containsDuplicate(nums);

}

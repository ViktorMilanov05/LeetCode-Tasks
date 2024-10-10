#include <iostream>
#include <vector>
#include <algorithm>

/*You are given two integer arrays of equal length target and arr. In one step, you can select any non-empty 
subarray of arr and reverse it. You are allowed to make any number of steps.

Return true if you can make arr equal to target or false otherwise.*/

bool canBeEqual(std::vector<int>& target, std::vector<int>& arr) {
	std::sort(target.begin(), target.end());
	std::sort(arr.begin(), arr.end());
	return target == arr;
}

int main()
{
	std::vector<int> v1 = { 7,8,3,4,15,13,4,1 };
	std::vector<int> v2 = { 7,3,15,8,4,13,4,1 };
	std::cout << canBeEqual(v1,v2) << std::endl;
}

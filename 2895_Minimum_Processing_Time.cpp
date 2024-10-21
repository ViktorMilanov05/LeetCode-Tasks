#include <iostream>
#include <vector>
#include <algorithm>

/*You have a certain number of processors, each having 4 cores.
The number of tasks to be executed is four times the number 
of processors. Each task must be assigned to a unique core, 
and each core can only be used once.

You are given an array processorTime representing the time 
each processor becomes available and an array tasks 
representing how long each task takes to complete. Return the
minimum time needed to complete all tasks.*/

int minProcessingTime(std::vector<int>& processorTime, std::vector<int>& tasks) {
    std::sort(processorTime.begin(), processorTime.end(), std::greater<int>());
    std::sort(tasks.begin(), tasks.end());
    const int CORES = 4;
    int taskInd = CORES - 1;
    int max = INT_MIN;
    for (int i = 0; i < processorTime.size(); i++) {
        int curr = processorTime[i] + tasks[taskInd];
        if (curr > max) {
            max = curr;
        }
        taskInd += CORES;
    }
    return max;
}

int main()
{
	std::vector<int> nums1{ 8 ,10 };
    std::vector<int> nums2{ 2, 2, 3, 1, 8, 7, 4 ,5};
    std::cout << minProcessingTime(nums1, nums2);
}

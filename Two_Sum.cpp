#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target) {

        std::unordered_map<int, std::vector<int>> numbers_indexes;
        for (int index = 0; index < nums.size(); index++) {
            numbers_indexes[nums[index]].push_back(index);
        }

        for (int i = 0; i < nums.size(); i++) {
            int number_to_find = target - nums[i];
            if (numbers_indexes.find(number_to_find) != numbers_indexes.end()) {
                if (nums[i] == number_to_find && numbers_indexes[number_to_find].size() >= 2) {
                    return {numbers_indexes[nums[i]][0], numbers_indexes[nums[i]][1]};
                } else if (i != numbers_indexes[number_to_find][0]) {
                    return {numbers_indexes[nums[i]][0], numbers_indexes[number_to_find][0]};
                }
            }
        }
        return {0, 0};
    }
};
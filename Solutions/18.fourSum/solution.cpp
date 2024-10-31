#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
    {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 3; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // Skip duplicates
            for (int j = i + 1; j < n - 2; ++j)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue; // Skip duplicates
                int left = j + 1, right = n - 1;
                while (left < right)
                {
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[left] + nums[right];
                    if (sum == target)
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])
                            ++left; // Skip duplicates
                        while (left < right && nums[right] == nums[right - 1])
                            --right; // Skip duplicates
                        ++left;
                        --right;
                    }
                    else if (sum < target)
                    {
                        ++left;
                    }
                    else
                    {
                        --right;
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    std::vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    int target1 = 0;
    std::vector<std::vector<int>> result1 = solution.fourSum(nums1, target1);

    std::cout << "Example 1 Output:\n";
    for (const auto &quadruplet : result1)
    {
        std::cout << "[";
        for (size_t i = 0; i < quadruplet.size(); ++i)
        {
            std::cout << quadruplet[i];
            if (i < quadruplet.size() - 1)
                std::cout << ", ";
        }
        std::cout << "]\n";
    }

    std::vector<int> nums2 = {2, 2, 2, 2, 2};
    int target2 = 8;
    std::vector<std::vector<int>> result2 = solution.fourSum(nums2, target2);

    std::cout << "Example 2 Output:\n";
    for (const auto &quadruplet : result2)
    {
        std::cout << "[";
        for (size_t i = 0; i < quadruplet.size(); ++i)
        {
            std::cout << quadruplet[i];
            if (i < quadruplet.size() - 1)
                std::cout << ", ";
        }
        std::cout << "]\n";
    }

    return 0;
}

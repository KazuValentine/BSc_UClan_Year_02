#include <vector>
#include <iostream>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        int i = 0;
        int j = 0;
        int len1 = nums1.size();
        int len2 = nums2.size();
        double tempMid = (len1 + len2) / 2.0;
        std::vector<int> nums3;
        while(i < len1 && j < len2 && nums3.size() <= tempMid)
        {
            if(nums1[i] > nums2[j])
            {
                nums3.push_back(nums2[j++]);
            }
            else
            {
                nums3.push_back(nums1[i++]);
            }
        }
        while(i < len1 && nums3.size() <= tempMid)
        {
            nums3.push_back(nums1[i++]);
        }
        while(j < len2 && nums3.size() <= tempMid)
        {
            nums3.push_back(nums2[j++]);
        }
        int mid = tempMid;
        if(mid == tempMid)
        {
            return (nums3[mid - 1] + nums3[mid]) / 2.0;
        }
        return nums3[mid];
    }
};
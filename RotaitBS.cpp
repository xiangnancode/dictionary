class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        if (num.size() == 0)
        {
            return -1;
        }
        int start = 0;
        int end = num.size() - 1;
        int mid;
        int target = num[end];
        while (start + 1 < end)
        {
            mid = start + (end - start) / 2;
            if (num[mid] <= target)
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }
        
        if (num[start] <= target)
        {
            return num[start];
        }
        if (num[end] <= target)
        {
            return num[end];
        }
        return -1;
    }
};
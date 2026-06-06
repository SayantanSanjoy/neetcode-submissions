class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        vector<int> length;
        int count = 1;

        for(int i = 0; i < nums.size()-1; i++) {

            if(nums[i+1] == nums[i]) {
                continue;
            }

            if(nums[i+1] == nums[i] + 1) {
                count++;
            }
            else {
                length.push_back(count);
                count = 1;
            }
        }

        length.push_back(count);

        return *max_element(length.begin(), length.end());
    }
};
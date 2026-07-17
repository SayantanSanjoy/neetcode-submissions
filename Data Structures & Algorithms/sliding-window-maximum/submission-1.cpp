class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> max;

        for(int left=0;left<=nums.size()-k;left++){
            int right=left+k-1;

            int maxn=-10;
            for(int i=left;i<=right;i++){
                if(nums[i]>maxn){
                    maxn=nums[i];
                }
            }
            max.push_back(maxn);
        }
        return max;
    }
};

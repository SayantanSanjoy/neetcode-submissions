class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;

        while(left<right){
            int mid=left+(right-left)/2;

            if(nums[mid]>nums[right]){
                left=mid+1;
            }else{
                right=mid;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                return i;
                break;
            }
        }
        return -1;
    }
};
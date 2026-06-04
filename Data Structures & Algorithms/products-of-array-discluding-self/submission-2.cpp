class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                product*=nums[i];
            }else{
                count++;
            }
        }
        vector<int>final(nums.size());

        for(int i=0;i<nums.size();i++){
            if(count>1){
                final[i]=0;
            }else if(count==1){
                final[i]=(nums[i]==0)?product:0;
            }else{
                final[i]=product/nums[i];
            }
        }
        return final;
    }
};

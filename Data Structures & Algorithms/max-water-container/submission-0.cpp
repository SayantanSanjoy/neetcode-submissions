class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max=0;
        int left=0;
        int right=heights.size()-1;

        while(left<right){
            
            int area;
            int base=right-left;

            area=min(heights[left],heights[right])*base;

            if(max<area){
                max=area;
                
            }else if(heights[left]<heights[right]){
                left++;
            }else{
                right--;
            }
            
        }
        return max;
    }
};

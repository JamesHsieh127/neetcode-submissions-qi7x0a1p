class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans=0, left=0, right=heights.size()-1;
        while(left<right){
            int area=min(heights[left], heights[right])*(right-left);
            ans=max(ans, area);
            if(heights[left]>heights[right]){
                right--;
            }
            else if(heights[left]<heights[right]){
                left++;
            }
            else{
                left++;
                right--;
            }
        }
        return ans;
    }
};

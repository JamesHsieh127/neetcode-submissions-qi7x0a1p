class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(), ans=0;
        vector<int> left(n, -1), right(n, n);
        stack<int> stk;
        for(int i=0; i<n; i++){
            while(!stk.empty() &&
            heights[i]<=heights[stk.top()]){
                stk.pop();
            }
            if(!stk.empty()){
                left[i]=stk.top();
            }
            stk.push(i);
        }
        stk=stack<int>();
        for(int i=n-1; i>=0; i--){
            while(!stk.empty() &&
            heights[i]<=heights[stk.top()]){
                stk.pop();
            }
            if(!stk.empty()){
                right[i]=stk.top();
            }
            stk.push(i);
        }
        for(int i=0; i<n; i++){
            ans=max(ans, heights[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
};

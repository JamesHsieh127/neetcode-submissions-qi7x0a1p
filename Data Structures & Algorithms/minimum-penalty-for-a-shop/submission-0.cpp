class Solution {
public:
    int bestClosingTime(string customers) {
        int ans=0, sumY=0, sumN=0, n=customers.size();
        for(char& c:customers){
            if(c=='Y') sumY++;
        }
        int penalty=sumY;
        for(int i=0; i<n; i++){
            if(customers[i]=='N') sumN++;
            else sumY--;
            if(sumY+sumN<penalty){
                penalty=sumY+sumN;
                ans=i+1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n=nums.size(), maxVal=INT_MIN;
        if(n==1) return true;
        for(int& x:nums){
            if(x==1) return false;
            maxVal=max(maxVal, x);
        }
        vector<int> minPrime(maxVal+1, 0);
        for(int i=2; i<=maxVal; i++){
            minPrime[i]=i;
        }
        for(int i=2; i*i<=maxVal; i++){
            if(minPrime[i]==i){
                for(int j=i*i; j<=maxVal; j+=i){
                    if(minPrime[j]==j){
                        minPrime[j]=i;
                    }
                }
            }
        }
        int total = n + maxVal + 1;
        vector<int> parent(total);
        for (int i = 0; i < total; i++) parent[i] = i;

        auto find = [&](auto& self, int i) -> int {
            return parent[i] == i ? i : parent[i] = self(self, parent[i]);
        };

        auto unite = [&](int i, int j) {
            int root_i = find(find, i);
            int root_j = find(find, j);
            if (root_i != root_j) {
                parent[root_i] = root_j;
            }
        };
        for (int i = 0; i < n; i++) {
            int temp = nums[i];
            while (temp > 1) {
                int p = minPrime[temp];
                unite(i, n + p);
                while (temp % p == 0) {
                    temp /= p;
                }
            }
        }
        int root = find(find, 0);
        for (int i = 1; i < n; i++) {
            if (find(find, i) != root) {
                return false;
            }
        }

        return true;
    }
};
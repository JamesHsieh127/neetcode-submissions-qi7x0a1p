class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        int n=position.size();
        for(int i=0; i<n; i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());
        stack<double> stk;
        for(int i=0; i<n; i++){
            double t=(double)(target-cars[i].first)/cars[i].second;
            while(!stk.empty() &&
            stk.top()<=t){
                stk.pop();
            }
            stk.push(t);
        }
        return stk.size();
    }
};
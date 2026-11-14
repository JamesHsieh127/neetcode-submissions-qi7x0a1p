class FoodRatings {
public:
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRate;
    unordered_map<string, set<pair<int,string>>> cuisineToRate;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0; i<n; i++){
            foodToCuisine[foods[i]]=cuisines[i];
            foodToRate[foods[i]]=ratings[i];
            cuisineToRate[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    void changeRating(string food, int newRating) {
        string cuisine=foodToCuisine[food];
        int oldRate=foodToRate[food];
        cuisineToRate[cuisine].erase({-oldRate, food});
        foodToRate[food]=newRating;
        cuisineToRate[cuisine].insert({-newRating, food});
    }
    string highestRated(string cuisine) {
        return cuisineToRate[cuisine].begin()->second;
    }
};

 struct cmp{
        bool operator()(pair<int, string>a, pair<int, string>b)const{
            if(a.first>b.first) return 1;
            if(a.first<b.first) return 0;
            return a.second <b.second;
        }
    };

class FoodRatings {
public:    
     // cuisine to <rating and food>   /--> store in ma in descending order in set so from begin we get highest rating 
        unordered_map<string, set<pair<int, string>, cmp>>cuisToFood;
       
        // food to <cuisine, rating> 
        unordered_map<string, pair<string, int>>foodToCuis;
        
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
         int n= foods.size();
        for(int i=0; i<n; i++){
           cuisToFood[cuisines[i]].insert({ratings[i], foods[i]});
           foodToCuis[foods[i]] ={cuisines[i], ratings[i]}; 
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuis[food].first;
        int oldRating = foodToCuis[food].second;
        cuisToFood[cuisine].erase({oldRating, food});
        
        // add new ratings 
        foodToCuis[food] = {cuisine, newRating};
        cuisToFood[cuisine].insert({newRating, food});
        
    }
    
    string highestRated(string cuisine) {
        return (*cuisToFood[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
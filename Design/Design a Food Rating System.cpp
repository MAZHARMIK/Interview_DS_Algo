/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=SF13GD8FPxM
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/design-a-food-rating-system/
*/

/**************************************** C++ ****************************************/
//Using maps/set as requirement
/*T.C -
FoodRatings - O(n)
changeRating - log(n) due to erase function used in ordered_set
highestRated - O(1)
S.C - O(n) in all maps
*/
class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>>> cuisine_ratings_food;
    unordered_map<string, string> food_cuisine;
    unordered_map<string, int> food_rating;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        
        for(int i = 0; i<n; i++) {
            string food    = foods[i];
            string cuisine = cuisines[i];
            int rating     = ratings[i];
            
            cuisine_ratings_food[cuisine].insert({-rating, food});
            food_cuisine[food] = cuisine;
            food_rating[food]  = rating;
            
            
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food_cuisine[food];
        int oldRating  = food_rating[food];
        
        cuisine_ratings_food[cuisine].erase({-oldRating, food});
        cuisine_ratings_food[cuisine].insert({-newRating, food});
        food_rating[food] = newRating;
        
    }
    
    string highestRated(string cuisine) {
        return begin(cuisine_ratings_food[cuisine])->second; 
        
        //first item will have highest absolute rating "we put all ratings in negative" (ordered_set)
        //Why did we not put them in ascending order and just return the last element of ordered_set ?
        //Ans : Because We can have a case like below
        //{(15, abc), (16, ramen), (16, sushi)} -> Order in ordered_set. last element is not lexicographically smaller
        //{(-16, ramen), (-16, sushi), (-15, abc)} -> First element is now lexicographically smaller
    }
};



/**************************************** JAVA ****************************************/
//Using maps/set as requirement
/*T.C -
FoodRatings - O(n)
changeRating - log(n) due to erase function used in ordered_set
highestRated - O(1)
S.C - O(n) in all maps
*/
public class FoodRatings {
    private Map<String, Integer> food_rating = new HashMap<>();
    private Map<String, String> food_cuisine = new HashMap<>();
    private Map<String, TreeSet<Pair<Integer, String>>> cuisine_ratings_food = new HashMap<>();

    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        for (int i = 0; i < foods.length; ++i) {
            food_rating.put(foods[i], ratings[i]);
            food_cuisine.put(foods[i], cuisines[i]);

            cuisine_ratings_food
                .computeIfAbsent(cuisines[i], k -> new TreeSet<>((a, b) -> {
                    int compareByRating = Integer.compare(a.getKey(), b.getKey());
                    if (compareByRating == 0) {
                        return a.getValue().compareTo(b.getValue());
                    }
                    return compareByRating;
                }))
                .add(new Pair(-ratings[i], foods[i]));
        }
    }

    public void changeRating(String food, int newRating) {
        String cuisineName = food_cuisine.get(food);
        TreeSet<Pair<Integer, String>> cuisineSet = cuisine_ratings_food.get(cuisineName);
        Pair<Integer, String> oldElement = new Pair<>(-food_rating.get(food), food);
        cuisineSet.remove(oldElement);
        food_rating.put(food, newRating);
        cuisineSet.add(new Pair<>(-newRating, food));
    }

    public String highestRated(String cuisine) {
        Pair<Integer, String> highestRated = cuisine_ratings_food.get(cuisine).first();
        return highestRated.getValue();
    }
}

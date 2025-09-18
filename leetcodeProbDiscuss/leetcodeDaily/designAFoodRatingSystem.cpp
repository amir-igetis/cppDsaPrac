#include <bits/stdc++.h>
using namespace std;

class FoodRatings
{
private:
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;

    struct Food
    {
        int rating;
        string name;
        bool operator<(const Food &other) const
        {
            if (rating != other.rating)
                return rating < other.rating; // higher rating first
            return name > other.name;         // lexicographically smaller first
        }
    };

    unordered_map<string, priority_queue<Food>> cuisineToHeap;

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        int n = foods.size();
        for (int i = 0; i < n; i++)
        {
            string f = foods[i];
            string c = cuisines[i];
            int r = ratings[i];

            foodToCuisine[f] = c;
            foodToRating[f] = r;
            cuisineToHeap[c].push({r, f});
        }
    }

    void changeRating(string food, int newRating)
    {
        foodToRating[food] = newRating;
        string cuisine = foodToCuisine[food];
        cuisineToHeap[cuisine].push({newRating, food});
    }

    string highestRated(string cuisine)
    {
        auto &pq = cuisineToHeap[cuisine];
        while (!pq.empty())
        {
            Food top = pq.top();
            if (foodToRating[top.name] == top.rating)
            {
                return top.name;
            }
            pq.pop(); // outdated entry
        }
        return "";
    }
};

int main()
{
    vector<string> foods = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> cuisines = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vector<int> ratings = {9, 12, 8, 15, 14, 7};

    FoodRatings *obj = new FoodRatings(foods, cuisines, ratings);
    cout << obj->highestRated("korean") << endl;   // "kimchi"
    cout << obj->highestRated("japanese") << endl; // "ramen"
    obj->changeRating("sushi", 16);
    cout << obj->highestRated("japanese") << endl; // "sushi"
    obj->changeRating("ramen", 16);
    cout << obj->highestRated("japanese") << endl; // "ramen"

    delete obj;
    return 0;
}

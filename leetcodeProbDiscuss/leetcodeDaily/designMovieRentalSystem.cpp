#include <bits/stdc++.h>
using namespace std;

class MovieRentingSystem
{
    struct MovieInfo
    {
        int price, shop, movie;
        bool operator<(const MovieInfo &other) const
        {
            if (price != other.price)
                return price < other.price;
            if (shop != other.shop)
                return shop < other.shop;
            return movie < other.movie;
        }
    };

    // price lookup: {shop, movie} -> price
    unordered_map<long long, int> priceMap;

    // unrented: movie -> set<{price, shop}>
    unordered_map<int, set<pair<int, int>>> unrented;

    // rented movies globally
    set<MovieInfo> rented;

    long long encode(int shop, int movie)
    {
        return ((long long)shop << 32) | movie;
    }

public:
    MovieRentingSystem(int n, vector<vector<int>> &entries)
    {
        for (auto &e : entries)
        {
            int shop = e[0], movie = e[1], price = e[2];
            priceMap[encode(shop, movie)] = price;
            unrented[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie)
    {
        vector<int> ans;
        if (unrented.count(movie))
        {
            auto &s = unrented[movie];
            int k = 0;
            for (auto &p : s)
            {
                if (k == 5)
                    break;
                ans.push_back(p.second); // shop
                k++;
            }
        }
        return ans;
    }

    void rent(int shop, int movie)
    {
        int price = priceMap[encode(shop, movie)];
        unrented[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie)
    {
        int price = priceMap[encode(shop, movie)];
        rented.erase({price, shop, movie});
        unrented[movie].insert({price, shop});
    }

    vector<vector<int>> report()
    {
        vector<vector<int>> ans;
        int k = 0;
        for (auto &info : rented)
        {
            if (k == 5)
                break;
            ans.push_back({info.shop, info.movie});
            k++;
        }
        return ans;
    }
};

// assume your MovieRentingSystem class is already defined above

int main()
{
    vector<vector<int>> entries = {
        {0, 1, 5}, {0, 2, 6}, {0, 3, 7}, {1, 1, 4}, {1, 2, 7}, {2, 1, 5}};

    MovieRentingSystem movieSystem(3, entries);

    // search movie 1
    vector<int> res1 = movieSystem.search(1);
    cout << "Search(1): ";
    for (int x : res1)
        cout << x << " ";
    cout << endl;

    // rent (0,1)
    movieSystem.rent(0, 1);

    // rent (1,2)
    movieSystem.rent(1, 2);

    // report
    vector<vector<int>> report1 = movieSystem.report();
    cout << "Report: ";
    for (auto &v : report1)
    {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    cout << endl;

    // drop (1,2)
    movieSystem.drop(1, 2);

    // search movie 2
    vector<int> res2 = movieSystem.search(2);
    cout << "Search(2): ";
    for (int x : res2)
        cout << x << " ";
    cout << endl;

    return 0;
}

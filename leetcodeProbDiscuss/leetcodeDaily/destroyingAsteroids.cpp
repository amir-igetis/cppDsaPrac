#include <bits/stdc++.h>
using namespace std;

bool asteroidsDestroyed(int mass, vector<int> &asteroids)
{
    sort(asteroids.begin(), asteroids.end());
    long currMass = mass;
    for (auto &i : asteroids)
    {

        if (mass < i)
            return false;
    }
    return true;
}

int main()
{
    int mass = 10;
    vector<int> asteroids = {3, 9, 19, 5, 21};
    cout << (asteroidsDestroyed(mass, asteroids) ? "True" : "False") << endl;

    return 0;
}
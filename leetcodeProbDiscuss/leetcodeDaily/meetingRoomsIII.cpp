#include <bits/stdc++.h>
using namespace std;

// sorting and counting
int mostBooked(int n, vector<vector<int>> &meetings)
{
    vector<long long> roomAvailabilityTime(n, 0);
    vector<int> meetingCount(n, 0);
    sort(meetings.begin(), meetings.end());

    for (auto &meeting : meetings)
    {
        int start = meeting[0], end = meeting[1];
        long long minRoomAvailabilityTime = LLONG_MAX;
        int minAvailableTimeRoom = 0;
        bool foundUnusedRoom = false;

        for (int i = 0; i < n; i++)
        {
            if (roomAvailabilityTime[i] <= start)
            {
                foundUnusedRoom = true;
                meetingCount[i]++;
                roomAvailabilityTime[i] = end;
                break;
            }

            if (minRoomAvailabilityTime > roomAvailabilityTime[i])
            {
                minRoomAvailabilityTime = roomAvailabilityTime[i];
                minAvailableTimeRoom = i;
            }
        }

        if (!foundUnusedRoom)
        {
            roomAvailabilityTime[minAvailableTimeRoom] += end - start;
            meetingCount[minAvailableTimeRoom]++;
        }
    }
    int maxMeetingCount = 0, maxMeetingCountRoom = 0;
    for (int i = 0; i < n; i++)
    {
        if (meetingCount[i] > maxMeetingCount)
        {
            maxMeetingCount = meetingCount[i];
            maxMeetingCountRoom = i;
        }
    }
    return maxMeetingCountRoom;
}

// sorting and priority queue
int mostBookedI(int n, vector<vector<int>> &meetings)
{
    vector<int> meetingCount(n, 0);

    priority_queue<pair<long long, int>,
                   vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        usedRooms;

    priority_queue<int, vector<int>, greater<int>> unusedRooms;

    for (int i = 0; i < n; i++)
        unusedRooms.push(i);

    sort(meetings.begin(), meetings.end());

    for (int i = 0; i < meetings.size(); i++)
    {
        int start = meetings[i][0];
        int end = meetings[i][1];

        while (!usedRooms.empty() && usedRooms.top().first <= start)
        {
            unusedRooms.push(usedRooms.top().second);
            usedRooms.pop();
        }

        if (!unusedRooms.empty())
        {
            int room = unusedRooms.top();
            unusedRooms.pop();

            usedRooms.push(make_pair((long long)end, room));
            meetingCount[room]++;
        }
        else
        {
            // auto [availableTime, room] = usedRooms.top();
            pair<long long, int> topRoom = usedRooms.top();
            usedRooms.pop();

            long long availableTime = topRoom.first;
            int room = topRoom.second;

            long long newEndTime = availableTime + (end - start);
            usedRooms.push(make_pair(newEndTime, room));

            meetingCount[room]++;
        }
    }

    int maxRoom = 0;
    for (int i = 1; i < n; i++)
    {
        if (meetingCount[i] > meetingCount[maxRoom])
            maxRoom = i;
    }

    return maxRoom;
}

int main()
{
    vector<vector<int>> meetings = {{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}};
    int n = 3;
    cout << mostBookedI(n, meetings) << endl;

    return 0;
}
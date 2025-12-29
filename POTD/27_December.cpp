// brute m*n 
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end());

        vector<int> meetings_count(n, 0);

        map<int, long long> mp;

        for (int i = 0; i < n; i++) {
            mp[i] = 0;
        }

        for (auto& i : meetings) {
            int start_i = i[0];
            int end_i = i[1];

            bool wait = true;
            for (auto& it : mp) {
                if (it.second <= start_i) {
                    it.second = end_i;
                    meetings_count[it.first]++;
                    wait = false;
                    break;
                }
            }

            if (wait == true) {
                long long  mini = LLONG_MAX;
                int meeting_room = -1;
                for (auto& it : mp) {
                    if (mini > it.second) {
                        mini = it.second;
                        meeting_room = it.first;
                    }
                }
                meetings_count[meeting_room]++;
                mp[meeting_room] = mini + (end_i - start_i);
            }
        }

        int maxi_meetings = 0;
        int ans_room = 0;
        for (int i = 0; i < n; i++) {
            int curr_meetings = meetings_count[i];
            if (curr_meetings > maxi_meetings) {
                maxi_meetings = curr_meetings;
                ans_room = i;
            }
        }
        return ans_room;
    }
};

// optimal using heap O(nlogm)
class Solution {
public:
    typedef pair<long long, int> P;
    int mostBooked(int n, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end());

        vector<int> meetings_count(n, 0);

        priority_queue<P, vector<P>, greater<P>> usedRooms;

        priority_queue<int, vector<int>, greater<int>> roomsAvailable;

        for (int i = 0; i < n; i++) {
            roomsAvailable.push(i);
        }

        for (auto& i : meetings) {
            int start = i[0];
            int end = i[1];

            while (!usedRooms.empty() && usedRooms.top().first <= start) {
                int room = usedRooms.top().second;
                usedRooms.pop();
                roomsAvailable.push(room);
            }

            if (!roomsAvailable.empty()) {
                int room = roomsAvailable.top();
                roomsAvailable.pop();
                usedRooms.push({end, room});
                meetings_count[room]++;
            } else { // roomsAvailable == empty so now its pop time for used
                     // room
                int room = usedRooms.top().second;
                long long time = usedRooms.top().first;

                usedRooms.pop();
                usedRooms.push({time + (end - start), room});
                meetings_count[room]++;
            }
        }

        int maxi_meetings = 0;
        int ans_room = 0;
        for (int i = 0; i < n; i++) {
            int curr_meetings = meetings_count[i];
            if (curr_meetings > maxi_meetings) {
                maxi_meetings = curr_meetings;
                ans_room = i;
            }
        }
        return ans_room;
    }
};
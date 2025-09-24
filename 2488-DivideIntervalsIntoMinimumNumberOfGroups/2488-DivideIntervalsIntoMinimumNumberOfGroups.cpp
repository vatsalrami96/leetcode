// Last updated: 9/24/2025, 2:16:21 AM
class Solution {
public:
    class Interval {
    public:
        int startTime;
        int endTime;

        Interval(int start, int end) : startTime(start), endTime(end) {}
    };

    int minGroups(vector<vector<int>>& intervals) {
        // Create a list of Interval objects
        vector<Interval> sortedIntervals;
        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            sortedIntervals.push_back(Interval(start, end));
        }

        // Sort intervals based on the start time
        sort(sortedIntervals.begin(), sortedIntervals.end(), [](const Interval& a, const Interval& b) {
            return a.startTime < b.startTime;
        });

        // Min-heap to track the earliest end times
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int maxGroups = 0;

        for (const auto& interval : sortedIntervals) {
            int start = interval.startTime;
            int end = interval.endTime;

            // Remove intervals from the heap that have already ended
            while (!minHeap.empty() && minHeap.top() < start) {
                minHeap.pop();
            }

            // Add the current interval's end time to the heap
            minHeap.push(end);

            // Update the maximum number of overlapping intervals
            maxGroups = max(maxGroups, static_cast<int>(minHeap.size()));
        }

        return maxGroups;
    }
};

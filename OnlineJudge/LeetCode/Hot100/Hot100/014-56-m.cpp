#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        for (auto ve : intervals) {
            pq.push(ve);
        }
        while (pq.size() > 1) {
            vector<int>top = pq.top();
            pq.pop();
            vector<int>sec = pq.top();
            pq.pop();
            if (top[1] < sec[0]) {
                ans.push_back(top);
                pq.push(sec);
            }
            else if (top[1] > sec[1]) {
                pq.push(top);
            }
            else {
                vector<int>now;
                now.push_back(top[0]);
                now.push_back(sec[1]);
                pq.push(now);
            }
        }
        ans.push_back(pq.top());
        return ans;
    }
private:
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
    vector<vector<int>>ans;
};

// Problem: Kth largest in array
//  Time Complexity : O(nlog(n-k))
//  Space Complexity : O(n-k) where k is the size of the heap
//  Did this code successfully run on Leetcode : Yes
//  Any problem you faced while coding this : No

// Your code here along with comments explaining your approach in three
// sentences only
// 1. We can declare a min heap or max heap, here we have declared max heap
// 2. We start pushing our elements in the heap and once the heap size is above
// n - k, the
// rest of the elements will be potential candidates for our solution
// 3. So we compare the min values out of those, and in the end return res;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    int n = (int)nums.size();
    priority_queue<int> pq;
    int res = INT_MAX;
    for (auto num : nums) {
      pq.push(num); // logk
      if (pq.size() > n - k) {
        res = min(res, pq.top());
        pq.pop();
      }
    }

    // time complexity is nlogk since we are maintaining n-k size heap only at
    // all times
    return res;
  }

  int findKthLargestWithMinHeap(vector<int> &nums, int k) {
    int n = (int)nums.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto num : nums) {
      pq.push(num); // logk
      if (pq.size() > k) {
        pq.pop();
      }
    }
    // time complexity is nlogk since we are maintaining k size heap only at all
    // times
    return pq.top();
  }
};

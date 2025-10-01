
// Problem: Merge k sorted lists
//  Time Complexity : O(nlogk)
//  Space Complexity : O(k) where k is the size of the heap
//  Did this code successfully run on Leetcode : Yes
//  Any problem you faced while coding this : No

// Your code here along with comments explaining your approach in three
// sentences only
// 1. We start with min heap with custom comparator, and insert all ListNodes in
// the heap
// 2. We start removing the top element since it will be holding the min value
// and attach to our dummy node
// 3. In the end, we return dummy->next

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct compare {
public:
  bool operator()(ListNode *a, ListNode *b) {
    if (!a)
      return true;
    if (!b)
      return false;
    return a->val > b->val;
  }
};

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<ListNode *, vector<ListNode *>, compare> pq;
    ListNode *dummy = new ListNode(-1);
    ListNode *curr = dummy;
    for (auto it : lists) {
      pq.push(it);
    }
    while (!pq.empty()) {
      ListNode *val = pq.top();
      pq.pop();
      if (val) {
        pq.push(val->next);
      }
      if (curr) {
        curr->next = val;
        curr = curr->next;
      }
    }
    return dummy->next;
  }
};

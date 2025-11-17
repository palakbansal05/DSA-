class Solution{
public:
    int findKthSmallest(const vector<int>& nums, int k) {
        priority_queue<int> maxHeap; // max-heap

        for (int num : nums) {
            maxHeap.push(num); // insert into max-heap
            if (maxHeap.size() > k) {
                maxHeap.pop(); // remove largest element
            }
        }
        return maxHeap.top(); // kth smallest element
    }
};
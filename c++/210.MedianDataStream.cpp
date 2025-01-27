/* https://leetcode.com/problems/find-median-from-data-stream/description/
295. Find Median from Data Stream

The median is the middle value in an ordered integer list. If the size of the
list is even, there is no middle value, and the median is the mean of the two
middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

Implement the MedianFinder class:
MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data
structure. double findMedian() returns the median of all elements so far.
Answers within 10-5 of the actual answer will be accepted.


Example 1:
Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0


Constraints:
-105 <= num <= 105
There will be at least one element in the data structure before calling
findMedian. At most 5 * 104 calls will be made to addNum and findMedian.


Follow up:
If all integer numbers from the stream are in the range [0, 100], how would you
optimize your solution? If 99% of all integer numbers from the stream are in the
range [0, 100], how would you optimize your solution?
*/

/* The idea is to divide numbers into 2 balanced halves, one half `low` stores
low numbers, the other half `high` stores high numbers. To access the median in
`O(1)`, we need a data structure that give us the maximum of `low` half and the
minimum of `high` half in O(1). That's where `maxHeap` and `minHeap` come into
play. We use `maxHeap` to store a half of `low` numbers, top of the maxHeap is
the highest number among low numbers. We use `minHeap` to store a half of `high`
numbers, top of the minHeap is the lowest number among high numbers. We need to
balance the size between maxHeap and minHeap while processing. Hence after
adding k elements,
- If (k = 2 * i) { maxHeap.size = minHeap.size = i}
- If (k = 2 * i + 1){ let maxHeap store 1 element more than minHeap, then
maxHeap.size = minHeap.size + 1.} When adding a new number num into our
MedianFinder:
- Firstly, add num to the maxHeap, now maxHeap may contain the big element
(which should belong to minHeap). So we need to balance, by removing the highest
element from maxHeap, and offer it to minHeap.
- Now, the minHeap might hold more elements than maxHeap, in that case, we need
to balance the size, by removing the lowest element from minHeap and offer it
back to maxHeap. When doing findMedian():
- If maxHeap.size > minHeap.size return top of the maxHeap, which is the highest
number amongs low numbers.
- Else if maxHeap.size == minHeap return the (maxHeap.top() + minHeap.top())
/ 2.
*/
#include <queue>
using namespace std;

class MedianFinder {
public:
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;

  MedianFinder() {}
  void addNum(int num) {
    maxHeap.push(num);
    minHeap.push(maxHeap.top());
    maxHeap.pop();
    if (minHeap.size() > maxHeap.size()) {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }
  }
  double findMedian() {
    if (maxHeap.size() > minHeap.size())
      return maxHeap.top();
    return (maxHeap.top() + minHeap.top()) / 2.0;
  }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 */
int main() {
  MedianFinder* obj = new MedianFinder();
  obj->addNum(num);
  double param_2 = obj->findMedian();
  return 0;
}
// 50%
// sub:
// https://leetcode.com/problems/find-median-from-data-stream/submissions/1522309774/
// sol:
// https://leetcode.com/problems/find-median-from-data-stream/solutions/6336339/295-find-median-from-data-stream50-by-na-0cp1/

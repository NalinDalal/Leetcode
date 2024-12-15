/* 1792. Maximum Average Pass Ratio

There is a school that has classes of students and each class will be having a
final exam. You are given a 2D integer array classes, where classes[i] = [passi,
totali]. You know beforehand that in the ith class, there are totali total
students, but only passi number of students will pass the exam.

You are also given an integer extraStudents. There are another extraStudents
brilliant students that are guaranteed to pass the exam of any class they are
assigned to. You want to assign each of the extraStudents students to a class in
a way that maximizes the average pass ratio across all the classes.

The pass ratio of a class is equal to the number of students of the class that
will pass the exam divided by the total number of students of the class. The
average pass ratio is the sum of pass ratios of all the classes divided by the
number of the classes.

Return the maximum possible average pass ratio after assigning the extraStudents
students. Answers within 10-5 of the actual answer will be accepted.



Example 1:
Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
Output: 0.78333
Explanation: You can assign the two extra students to the first class. The
average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.

Example 2:
Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
Output: 0.53485


Constraints:

1 <= classes.length <= 10^5
classes[i].length == 2
1 <= passi <= totali <= 10^5
1 <= extraStudents <= 10^5
*/

// what to do:
// 1. sort classes by totali{classes[i]=[passi, totali]}
// if totali==1, return 1.0
// 2. for each extraStudents,find class with max totali
// 3. pass ratio=pass/total
// 4. max pass ratio=max(pass ratio of class with max total)
// 5. find max pass ratio
// 6. return max pass ratio

#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    // Define a lambda for calculating the gain in pass ratio by adding one
    // student
    auto passGain = [](int pass, int total) -> double {
      return (double)(pass + 1) / (total + 1) - (double)pass / total;
    };

    // Max heap to store the classes by their potential gain in pass ratio
    priority_queue<pair<double, pair<int, int>>> maxHeap;

    // Populate the heap with initial pass gains for all classes
    for (const auto& c : classes) {
      int pass = c[0], total = c[1];
      maxHeap.push({passGain(pass, total), {pass, total}});
    }

    // Distribute the extra students
    while (extraStudents > 0) {
      auto [gain, classInfo] = maxHeap.top();
      maxHeap.pop();

      int pass = classInfo.first;
      int total = classInfo.second;

      // Add one student to the class with the max gain
      pass++;
      total++;
      extraStudents--;

      // Recalculate the gain and push the updated class back to the heap
      maxHeap.push({passGain(pass, total), {pass, total}});
    }

    // Calculate the final average pass ratio
    double totalRatio = 0.0;
    while (!maxHeap.empty()) {
      auto [gain, classInfo] = maxHeap.top();
      maxHeap.pop();

      int pass = classInfo.first;
      int total = classInfo.second;

      totalRatio += (double)pass / total;
    }

    return totalRatio / classes.size();
  }
};

// 85.47% correct
/* Time complexity:O(klogn)
{Heap operations (push and pop): 𝑂(log ⁡𝑛), repeated 𝑘 times (for
extraStudents)}

Space complexity: O(n) for heap*/

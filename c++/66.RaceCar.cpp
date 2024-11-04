/* 818. Race Car

Your car starts at position 0 and speed +1 on an infinite number line. Your car
can go into negative positions. Your car drives automatically according to a
sequence of instructions 'A' (accelerate) and 'R' (reverse):

When you get an instruction 'A', your car does the following:
position += speed
speed *= 2
When you get an instruction 'R', your car does the following:
If your speed is positive then speed = -1 otherwise speed = 1 Your position
stays the same.

For example, after commands "AAR", your car goes to positions 0 --> 1 --> 3 -->
3, and your speed goes to 1 --> 2 --> 4 --> -1.

Given a target position target, return the length of the shortest sequence of
instructions to get there.

Example 1:
Input: target = 3
Output: 2
Explanation:
The shortest instruction sequence is "AA".
Your position goes from 0 --> 1 --> 3.

Example 2:
Input: target = 6
Output: 5
Explanation:
The shortest instruction sequence is "AAARA".
Your position goes from 0 --> 1 --> 3 --> 7 --> 7 --> 6.


Constraints:

1 <= target <= 10^4.
*/

/*
well always start with accelerating the car
keep position and speed=0

    get a fucking instruction
once instruction is set to A -> position += speed;speed *= 2;
instruction set to R-> speed is positive then speed = -1;otherwise speed = 1;

return speed;

*/
// certainly i am missing an angle here
// we don't want speed at last
// we want the length of shortest sequence
/*angle-> The variable instruction is declared but never assigned any value, so
the conditionals using instruction are undefined. The logic in the function
doesn't solve the problem of reaching a specific target. It only modifies speed
and position based on hypothetical instructions but doesn't implement a loop or
mechanism to handle the racecar's journey toward the target. The return value of
the function is only the speed, but based on the function's signature, you
likely want to return the minimum number of steps to reach the target, not just
the speed.*/

/*correct approach to solving the "Racecar" problem using BFS (Breadth-First
 * Search). This approach aims to calculate the minimum number of commands (A
 * for accelerate, R for reverse) required for the racecar to reach the target
 * position starting from position 0 and speed 1.*/

/*
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int racecar(int target) {
    // Each state is represented as (position, speed, steps)
    using State = std::tuple<int, int, int>;
    std::queue<State> q;
    std::unordered_set<std::string> visited;

    // Start at position 0, speed 1, with 0 steps taken
    q.push({0, 1, 0});
    visited.insert("0,1");

    while (!q.empty()) {
      auto [position, speed, steps] = q.front();
      q.pop();

      // If we reach the target, return the number of steps
      if (position == target) {
        return steps;
      }

      // Accelerate: next position increases by speed, speed doubles
      int nextPosA = position + speed;
      int nextSpeedA = speed * 2;
      std::string stateA =
          std::to_string(nextPosA) + "," + std::to_string(nextSpeedA);

      if (abs(nextPosA) <= 2 * target &&
          visited.find(stateA) == visited.end()) {
        visited.insert(stateA);
        q.push({nextPosA, nextSpeedA, steps + 1});
      }

      // Reverse: speed changes direction (if positive to -1, if negative to 1)
      int nextSpeedR = speed > 0 ? -1 : 1;
      std::string stateR =
          std::to_string(position) + "," + std::to_string(nextSpeedR);

      if (visited.find(stateR) == visited.end()) {
        visited.insert(stateR);
        q.push({position, nextSpeedR, steps + 1});
      }
    }

    return -1; // This should never be reached
  }
};

int main() {
  Solution solution;
  int target1 = 3;
  int answer1 = solution.racecar(target1);
  cout << answer1 << endl;

  if (answer1 == 2) {
    return true;
  }
  cout << endl;
  cout << endl;

  int target2 = 6;
  int answer2 = solution.racecar(target2);
  cout << answer2 << endl;
  if (answer2 == 6) {
    return true;
  }

  return 0;
}*/

#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int racecar(int target) {
    // Each state is represented as (position, speed, steps)
    using State = std::tuple<int, int, int>;
    std::queue<State> q;
    std::unordered_set<std::string> visited;

    // Start at position 0, speed 1, with 0 steps taken
    q.push({0, 1, 0});
    visited.insert("0,1");

    while (!q.empty()) {
      auto [position, speed, steps] = q.front();
      q.pop();

      // If we reach the target, return the number of steps
      if (position == target) {
        return steps;
      }

      // Accelerate: next position increases by speed, speed doubles
      int nextPosA = position + speed;
      int nextSpeedA = speed * 2;
      std::string stateA =
          std::to_string(nextPosA) + "," + std::to_string(nextSpeedA);

      if (abs(nextPosA) <= 2 * target &&
          visited.find(stateA) == visited.end()) {
        visited.insert(stateA);
        q.push({nextPosA, nextSpeedA, steps + 1});
      }

      // Reverse: speed changes direction (if positive to -1, if negative to 1)
      int nextSpeedR = speed > 0 ? -1 : 1;
      std::string stateR =
          std::to_string(position) + "," + std::to_string(nextSpeedR);

      if (visited.find(stateR) == visited.end()) {
        visited.insert(stateR);
        q.push({position, nextSpeedR, steps + 1});
      }
    }

    return -1; // This should never be reached
  }
};

int main() {
  Solution solution;

  // Test with target1 = 3
  int target1 = 3;
  int answer1 = solution.racecar(target1);
  cout << "Steps for target " << target1 << ": " << answer1 << endl;

  if (answer1 == 2) {
    return true; // Assuming you wanted to exit when this condition is true
  }

  cout << endl;

  // Test with target2 = 6
  int target2 = 6;
  int answer2 = solution.racecar(target2);
  cout << "Steps for target " << target2 << ": " << answer2 << endl;

  if (answer2 == 6) {
    return true; // Assuming you wanted to exit when this condition is true
  }

  return 0;
}

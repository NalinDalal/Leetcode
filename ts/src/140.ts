//134. Gas Station
function canCompleteCircuit(gas: number[], cost: number[]): number {
  let n = gas.length;
  let total_tank = 0,
    currentTank = 0,
    start = 0;
  for (let i = 0; i < n; i++) {
    total_tank += gas[i] - cost[i];
    currentTank += gas[i] - cost[i];
    if (currentTank < 0) {
      //can't reach next station
      start = i + 1; //start from next station
      currentTank = 0; //reset current tank
    }
  }
  //if total_tank is non-negative return startIndex
  return total_tank >= 0 ? start : -1;
}
//sub: https://leetcode.com/problems/gas-station/submissions/1560980914/
//sol: https://leetcode.com/problems/gas-station/solutions/6488419/134-gas-station-by-nalindalal2004-n2ug/

//2300. Successful Pairs of Spells and Potions
function successfulPairs(
  spells: number[],
  potions: number[],
  success: number,
): number[] {
  potions.sort((a, b) => a - b);
  const m = potions.length;
  const res: number[] = [];

  for (const spell of spells) {
    const minPotion = Math.ceil(success / spell);

    // Binary search for the first potion >= minPotion
    let left = 0,
      right = m - 1,
      idx = m;
    while (left <= right) {
      const mid = Math.floor((left + right) / 2);
      if (potions[mid] >= minPotion) {
        idx = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    res.push(m - idx); // number of successful potions
  }

  return res;
}

//sub: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/submissions/1794950306/?envType=daily-question&envId=2025-10-08
//sol: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/solutions/7258068/2300-successful-pairs-of-spells-and-poti-uewb/

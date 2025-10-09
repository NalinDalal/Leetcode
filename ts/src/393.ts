//3494. Find the Minimum Amount of Time to Brew Potions
function minTime(skill: number[], mana: number[]): number {
  const n = skill.length;
  const m = mana.length;
  const f = new Array<number>(n).fill(0);

  for (let j = 0; j < m; ++j) {
    const x = mana[j];
    let now = f[0];

    // forward pass
    for (let i = 1; i < n; ++i) {
      now = Math.max(now + skill[i - 1] * x, f[i]);
    }

    // last wizard finishes this potion
    f[n - 1] = now + skill[n - 1] * x;

    // backward pass to update earlier wizards
    for (let i = n - 2; i >= 0; --i) {
      f[i] = f[i + 1] - skill[i + 1] * x;
    }
  }

  return f[n - 1];
}

//sub: https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/submissions/1795932962/?envType=daily-question&envId=2025-10-09
//sol: https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/solutions/7260546/3494-find-the-minimum-amount-of-time-to-tm0o9/

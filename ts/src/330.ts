//2561. Rearranging Fruits
function minCost(basket1: number[], basket2: number[]): number {
    const freq1 = new Map<number, number>();
    const freq2 = new Map<number, number>();
    const totalFreq = new Map<number, number>();

    let minVal = Infinity;

    for (const x of basket1) {
        freq1.set(x, (freq1.get(x) ?? 0) + 1);
        totalFreq.set(x, (totalFreq.get(x) ?? 0) + 1);
        minVal = Math.min(minVal, x);
    }

    for (const x of basket2) {
        freq2.set(x, (freq2.get(x) ?? 0) + 1);
        totalFreq.set(x, (totalFreq.get(x) ?? 0) + 1);
        minVal = Math.min(minVal, x);
    }

    for (const [val, freq] of totalFreq.entries()) {
        if (freq % 2 !== 0) return -1;
    }

    const extraFrom1: number[] = [];
    const extraFrom2: number[] = [];

    for (const [val, total] of totalFreq.entries()) {
        const count1 = freq1.get(val) ?? 0;
        const diff = count1 - total / 2;

        if (diff > 0) {
            extraFrom1.push(...Array(diff).fill(val));
        } else if (diff < 0) {
            extraFrom2.push(...Array(-diff).fill(val));
        }
    }

    extraFrom1.sort((a, b) => a - b);
    extraFrom2.sort((a, b) => b - a); // reverse

    let cost = 0;
    for (let i = 0; i < extraFrom1.length; i++) {
        const a = extraFrom1[i];
        const b = extraFrom2[i];
        cost += Math.min(Math.min(a, b), 2 * minVal);
    }

    return cost;
}
//sub: https://leetcode.com/problems/rearranging-fruits/submissions/1720670631/?envType=daily-question&envId=2025-08-02
//sol: https://leetcode.com/problems/rearranging-fruits/solutions/7036216/2561-rearranging-fruits-by-nalindalal200-nth0/

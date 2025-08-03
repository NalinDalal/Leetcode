//2106. Maximum Fruits Harvested After at Most K Steps
function maxTotalFruits(fruits: number[][], startPos: number, k: number): number {
    const n = fruits.length;
    const positions = fruits.map(f => f[0]);
    const prefixSum: number[] = new Array(n + 1).fill(0);

    for (let i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + fruits[i][1];
    }

    const getSum = (l: number, r: number): number => {
        return prefixSum[r + 1] - prefixSum[l];
    };

    const lowerBound = (target: number): number => {
        let lo = 0, hi = n;
        while (lo < hi) {
            const mid = Math.floor((lo + hi) / 2);
            if (positions[mid] >= target) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    };

    const upperBound = (target: number): number => {
        let lo = 0, hi = n;
        while (lo < hi) {
            const mid = Math.floor((lo + hi) / 2);
            if (positions[mid] > target) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    };

    let res = 0;

    for (let x = 0; x <= k; x++) {
        // Left then right
        let left = startPos - x;
        let right = startPos + Math.max(k - 2 * x, 0);
        let l = lowerBound(left);
        let r = upperBound(right) - 1;
        if (l <= r) res = Math.max(res, getSum(l, r));

        // Right then left
        right = startPos + x;
        left = startPos - Math.max(k - 2 * x, 0);
        l = lowerBound(left);
        r = upperBound(right) - 1;
        if (l <= r) res = Math.max(res, getSum(l, r));
    }

    return res;
}
//sub: https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/submissions/1721589255/?envType=daily-question&envId=2025-08-03
//sol: https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/solutions/7038436/2106-maximum-fruits-harvested-after-at-m-phq9/

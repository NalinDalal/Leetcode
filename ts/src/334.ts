//3479. Fruits Into Baskets III
function numOfUnplacedFruits(fruits: number[], baskets: number[]): number {
    const n = baskets.length;
    const blockSize = Math.floor(Math.sqrt(n)) + 1;
    const numBlocks = Math.ceil(n / blockSize);
    const maxV = Array(numBlocks).fill(0);

    // Precompute max in each block
    for (let i = 0; i < n; ++i) {
        const block = Math.floor(i / blockSize);
        maxV[block] = Math.max(maxV[block], baskets[i]);
    }

    let unplaced = 0;

    for (const fruit of fruits) {
        let placed = false;
        for (let b = 0; b < numBlocks; ++b) {
            if (maxV[b] < fruit) continue;

            const start = b * blockSize;
            const end = Math.min(n, start + blockSize);

            for (let i = start; i < end; ++i) {
                if (baskets[i] >= fruit) {
                    baskets[i] = 0;

                    // Recompute block max
                    maxV[b] = 0;
                    for (let j = start; j < end; ++j) {
                        maxV[b] = Math.max(maxV[b], baskets[j]);
                    }

                    placed = true;
                    break;
                }
            }

            if (placed) break;
        }

        if (!placed) unplaced++;
    }

    return unplaced;
}
//sub: https://leetcode.com/problems/fruits-into-baskets-iii/submissions/1725705179/?envType=daily-question&envId=2025-08-06
//sol: https://leetcode.com/problems/fruits-into-baskets-iii/solutions/7051367/3479-fruits-into-baskets-iii-by-nalindal-wstg/

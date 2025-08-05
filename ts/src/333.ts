//3477. Fruits Into Baskets II
function numOfUnplacedFruits(fruits: number[], baskets: number[]): number {
    const n = fruits.length;
    let size = 1;
    while (size < n) size <<= 1;

    const seg = new Array(2 * size).fill(0);

    // Build segment tree leaves
    for (let i = 0; i < n; i++) {
        seg[size + i] = baskets[i];
    }

    // Build internal nodes
    for (let i = size - 1; i >= 1; i--) {
        seg[i] = Math.max(seg[2 * i], seg[2 * i + 1]);
    }

    const update = (pos: number) => {
        pos += size;
        seg[pos] = 0;
        while (pos > 1) {
            pos >>= 1;
            seg[pos] = Math.max(seg[2 * pos], seg[2 * pos + 1]);
        }
    };

    const query = (x: number): number => {
        let pos = 1;
        let l = 0, r = size - 1;
        while (pos < size) {
            const mid = (l + r) >> 1;
            if (seg[2 * pos] >= x) {
                pos = 2 * pos;
                r = mid;
            } else {
                pos = 2 * pos + 1;
                l = mid + 1;
            }
        }
        return (l < n && seg[pos] >= x) ? l : -1;
    };

    let unplaced = 0;
    for (const fruit of fruits) {
        const idx = query(fruit);
        if (idx === -1) {
            unplaced++;
        } else {
            update(idx);
        }
    }

    return unplaced;
}
//sub: https://leetcode.com/problems/fruits-into-baskets-ii/submissions/1723894593/?envType=daily-question&envId=2025-08-05
//sol: https://leetcode.com/problems/fruits-into-baskets-ii/solutions/7045726/3477-fruits-into-baskets-ii-by-nalindala-uk6y/

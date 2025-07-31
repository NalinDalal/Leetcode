//898. Bitwise ORs of Subarrays
function subarrayBitwiseORs(arr: number[]): number {
    const result = new Set<number>();
    let curr = new Set<number>();

    for (const num of arr) {
        const next = new Set<number>();
        next.add(num);
        for (const x of curr) {
            next.add(x | num);
        }
        curr = next;
        for (const x of curr) {
            result.add(x);
        }
    }

    return result.size;
}
//sub: https://leetcode.com/problems/bitwise-ors-of-subarrays/submissions/1717879852/?envType=daily-question&envId=2025-07-31
//sol: https://leetcode.com/problems/bitwise-ors-of-subarrays/solutions/7026811/898-bitwise-ors-of-subarrays-by-nalindal-aap4/

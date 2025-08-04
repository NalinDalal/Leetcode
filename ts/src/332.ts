//904. Fruit Into Baskets
function totalFruit(fruits: number[]): number {
    const basket = new Map<number, number>();
    let left = 0, maxFruits = 0;

    for (let right = 0; right < fruits.length; right++) {
        basket.set(fruits[right], (basket.get(fruits[right]) || 0) + 1);

        while (basket.size > 2) {
            const leftFruit = fruits[left];
            basket.set(leftFruit, basket.get(leftFruit)! - 1);
            if (basket.get(leftFruit) === 0) {
                basket.delete(leftFruit);
            }
            left++;
        }

        maxFruits = Math.max(maxFruits, right - left + 1);
    }

    return maxFruits;
}
//sub: https://leetcode.com/problems/fruit-into-baskets/submissions/1722459038/?envType=daily-question&envId=2025-08-04
//sol: https://leetcode.com/problems/fruit-into-baskets/solutions/7041213/904-fruit-into-baskets-by-nalindalal2004-84vz/

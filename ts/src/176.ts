//2115. Find All Possible Recipes from Given Supplies
function findAllRecipes(
  recipes: string[],
  ingredients: string[][],
  supplies: string[],
): string[] {
  const inDegree: Map<string, number> = new Map(); // Track number of missing ingredients
  const graph: Map<string, string[]> = new Map(); // Map ingredient → recipes that depend on it
  const available: Set<string> = new Set(supplies); // Convert supplies to a set

  // Initialize in-degree for each recipe
  for (let i = 0; i < recipes.length; i++) {
    inDegree.set(recipes[i], ingredients[i].length); // Number of ingredients needed
    for (const ing of ingredients[i]) {
      if (!graph.has(ing)) {
        graph.set(ing, []);
      }
      graph.get(ing)!.push(recipes[i]); // ing → recipe
    }
  }

  const queue: string[] = [...supplies]; // Start with all available supplies
  const result: string[] = [];

  while (queue.length > 0) {
    const item = queue.shift()!;

    // If this is a recipe, add it to the result
    if (inDegree.has(item)) {
      result.push(item);
    }

    // Process all recipes that depend on this ingredient
    if (graph.has(item)) {
      for (const dependentRecipe of graph.get(item)!) {
        inDegree.set(dependentRecipe, inDegree.get(dependentRecipe)! - 1);
        if (inDegree.get(dependentRecipe) === 0) {
          queue.push(dependentRecipe); // If all ingredients are available, add to queue
        }
      }
    }
  }

  return result;
}
//sub: https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/submissions/1581125152/?envType=daily-question&envId=2025-03-21
//sol: https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/solutions/6562235/2115-find-all-possible-recipes-from-give-lz67/

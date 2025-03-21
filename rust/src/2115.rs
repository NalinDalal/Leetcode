//2115. Find All Possible Recipes from Given Supplies
use std::collections::{HashMap, HashSet, VecDeque};

impl Solution {
    pub fn find_all_recipes(
        recipes: Vec<String>,
        ingredients: Vec<Vec<String>>,
        supplies: Vec<String>,
    ) -> Vec<String> {
        let mut in_degree: HashMap<String, i32> = HashMap::new(); // Track number of missing ingredients
        let mut graph: HashMap<String, Vec<String>> = HashMap::new(); // Ingredient → recipes that depend on it
        let available: HashSet<String> = supplies.iter().cloned().collect(); // Convert supplies to set

        // Initialize in-degree for each recipe
        for (i, recipe) in recipes.iter().enumerate() {
            in_degree.insert(recipe.clone(), ingredients[i].len() as i32);
            for ing in &ingredients[i] {
                graph
                    .entry(ing.clone())
                    .or_insert(vec![])
                    .push(recipe.clone());
            }
        }

        let mut queue: VecDeque<String> = VecDeque::from(supplies);
        let mut result: Vec<String> = Vec::new();

        while let Some(item) = queue.pop_front() {
            // If this is a recipe, add it to the result
            if in_degree.contains_key(&item) {
                result.push(item.clone()); //clone cause we need to append the result vector, we need it to be dynamic, hence need it to be cloned
                                           //we know what copy and clone does, here it creates data structure and then store the value from source
            }

            // Process all recipes that depend on this ingredient
            if let Some(dependent_recipes) = graph.get(&item) {
                for dependent_recipe in dependent_recipes {
                    if let Some(count) = in_degree.get_mut(dependent_recipe) {
                        *count -= 1;
                        if *count == 0 {
                            queue.push_back(dependent_recipe.clone()); // If all ingredients available, add to queue
                        }
                    }
                }
            }
        }

        result
    }
}
//sub: https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/submissions/1581127474/?envType=daily-question&envId=2025-03-21
//sol: https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/solutions/6562235/2115-find-all-possible-recipes-from-give-lz67/

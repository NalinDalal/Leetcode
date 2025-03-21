/*2115. Find All Possible Recipes from Given Supplies

You have information about n different recipes. You are given a string array
recipes and a 2D string array ingredients. The ith recipe has the name
recipes[i], and you can create it if you have all the needed ingredients from
ingredients[i]. A recipe can also be an ingredient for other recipes, i.e.,
ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that
you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer
in any order.

Note that two recipes may contain each other in their ingredients.


Example 1:
Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies =
["yeast","flour","corn"] Output: ["bread"] Explanation: We can create "bread"
since we have the ingredients "yeast" and "flour".

Example 2:
Input: recipes = ["bread","sandwich"], ingredients =
[["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the
ingredient "bread".

Example 3:
Input: recipes = ["bread","sandwich","burger"], ingredients =
[["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies =
["yeast","flour","meat"] Output: ["bread","sandwich","burger"] Explanation: We
can create "bread" since we have the ingredients "yeast" and "flour". We can
create "sandwich" since we have the ingredient "meat" and can create the
ingredient "bread". We can create "burger" since we have the ingredient "meat"
and can create the ingredients "bread" and "sandwich".


Constraints:
n == recipes.length == ingredients.length
1 <= n <= 100
1 <= ingredients[i].length, supplies.length <= 100
1 <= recipes[i].length, ingredients[i][j].length, supplies[k].length <= 10
recipes[i], ingredients[i][j], and supplies[k] consist only of lowercase English
letters. All the values of recipes and supplies combined are unique. Each
ingredients[i] does not contain any duplicate values.
*/

// Intuition:
/*so we are given supplies array,
now collect material while checking with ingredients{it's 2d array}
appends corrsponding recipe in ans array from recipes based on ingredients
return ans array*/

// Approach:
/*- Each recipe is a node.
- Each ingredient is a dependency.
- If all ingredients of a recipe are available (either as a supply or another
recipe that can be made), we can make the recipe.
- We use in-degree (number of required ingredients) and a queue (to process
available recipes).
- check for all recipe that exists,
start with ingredients, if recipe found, push to queue
- process all recipe based on that ingredient
- now if if all ingredient available, add to queue
*/
class Solution {
public:
  vector<string> findAllRecipes(vector<string>& recipes,
                                vector<vector<string>>& ingredients,
                                vector<string>& supplies) {
    unordered_map<string, int> inDegree; // Track number of missing ingredients
    unordered_map<string, vector<string>>
        graph; // Map ingredient → recipes that depend on it
    unordered_set<string> available(supplies.begin(),
                                    supplies.end()); // Convert supplies to set

    // Initialize in-degree for each recipe
    for (int i = 0; i < recipes.size(); i++) {
      inDegree[recipes[i]] =
          ingredients[i].size(); // Number of ingredients needed
      for (const string& ing : ingredients[i]) {
        graph[ing].push_back(recipes[i]); // ing → recipe
      }
    }

    queue<string> q;

    // Start with all available supplies
    for (const string& supply : supplies) {
      q.push(supply);
    }

    vector<string> result;

    while (!q.empty()) {
      string item = q.front();
      q.pop();

      // If this is a recipe, add it to the result
      if (inDegree.count(item)) {
        result.push_back(item);
      }

      // Process all recipes that depend on this ingredient
      for (const string& dependentRecipe : graph[item]) {
        inDegree[dependentRecipe]--; // One less ingredient needed
        if (inDegree[dependentRecipe] == 0) {
          q.push(dependentRecipe); // If all ingredients available, add to queue
        }
      }
    }

    return result;
  }
};
// sub:
// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/submissions/1580988564/?envType=daily-question&envId=2025-03-21
// sol:
// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/solutions/6562235/2115-find-all-possible-recipes-from-give-lz67/

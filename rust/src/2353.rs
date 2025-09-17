//2353. Design a Food Rating System
use std::collections::{HashMap, BTreeSet};
use std::cmp::Ordering;

#[derive(Debug, Clone, Eq, PartialEq)]
struct Food {
    name: String,
    rating: i32,
}

impl Ord for Food {
    fn cmp(&self, other: &Self) -> Ordering {
        // Order by rating descending, then by name ascending
        match self.rating.cmp(&other.rating).reverse() {
            Ordering::Equal => self.name.cmp(&other.name),
            ord => ord,
        }
    }
}

impl PartialOrd for Food {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

struct FoodRatings {
    food_info: HashMap<String, (String, i32)>,      // food -> (cuisine, rating)
    cuisine_foods: HashMap<String, BTreeSet<Food>>, // cuisine -> sorted foods
}

impl FoodRatings {
    fn new(foods: Vec<String>, cuisines: Vec<String>, ratings: Vec<i32>) -> Self {
        let mut food_info = HashMap::new();
        let mut cuisine_foods: HashMap<String, BTreeSet<Food>> = HashMap::new();

        for i in 0..foods.len() {
            let food = foods[i].clone();
            let cuisine = cuisines[i].clone();
            let rating = ratings[i];

            food_info.insert(food.clone(), (cuisine.clone(), rating));

            cuisine_foods
                .entry(cuisine)
                .or_insert_with(BTreeSet::new)
                .insert(Food {
                    name: food,
                    rating,
                });
        }

        FoodRatings {
            food_info,
            cuisine_foods,
        }
    }

    fn change_rating(&mut self, food: String, new_rating: i32) {
        if let Some((cuisine, old_rating)) = self.food_info.get(&food).cloned() {
            if let Some(set) = self.cuisine_foods.get_mut(&cuisine) {
                set.remove(&Food {
                    name: food.clone(),
                    rating: old_rating,
                });
                set.insert(Food {
                    name: food.clone(),
                    rating: new_rating,
                });
            }
            self.food_info.insert(food, (cuisine, new_rating));
        }
    }

    fn highest_rated(&self, cuisine: String) -> String {
        self.cuisine_foods[&cuisine]
            .iter()
            .next()
            .unwrap()
            .name
            .clone()
    }
}

//sub: https://leetcode.com/problems/design-a-food-rating-system/submissions/1773349554/?envType=daily-question&envId=2025-09-17
//sol: https://leetcode.com/problems/design-a-food-rating-system/solutions/7197850/2353-design-a-food-rating-system-by-nali-3m29/

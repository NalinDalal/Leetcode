//1912. Design Movie Rental System
use std::collections::{BTreeSet, HashMap};

#[derive(Debug, Clone, Eq)]
struct Entry {
    shop: i32,
    movie: i32,
    price: i32,
}

// Implement ordering: price, then shop, then movie
impl PartialEq for Entry {
    fn eq(&self, other: &Self) -> bool {
        self.price == other.price && self.shop == other.shop && self.movie == other.movie
    }
}

impl PartialOrd for Entry {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}

impl Ord for Entry {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        self.price
            .cmp(&other.price)
            .then(self.shop.cmp(&other.shop))
            .then(self.movie.cmp(&other.movie))
    }
}

pub struct MovieRentingSystem {
    price_map: HashMap<(i32, i32), i32>,          // (shop,movie) -> price
    unrented: HashMap<i32, BTreeSet<(i32, i32)>>, // movie -> (price, shop)
    rented: BTreeSet<Entry>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MovieRentingSystem {

    pub fn new(n: i32, entries: Vec<Vec<i32>>) -> Self {
        let mut price_map = HashMap::new();
        let mut unrented: HashMap<i32, BTreeSet<(i32, i32)>> = HashMap::new();
        let rented = BTreeSet::new();

        for e in entries {
            let shop = e[0];
            let movie = e[1];
            let price = e[2];
            price_map.insert((shop, movie), price);
            unrented
                .entry(movie)
                .or_insert_with(BTreeSet::new)
                .insert((price, shop));
        }

        MovieRentingSystem {
            price_map,
            unrented,
            rented,
        }
    }
    
    pub fn search(&self, movie: i32) -> Vec<i32> {
        let mut res = Vec::new();
        if let Some(set) = self.unrented.get(&movie) {
            for &(price, shop) in set.iter().take(5) {
                res.push(shop);
            }
        }
        res
    }
    
    pub fn rent(&mut self, shop: i32, movie: i32) {
        let price = self.price_map[&(shop, movie)];
        if let Some(set) = self.unrented.get_mut(&movie) {
            set.remove(&(price, shop));
        }
        self.rented.insert(Entry { shop, movie, price });
    }
    
    pub fn drop(&mut self, shop: i32, movie: i32) {
        let price = self.price_map[&(shop, movie)];
        self.rented.remove(&Entry { shop, movie, price });
        self.unrented
            .entry(movie)
            .or_insert_with(BTreeSet::new)
            .insert((price, shop));
    }
    
    pub fn report(&self) -> Vec<Vec<i32>> {
        let mut res = Vec::new();
        for entry in self.rented.iter().take(5) {
            res.push(vec![entry.shop, entry.movie]);
        }
        res
    }
}

 fn main(){ let obj = MovieRentingSystem::new(n, entries);
  let ret_1: Vec<i32> = obj.search(movie);
  obj.rent(shop, movie);
  obj.drop(shop, movie);
  let ret_4: Vec<Vec<i32>> = obj.report();
}
//sub: https://leetcode.com/problems/design-movie-rental-system/submissions/1777728971/?envType=daily-question&envId=2025-09-21
//sol: https://leetcode.com/problems/design-movie-rental-system/solutions/7209797/1912-design-movie-rental-system-by-nalin-jvgj/

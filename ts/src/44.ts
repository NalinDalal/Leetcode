//  3405. Count the Number of Arrays with K Matching Adjacent Elements
//sub:
//sol: 
const MOD = 1_000_000_007;

let FACT: number[] = [1, 1];
let INV: number[] = [1, 1];
let INV_FACT: number[] = [1, 1];

// Helper function for nCr (combinatorics)
function nCr(n: number, k: number): number {
    while (INV.length <= n) {  // lazy initialization
        FACT.push((FACT[FACT.length - 1] * INV.length) % MOD);
        INV.push((INV[MOD % INV.length] * (MOD - Math.floor(MOD / INV.length))) % MOD);  // modular inverse
        INV_FACT.push((INV_FACT[INV_FACT.length - 1] * INV[INV.length - 1]) % MOD);
    }
    return (((FACT[n] * INV_FACT[n - k]) % MOD) * INV_FACT[k]) % MOD;
}

// Function to compute power with modular exponentiation
function powMod(a: number, b: number): number {
    a %= MOD;
    let result = 1;
    while (b > 0) {
        if (b % 2 === 1) {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return result;
}

// Function to count good arrays
function countGoodArrays(n: number, m: number, k: number): number {
    const comb = nCr(n - 1, k);  // Get nCr(n-1, k)
    const power = powMod(m - 1, n - 1 - k);  // Power (m-1)^(n-1-k)
    
    return (comb * (m * power % MOD)) % MOD;
}

// Example usage:
console.log(countGoodArrays(5, 3, 2));  // Example test case

--------------------------------------------------------------
//maa chudaye
const MOD = 1_000_000_007;

let FACT: number[] = [1, 1];
let INV: number[] = [1, 1];
let INV_FACT: number[] = [1, 1];

// Function to compute power with modular exponentiation
function powMod(a: number, b: number): number {
    a %= MOD;
    let result = 1;
    while (b > 0) {
        if (b % 2 === 1) {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return result;
}

// Helper function for nCr (combinatorics)
function nCr(n: number, k: number): number {
    // Ensure factorials are precomputed for values up to n
    while (FACT.length <= n) {
        let nextFactorial = (FACT[FACT.length - 1] * FACT.length) % MOD;
        FACT.push(nextFactorial);
        let invNext = powMod(FACT[FACT.length - 1], MOD - 2); // Corrected call to powMod
        INV.push(invNext);
        INV_FACT.push((INV_FACT[INV_FACT.length - 1] * INV[INV.length - 1]) % MOD);
    }

    return ((FACT[n] * INV_FACT[k]) % MOD) * INV_FACT[n - k] % MOD;
}

// Function to count good arrays
function countGoodArrays(n: number, m: number, k: number): number {
    // Edge cases where k is invalid
    if (k < 0 || k > n - 1) {
        return 0;
    }

    // Step 1: Calculate combinations (n-1 choose k)
    const comb = nCr(n - 1, k);  
    
    // Step 2: Power of (m-1) for remaining positions
    const power = powMod(m - 1, n - 1 - k);  
    
    // Step 3: Calculate result
    const result = (comb * m % MOD * power % MOD) % MOD;

    return result;
}

// Test case
console.log(countGoodArrays(4, 2, 2));  // Expected output: 6


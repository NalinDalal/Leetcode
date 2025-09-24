//166. Fraction to Recurring Decimal
use std::collections::HashMap;

impl Solution {
    pub fn fraction_to_decimal(numerator: i32, denominator: i32) -> String {
        if numerator == 0 {
            return "0".to_string();
        }

        let mut result = String::new();

        // Handle sign
        if (numerator < 0) ^ (denominator < 0) {
            result.push('-');
        }

        // Use i64 to avoid overflow on abs
        let mut n = (numerator as i64).abs();
        let d = (denominator as i64).abs();

        // Integral part
        result.push_str(&(n / d).to_string());
        let mut remainder = n % d;
        if remainder == 0 {
            return result; // no fractional part
        }

        result.push('.');

        // Map: remainder -> index in result string
        let mut seen = HashMap::new();

        while remainder != 0 {
            if let Some(&idx) = seen.get(&remainder) {
                // repeating cycle found
                result.insert(idx, '(');
                result.push(')');
                break;
            }

            seen.insert(remainder, result.len());

            remainder *= 10;
            result.push_str(&(remainder / d).to_string());
            remainder %= d;
        }

        result
    }
}
//sub: https://leetcode.com/problems/fraction-to-recurring-decimal/submissions/1780868374/
//sol: https://leetcode.com/problems/fraction-to-recurring-decimal/solutions/7219038/166-fraction-to-recurring-decimal-by-nal-svxf/

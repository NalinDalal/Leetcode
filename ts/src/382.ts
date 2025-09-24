//166. Fraction to Recurring Decimal
function fractionToDecimal(numerator: number, denominator: number): string {
  if (numerator === 0) return "0";

  let result = "";

  // Handle sign
  if (numerator < 0 !== denominator < 0) {
    result += "-";
  }

  // Work with absolute values
  let n = Math.abs(numerator);
  let d = Math.abs(denominator);

  // Integral part
  result += Math.floor(n / d).toString();
  let remainder = n % d;
  if (remainder === 0) return result; // No fractional part

  result += ".";

  // Map remainder -> position in result string
  const seen = new Map<number, number>();

  while (remainder !== 0) {
    if (seen.has(remainder)) {
      // repeating cycle starts here
      const idx = seen.get(remainder)!;
      result = result.slice(0, idx) + "(" + result.slice(idx) + ")";
      return result;
    }

    seen.set(remainder, result.length);

    remainder *= 10;
    result += Math.floor(remainder / d).toString();
    remainder %= d;
  }

  return result;
}

//sub: https://leetcode.com/problems/fraction-to-recurring-decimal/submissions/1780867612/?envType=daily-question&envId=2025-09-24
//sol: https://leetcode.com/problems/fraction-to-recurring-decimal/solutions/7219038/166-fraction-to-recurring-decimal-by-nal-svxf/

//2138. Divide a String Into Groups of Size k
function divideString(s: string, k: number, fill: string): string[] {
  const result: string[] = [];

  for (let i = 0; i < s.length; i += k) {
    let chunk = s.substring(i, i + k);
    if (chunk.length < k) {
      chunk += fill.repeat(k - chunk.length);
    }
    result.push(chunk);
  }

  return result;
}
//sub:https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/submissions/1672232387/
//sol: https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/solutions/6870831/2138-divide-a-string-into-groups-of-size-k/

//3508. Implement Router
class Router {
  private memoryLimit: number;

  private packetQueue: {
    source: number;
    destination: number;
    timestamp: number;
  }[] = [];
  private packetSet: Set<string> = new Set(); // uniqueness via string key
  private destinationMap: Map<number, number[]> = new Map();

  constructor(memoryLimit: number) {
    this.memoryLimit = memoryLimit;
  }

  private packetKey(
    source: number,
    destination: number,
    timestamp: number,
  ): string {
    return `${source}:${destination}:${timestamp}`;
  }

  addPacket(source: number, destination: number, timestamp: number): boolean {
    const key = this.packetKey(source, destination, timestamp);

    if (this.packetSet.has(key)) return false;

    if (this.packetQueue.length >= this.memoryLimit) {
      // Evict oldest packet
      const oldest = this.packetQueue.shift()!;
      const oldestKey = this.packetKey(
        oldest.source,
        oldest.destination,
        oldest.timestamp,
      );
      this.packetSet.delete(oldestKey);

      const timestamps = this.destinationMap.get(oldest.destination);
      if (timestamps && timestamps[0] === oldest.timestamp) {
        timestamps.shift();
      }
    }

    // Add new packet
    this.packetQueue.push({ source, destination, timestamp });
    this.packetSet.add(key);

    if (!this.destinationMap.has(destination)) {
      this.destinationMap.set(destination, []);
    }
    this.destinationMap.get(destination)!.push(timestamp);

    return true;
  }

  forwardPacket(): number[] {
    if (this.packetQueue.length === 0) return [];

    const packet = this.packetQueue.shift()!;
    const key = this.packetKey(
      packet.source,
      packet.destination,
      packet.timestamp,
    );
    this.packetSet.delete(key);

    const timestamps = this.destinationMap.get(packet.destination);
    if (timestamps && timestamps[0] === packet.timestamp) {
      timestamps.shift();
    }

    return [packet.source, packet.destination, packet.timestamp];
  }

  getCount(destination: number, startTime: number, endTime: number): number {
    const timestamps = this.destinationMap.get(destination);
    if (!timestamps || timestamps.length === 0) return 0;

    // binary search lower_bound
    let left = 0,
      right = timestamps.length;
    while (left < right) {
      const mid = Math.floor((left + right) / 2);
      if (timestamps[mid] < startTime) left = mid + 1;
      else right = mid;
    }
    const lower = left;

    // binary search upper_bound
    left = 0;
    right = timestamps.length;
    while (left < right) {
      const mid = Math.floor((left + right) / 2);
      if (timestamps[mid] <= endTime) left = mid + 1;
      else right = mid;
    }
    const upper = left;

    return Math.max(0, upper - lower);
  }
}
//sub: https://leetcode.com/problems/implement-router/submissions/1776661656/?envType=daily-question&envId=2025-09-20
//sol: https://leetcode.com/problems/implement-router/solutions/7207173/3508-implement-router-by-nalindalal2004-j8rr/

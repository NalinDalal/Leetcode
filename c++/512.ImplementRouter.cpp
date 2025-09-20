/*3508. Implement Router
Design a data structure that can efficiently manage data packets in a network
router. Each data packet consists of the following attributes:

source: A unique identifier for the machine that generated the packet.
destination: A unique identifier for the target machine.
timestamp: The time at which the packet arrived at the router.
Implement the Router class:

Router(int memoryLimit): Initializes the Router object with a fixed memory
limit.

memoryLimit is the maximum number of packets the router can store at any given
time. If adding a new packet would exceed this limit, the oldest packet must be
removed to free up space. bool addPacket(int source, int destination, int
timestamp): Adds a packet with the given attributes to the router.

A packet is considered a duplicate if another packet with the same source,
destination, and timestamp already exists in the router. Return true if the
packet is successfully added (i.e., it is not a duplicate); otherwise return
false. int[] forwardPacket(): Forwards the next packet in FIFO (First In First
Out) order.

Remove the packet from storage.
Return the packet as an array [source, destination, timestamp].
If there are no packets to forward, return an empty array.
int getCount(int destination, int startTime, int endTime):

Returns the number of packets currently stored in the router (i.e., not yet
forwarded) that have the specified destination and have timestamps in the
inclusive range [startTime, endTime]. Note that queries for addPacket will be
made in increasing order of timestamp.



Example 1:

Input:
["Router", "addPacket", "addPacket", "addPacket", "addPacket", "addPacket",
"forwardPacket", "addPacket", "getCount"]
[[3], [1, 4, 90], [2, 5, 90], [1, 4, 90], [3, 5, 95], [4, 5, 105], [], [5, 2,
110], [5, 100, 110]]

Output:
[null, true, true, false, true, true, [2, 5, 90], true, 1]

Explanation

Router router = new Router(3); // Initialize Router with memoryLimit of 3.
router.addPacket(1, 4, 90); // Packet is added. Return True.
router.addPacket(2, 5, 90); // Packet is added. Return True.
router.addPacket(1, 4, 90); // This is a duplicate packet. Return False.
router.addPacket(3, 5, 95); // Packet is added. Return True
router.addPacket(4, 5, 105); // Packet is added, [1, 4, 90] is removed as number
of packets exceeds memoryLimit. Return True. router.forwardPacket(); // Return
[2, 5, 90] and remove it from router. router.addPacket(5, 2, 110); // Packet is
added. Return True. router.getCount(5, 100, 110); // The only packet with
destination 5 and timestamp in the inclusive range [100, 110] is [4, 5, 105].
Return 1. Example 2:

Input:
["Router", "addPacket", "forwardPacket", "forwardPacket"]
[[2], [7, 4, 90], [], []]

Output:
[null, true, [7, 4, 90], []]

Explanation

Router router = new Router(2); // Initialize Router with memoryLimit of 2.
router.addPacket(7, 4, 90); // Return True.
router.forwardPacket(); // Return [7, 4, 90].
router.forwardPacket(); // There are no packets left, return [].


Constraints:

2 <= memoryLimit <= 105
1 <= source, destination <= 2 * 105
1 <= timestamp <= 109
1 <= startTime <= endTime <= 109
At most 105 calls will be made to addPacket, forwardPacket, and getCount methods
altogether. queries for addPacket will be made in increasing order of timestamp.


Hint 1
A deque can simulate the adding and forwarding of packets efficiently.
Hint 2
Use binary search for counting packets within a timestamp range.
*/

/* bool addPacket(int source, int destination, int timestamp) {
        //if already exists return false, else return true and add it
        //use a list
    }

    vector<int> forwardPacket() {
        //forward the packet into queue order
        //remove packet from storage
        //if not exist return empty vector
    }

    int getCount(int destination, int startTime, int endTime) {
        //return count of packets in router
        //find the destination then find their start and end time
        //find their lower and upper bound,
        //return their difference
    }
*/

class Router {
  struct Packet {
    int source;
    int destination;
    int timestamp;

    bool operator==(const Packet& other) const {
      return tie(source, destination, timestamp) ==
             tie(other.source, other.destination, other.timestamp);
    }
  };

  struct PacketHash {
    size_t operator()(const Packet& p) const {
      return hash<int>()(p.source) ^ hash<int>()(p.destination << 1) ^
             hash<int>()(p.timestamp << 2);
    }
  };

  struct DestinationData {
    vector<int> timestamps;
    int start = 0;
    int end = -1;
  };

  int memoryLimit;
  queue<Packet> packetQueue;
  unordered_set<Packet, PacketHash> packetSet;
  unordered_map<int, DestinationData> destinationMap;

public:
  Router(int memoryLimit) : memoryLimit(memoryLimit) {}

  bool addPacket(int source, int destination, int timestamp) {
    Packet packet{source, destination, timestamp};

    if (packetSet.count(packet))
      return false;

    if ((int)packetQueue.size() >= memoryLimit) {
      // Evict the oldest packet
      Packet oldest = packetQueue.front();
      packetQueue.pop();
      packetSet.erase(oldest);

      auto& data = destinationMap[oldest.destination];
      data.start++;
    }

    // Add new packet
    packetQueue.push(packet);
    packetSet.insert(packet);

    auto& data = destinationMap[destination];
    data.timestamps.push_back(timestamp);
    data.end++;

    return true;
  }

  vector<int> forwardPacket() {
    if (packetQueue.empty())
      return {};

    Packet packet = packetQueue.front();
    packetQueue.pop();
    packetSet.erase(packet);

    auto& data = destinationMap[packet.destination];
    data.start++;

    return {packet.source, packet.destination, packet.timestamp};
  }

  int getCount(int destination, int startTime, int endTime) {
    auto it = destinationMap.find(destination);
    if (it == destinationMap.end() || it->second.start > it->second.end)
      return 0;

    const auto& timestamps = it->second.timestamps;
    int startIdx = it->second.start;
    int endIdx = it->second.end;

    auto first = timestamps.begin() + startIdx;
    auto last = timestamps.begin() + endIdx + 1;

    auto lower = lower_bound(first, last, startTime);
    auto upper = upper_bound(first, last, endTime);

    return max(0, (int)(upper - lower));
  }
};
// sub:
// https://leetcode.com/problems/implement-router/submissions/1776658547/?envType=daily-question&envId=2025-09-20
// sol:
// https://leetcode.com/problems/implement-router/solutions/7207173/3508-implement-router-by-nalindalal2004-j8rr/

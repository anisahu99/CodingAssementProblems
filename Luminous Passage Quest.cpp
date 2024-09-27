/*
  In a vast underground tunnel network spanning N sections, a series of lamps hung from the ceiling at regular intervals. Each lamp had a power rating of P, determining the radius of its illumination, effectively lighting up the area from [Pos-P+1, Pos+P-1] when switched on at position Pos.

However, the tunnels were not without their challenges. Some of the lamps were malfunctioning, posing a risk to travelers navigating through the darkness. To distinguish between functional and faulty lamps, the tunnel overseer maintained a list, an array A, with N entries corresponding to each lamp's position. A value of 0 signified a faulty lamp, while a value of 1 indicated a functional one.

One fateful night, as darkness enveloped the tunnels, the overseer resolved to illuminate the entire underground passage. Yet, mindful of conserving resources, he sought to achieve this feat using the minimum number of lamps necessary.

Realizing that failure to fully illuminate the tunnels would jeopardize the safety of travellers, the overseer diligently calculated the precise number of functional lamps required to ensure optimal brightness and safe passage through the depths of the underground network.


Function Description Complete the function min NumberOfLights in the editor below.

minNumberOfLights has the following parameter(s):

int arr[n]: Array of size N, The ith index of this array is 0 if the lamp at ith position is faulty otherwise it is 1.

int power: Power rating of lamp


Returns

int[n]: minimum number of lamps to be turned ON to light the whole tunnel or -1 if the whole tunnel cannot be lighted.

Constraints

 1 <= N <= 100000
 1 <= P <= 10000

Sample Input 0

A = [ 0, 0, 1, 1, 1, 0, 0, 1] P = 3

Sample Output 0

2

Explanation

Turn on the lamp at 2nd and 7th index. Lamp at 2nd index covers from [ 1, 5] and lamp at 7th index covers [6, 8].

Sample Input 1

A = [ 0, 0, 0, 1, 0] P = 3

Sample Output 1

-1

Explanation

There is no lamp which can light the entire
tunnel.
*/

/*
  To solve this problem, we need to approach it greedily, ensuring we cover as many tunnel sections as possible with each functional lamp.
Plan:

    Traverse the tunnel starting from the leftmost section, and at each step, check how far we can reach using the available functional lamps.
    Greedily choose the furthest-reaching functional lamp that can illuminate the current section of the tunnel.
    If at any point we can't find a functional lamp that can illuminate the current section, it means it's impossible to light the entire tunnel, so we return -1.

Detailed Approach:

    Greedy Strategy: Start from the beginning of the tunnel and look for the farthest lamp that can illuminate the current position.
    Lamp Range: A lamp at position i with power P can illuminate the range from [i - P + 1, i + P - 1].
    Edge Cases:
        If it's not possible to light the entire tunnel, return -1.
        If we find enough lamps, return the minimum number of lamps required.
*/
// We are trying to minimize the number of lamps that need to be turned on in order to light up the entire tunnel.
#include <iostream>
#include <vector>

using namespace std;

int minNumberOfLights(vector<int>& A, int P) {
    int n = A.size();
    int lights_needed = 0;
    int i = 0;

    while (i < n) {
        int lamp = -1;
        // Look for the farthest lamp that can cover current position i
        for (int j = max(0, i - P + 1); j <= min(n - 1, i + P - 1); ++j) {
            if (A[j] == 1) {
                lamp = j;
            }
        }
        
        if (lamp == -1) {
            // No functional lamp found to cover this range
            return -1;
        }
        
        // We found a functional lamp at index `lamp`, which covers the range
        lights_needed++;
        i = lamp + P; // Move to the next section beyond the reach of this lamp
    }

    return lights_needed;
}

int main() {
    vector<int> A1 = {0, 0, 1, 1, 1, 0, 0, 1};
    int P1 = 3;
    cout << minNumberOfLights(A1, P1) << endl; // Output: 2

    vector<int> A2 = {0, 0, 0, 1, 0};
    int P2 = 3;
    cout << minNumberOfLights(A2, P2) << endl; // Output: -1

    return 0;
}

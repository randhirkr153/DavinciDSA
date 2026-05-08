#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Solution {
public:

    // Function to check how many
    // gas stations are needed
    // for maximum distance = dist
    int numberOfStations(vector<int>& stations,
                         double dist) {

        int count = 0;

        for (int i = 1; i < stations.size(); i++) {

            double gap =
                stations[i] - stations[i - 1];

            // Stations needed in this gap
            count += (int)(gap / dist);

            // Exact division case
            if ((gap / dist) ==
                (int)(gap / dist)) {

                count--;
            }
        }

        return count;
    }

    // Intuition:
    //
    // We apply Binary Search on answer.
    //
    // Minimum possible distance = 0
    // Maximum possible distance =
    // largest gap between stations.
    //
    // For every mid distance:
    // calculate how many extra stations
    // are required.
    //
    // If required stations <= k,
    // try smaller distance.
    //
    // Else increase distance.
    //
    // Time Complexity:
    // O(n * log(range))
    //
    // Space Complexity:
    // O(1)

    double minimizeMaxDistance(vector<int>& stations,
                               int k) {

        int n = stations.size();

        double low = 0;

        double high = 0;

        // Find maximum gap
        for (int i = 1; i < n; i++) {

            high = max(high,
                       (double)(stations[i]
                                - stations[i - 1]));
        }

        double diff = 1e-6;

        while ((high - low) > diff) {

            double mid =
                low + (high - low) / 2.0;

            int requiredStations =
                numberOfStations(stations, mid);

            if (requiredStations > k) {

                low = mid;
            }

            else {

                high = mid;
            }
        }

        return high;
    }
};

int main() {

    int n;

    cout << "Enter number of stations: ";
    cin >> n;

    vector<int> stations(n);

    cout << "Enter station positions:\n";

    for (int i = 0; i < n; i++) {
        cin >> stations[i];
    }

    int k;

    cout << "Enter extra stations: ";
    cin >> k;

    Solution obj;

    double result =
        obj.minimizeMaxDistance(stations, k);

    cout << fixed << setprecision(6);

    cout << "Minimum Maximum Distance: "
         << result << endl;

    return 0;
}
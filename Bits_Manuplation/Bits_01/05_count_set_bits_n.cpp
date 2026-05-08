#include <iostream>
using namespace std;

class Solution {
  public:
  
    int countSetBits(int n) {
        
        /*
            Intuition:
            
            We count set bits for every number
            from 1 to n.
            
            To count set bits efficiently,
            use Brian Kernighan Algorithm.
            
            Trick:
            n & (n - 1)
            
            removes the last set bit.
            
            Example:
            
            12 = 1100
            
            1100
            1011
            ----
            1000
            
            One set bit removed.
        */
        
        int totalBits = 0;
        
        // Traverse from 1 to n
        for(int i = 1; i <= n; i++) {
            
            int num = i;
            
            // Count set bits in current number
            while(num > 0) {
                
                // Remove last set bit
                num = num & (num - 1);
                
                totalBits++;
            }
        }
        
        return totalBits;
    }
};

int main() {

    int n;

    // Input
    cin >> n;

    Solution obj;

    // Output
    cout << obj.countSetBits(n);

    return 0;
}
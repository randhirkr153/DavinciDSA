#include <iostream>
using namespace std;

class Solution {
  public:
  
    bool checkKthBit(int n, int k) {
        
        /*
            Intuition:
            
            We need to check whether kth bit is 1 or 0.
            
            Create a mask using:
            (1 << k)
            
            Example:
            k = 2
            
            1 << 2 = 00000100
            
            Now AND it with number.
            
            If result is non-zero:
            bit is SET (1)
            
            Else:
            bit is NOT SET (0)
        */
        
        if (n & (1 << k)) {
            return true;
        }
        
        return false;
    }
};

int main() {
    
    int n, k;
    
    // Input
    cin >> n >> k;
    
    Solution obj;
    
    bool ans = obj.checkKthBit(n, k);
    
    // Output
    if(ans)
        cout << "true";
    else
        cout << "false";
    
    return 0;
}
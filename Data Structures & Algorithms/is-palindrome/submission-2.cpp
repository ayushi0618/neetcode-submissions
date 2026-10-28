#include <string>
#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        
        while (left < right) {
            // Move left pointer until it hits an alphanumeric character
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // Move right pointer until it hits an alphanumeric character
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            // Compare characters case-insensitively
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
};
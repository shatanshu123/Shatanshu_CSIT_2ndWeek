//STRIVER_SDE_SHEET

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int counter[128];
        for (int i = 0; i < 128; i++) {
            counter[i] = 0;
        }
        
        int index = 0;
        int start = 0;
        int maxLength = 0, currLength = 0;
        
        while (index < s.length()) {
            if (counter[s[index]] == 0) {
                counter[s[index]] = 1;
                currLength++;
            } else {
                maxLength = max(maxLength, currLength);
                int i;
                for (i = start; i < index; i++) {
                    if (s[i] == s[index]) {
                        break;
                    }
                    counter[s[i]] = 0;
                    currLength--;
                }
                start = i + 1; 
            
            }
            
            index++;
        }
        
        maxLength = max(maxLength, currLength);
        
        return maxLength;
    }
};
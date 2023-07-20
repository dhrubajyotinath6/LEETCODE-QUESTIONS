class Solution {
public:
    string minWindow(string str, string pattern) {
        
        int windowStart = 0, matched = 0, minLength = str.length() + 1, subStrStart = 0;
        unordered_map<char, int> charFrequencyMap;
        for (auto chr : pattern)
        {
            charFrequencyMap[chr]++;
        }

        // try to extend the range [windowStart, windowEnd]
        for (int windowEnd = 0; windowEnd < str.length(); windowEnd++)
        {
            char rightChar = str[windowEnd];
            if (charFrequencyMap.find(rightChar) != charFrequencyMap.end())
            {
                charFrequencyMap[rightChar]--;
                if (charFrequencyMap[rightChar] >= 0) // count every matching of a character
                { 
                    matched++;
                }
            }

            // shrink the window if we can, finish as soon as we remove a matched character
            while (matched == pattern.length())
            {
                if (minLength > windowEnd - windowStart + 1)
                {
                    minLength = windowEnd - windowStart + 1;
                    subStrStart = windowStart;
                }

                char leftChar = str[windowStart++];
                if (charFrequencyMap.find(leftChar) != charFrequencyMap.end())
                {
                    // note that we could have redundant matching characters, therefore we'll
                    // decrement the matched count only when a useful occurrence of a matched
                    // character is going out of the window
                    if (charFrequencyMap[leftChar] == 0)
                    {
                        matched--;
                    }
                    charFrequencyMap[leftChar]++;
                }
            }
        }

        return minLength > str.length() ? "" : str.substr(subStrStart, minLength);
    }
};
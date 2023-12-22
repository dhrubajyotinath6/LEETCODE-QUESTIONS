class Solution {
    
public:
    vector<long long> nearestPalindrome(long long num){
        
        vector<long long> palindrome;
        
        string str = to_string(num); // 12345 ,  123456        
        long long n= str.size(); 
        
        /*
        case 1 && case 2:
        12345 -->  9999, 100001
        123456-->  99999, 100001
        */
        
        palindrome.push_back(pow(10, n-1) - 1);
        palindrome.push_back(pow(10, n) + 1);
        
        /*
        case 3:
        12345  --> 12321
        123456 --> 123321
        */
        
        for(int i = 0; i < n/2; i++){
            str[n - 1 - i] = str[i];
        }
        palindrome.push_back(stoll(str));
        
        /*
        case 4: 12321  ---> 12421   
                123321 ---> 124421   
                
                12321
                
                123 + 1 = 124
                124 -> 12 -> 21
                
                12421
                
                123321
                
                123 + 1 = 124
                124 --> 421
                
                124421
                
        */
        
        string firstPart =  to_string(stoi(str.substr(0, (n +1)/2)) + 1);
        
        string secondPart = firstPart;
        
        if(n % 2 == 1) secondPart = secondPart.substr(0, secondPart.size() - 1);
        reverse(secondPart.begin(), secondPart.end());
        
        string finalNum =  firstPart + secondPart;
        palindrome.push_back(stoll(finalNum));
        
        /*
        case 5:
        
        */
        firstPart =  to_string(stoi(str.substr(0, (n +1)/2)) - 1);
        
        secondPart = firstPart;
        
        if(n % 2 == 1) secondPart = secondPart.substr(0, secondPart.size() - 1);
        reverse(secondPart.begin(), secondPart.end());
        
        finalNum =  firstPart + secondPart;
        palindrome.push_back(stoll(finalNum));
        
        return palindrome;
            
    }
    
    
public:
    string nearestPalindromic(string n) {
        
        long long num = stoll(n);
        vector<long long> palindrome = nearestPalindrome(num);
        
        int mini = INT_MAX;
        long long ans = 0;
        
        for(auto& x : palindrome){
            
            long long diff = abs(num - x);
            
            if(num == x) continue;
            
            else if(diff < mini){
                mini = abs(num - x);
                ans = x;
            }
            
            else if(diff == mini){
                ans = min(ans,x);
            }
            
        }
       
        
        return to_string(ans);
        
    }
};

//1331 - 1221 = 110
//1221 - 1111 = 110
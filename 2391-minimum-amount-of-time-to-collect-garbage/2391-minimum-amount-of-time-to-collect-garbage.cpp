class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        int n = garbage.size();
        
        int lastG = -1, lastP = -1, lastM = -1;
        
        int time = 0;
        
        for(int i = 0; i < n; i++){
            
            string houseGarbage =  garbage[i];
            
            time += houseGarbage.size();
            
            for(auto& ch : houseGarbage){
                
                if(ch == 'G')  lastG = i;
                if(ch == 'P')  lastP = i;
                if(ch == 'M')  lastM = i;
            }
        }
        
        /*
        time = 6
        lastG = 3 
        lastP = 2
        lastM = -1;        
        */
        
  
        
        // travel.length == garbage.length - 1
        for(int i = 0; i < n-1; i++){
            
            if(i < lastP) time += travel[i];   //6
            if(i < lastG) time += travel[i];   //9
            if(i < lastM) time += travel[i];   //0
        }
        
        //time = 6 + 6 + 9 + 0 = 21
        
        return time;
        
    }
};
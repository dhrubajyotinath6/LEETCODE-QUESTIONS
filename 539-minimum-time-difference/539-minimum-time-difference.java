class Solution {
    public int findMinDifference(List<String> timePoints) {
        boolean[] minutes = new boolean[24 * 60];
        for (String timePoint : timePoints) {
            int hour = Integer.parseInt(timePoint.split(":")[0]);
            int min = Integer.parseInt(timePoint.split(":")[1]);
            if (minutes[hour * 60 + min]) // Min difference 0 exists if there are two equal timePoints
                return 0;
            minutes[hour * 60 + min] = true;
        }
        
        int min = Integer.MAX_VALUE;
        int biggestMinuteSoFar = -1;  // the biggest minute meet so far
        int smallestMinute = -1; // the smallest minute exists in timePoints
        for (int minute = 0; minute < minutes.length; minute++) {
            if (minutes[minute]) {
                // minute exists in timePoints
                if (biggestMinuteSoFar != -1)
                    min = Math.min(min, minute - biggestMinuteSoFar);
                
                biggestMinuteSoFar = minute;
                
                if (smallestMinute == -1)
                    smallestMinute = minute;
            }
            
        }
        
        // Here biggestMinuteSoFar points to the biggest minute in timePoints
        return Math.min(min,smallestMinute + 24 * 60 - biggestMinuteSoFar);
    } 
}
//1. brute force
/*
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        int m = img.size(),  n = img[0].size();
        
        vector<vector<int>> newImg(m, vector<int>(n));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                int sum = 0;
                int count = 0;
                
                for(int x = i - 1; x <= i + 1; x++){
                    for(int y = j - 1; y <= j + 1; y++){
                        
                        if(0 <= x && x < m && 0 <= y && y < n){
                            sum += img[x][y];
                            count += 1;
                        }
                    }
                }
                
                newImg[i][j] = sum/count;
            }
        }
        
        return newImg;
    }
};
*/

// 2.optimised one
/*
Can we somehow store both the pre-modified and post-modified img[i][j] values in the same cell? Ideally speaking, it's possible.


we hv two numbers : p, r

Y=p⋅X+r   (X is a constant)

To extract p from Y, we can do Y/X
To extract r from Y, we can do Y%X

X value ?

r varies from 0 to X-1

0 <= r <= 255

therefore, X = 256;
*/


/*
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        int m = img.size(),  n = img[0].size();
        
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                int sum = 0;
                int count = 0;
                
                for(int x = i - 1; x <= i + 1; x++){
                    for(int y = j - 1; y <= j + 1; y++){
                        
                        if(0 <= x && x < m && 0 <= y && y < n){
                            sum += img[x][y];
                            count += 1;
                        }
                    }
                }
                
                // Y = p.X + r;
                img[i][j] += (sum/count)*256;
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                img[i][j] /= 256;
            }
        }
        
        return img;
    }
};
*/


// 3. More optimised version
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // Save the dimensions of the image.
        int m = img.size();
        int n = img[0].size();

        // Iterate over the cells of the image.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Initialize the sum and count 
                int sum = 0;
                int count = 0;

                // Iterate over all plausible nine indices.
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        // If the indices form valid neighbor
                        if (0 <= x && x < m && 0 <= y && y < n) {
                            // Extract the original value of img[x][y].
                            sum += img[x][y] & 255;
                            count += 1;
                        }
                    }
                }
                
                // Encode the smoothed value in img[i][j].
                img[i][j] |= (sum / count) << 8;
            }
        }

        // Extract the smoothed value from encoded img[i][j].
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                img[i][j] >>= 8;
            }
        }

        // Return the smooth image.
        return img;
    }
};
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int x = image.size();
        int y = image[0].size();
        for(int i = 0; i < x; i++){
            reverse(image[i].begin(), image[i].end());
            for(int j = 0; j < y; j++){
                if (image[i][j] == 1){
                    image[i][j] = 0;
                }
                else{
                    image[i][j] = 1;
                }
            }
        }
        return image;



    }
};
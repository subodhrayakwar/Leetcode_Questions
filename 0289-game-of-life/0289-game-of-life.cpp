class Solution {
    int check(vector<vector<int>>& b, int i, int j){
        int l = 0, d = 0;

        if(i-1 >= 0 && (b[i-1][j] == 0 || b[i-1][j] == 3)) d++;
        if(i-1 >= 0 && (b[i-1][j] == 1 || b[i-1][j] == 2)) l++;

        if(i+1 < b.size() && (b[i+1][j] == 0 || b[i+1][j] == 3)) d++;
        if(i+1 < b.size() && (b[i+1][j] == 1 || b[i+1][j] == 2)) l++;

        if(j-1 >= 0 && (b[i][j-1] == 0 || b[i][j-1] == 3)) d++;
        if(j-1 >= 0 && (b[i][j-1] == 1 || b[i][j-1] == 2)) l++;

        if(j+1 < b[0].size() && (b[i][j+1] == 0 || b[i][j+1] == 3)) d++;
        if(j+1 < b[0].size() && (b[i][j+1] == 1 || b[i][j+1] == 2)) l++;

        if(i-1 >= 0){
            if(j-1 >= 0 && (b[i-1][j-1] == 0 || b[i-1][j-1] == 3)) d++;
            if(j-1 >= 0 && (b[i-1][j-1] == 1 || b[i-1][j-1] == 2)) l++;

            if(j+1 < b[0].size() && (b[i-1][j+1] == 0 || b[i-1][j+1] == 3)) d++;
            if(j+1 < b[0].size() && (b[i-1][j+1] == 1 || b[i-1][j+1] == 2)) l++;
        }

        if(i+1 < b.size()){
            if(j-1 >= 0 && (b[i+1][j-1] == 0 || b[i+1][j-1] == 3)) d++;
            if(j-1 >= 0 && (b[i+1][j-1] == 1 || b[i+1][j-1] == 2)) l++;

            if(j+1 < b[0].size() && (b[i+1][j+1] == 0 || b[i+1][j+1] == 3)) d++;
            if(j+1 < b[0].size() && (b[i+1][j+1] == 1 || b[i+1][j+1] == 2)) l++;
        }

        if(b[i][j] == 0){
            if(l == 3) return 3;
        }
        if(b[i][j] == 1){
            if(l < 2 || l > 3) return 2;
            else return 1;
        }
        return 0;
    }

public:
    void gameOfLife(vector<vector<int>>& b) {
        int r = b.size(), c = b[0].size();

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                b[i][j] = check(b, i, j);
            }
        }

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                b[i][j] = b[i][j] % 2;
            }
        }
    }
};
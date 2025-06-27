class Solution {
public:

    // Helper function to find the largest square area in a histogram
    int findMax(vector<int>& heights){
        int n = heights.size();
        stack<int>st;
        // Vector for storing previous smallest element indices, initialized with -1
        vector<int>pse(n,-1);
        // Vector for storing next smallest element indices, initialized with n
        vector<int>nse(n,n);
        int maxArea = 0;

        // Finding PSE for each bar
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                st.pop();
            }
            if(!st.empty()) pse[i] = st.top();
            st.push(i);
        }

        // Clearing the stack before nse computation
        while(!st.empty()) st.pop();

        // Finding NSE for each bar
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()) nse[i] = st.top();
            st.push(i);
        }

        // Calculate the maximal square area possible at each bar
        for(int i=0;i<n;i++){
            int width = nse[i] - pse[i] - 1;   // Maximum width available for current bar
            int side = min(heights[i],width);  // Maximum side length of square at this bar
            maxArea = max(maxArea,side*side);  // Update max area if this square is larger
        }
        return maxArea;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Initialize a vector representing histogram to store vertical heights of 1's
        vector<int>heights(n,0);
        int maxArea = 0;

        // Traverse trough each cell of the matrix
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // If cell is '1', increase the column height by 1
                if(matrix[i][j]=='1') heights[j]++;
                // Else reset height to 0 
                else heights[j] = 0;
            }
            // Compute largest square area for the current histogram row
            maxArea = max(maxArea,findMax(heights));
        }
        return maxArea;
    }
};
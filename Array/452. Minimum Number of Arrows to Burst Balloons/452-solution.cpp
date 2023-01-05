bool compare(vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        // Testcase :
        // Default : [[9,12],[1,10],[4,11],[8,12],[3,9],[6,9],[6,7]]
        // Sorted : [[6,7],[3,9],[6,9],[1,10],[4,11],[9,12],[8,12]]

        int n = points.size();
        int res = 0;
        int lastArrowPosition = INT_MIN;

        sort(points.begin(), points.end(), compare);

        for(auto p : points){
            if(res == 0 || p[0] > lastArrowPosition){
                lastArrowPosition = p[1];
                res++;
            }
        }

        return res;
    }
};
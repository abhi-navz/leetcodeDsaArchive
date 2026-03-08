class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int lsum = 0, rsum = 0;

        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }
        int maxPoints = lsum;

        for (int i = 1; i <= k; i++) {
            lsum = lsum - cardPoints[k - i];
            rsum = rsum + cardPoints[n - i];

            maxPoints = max(maxPoints, lsum + rsum);
        }

        return maxPoints;
    }
};

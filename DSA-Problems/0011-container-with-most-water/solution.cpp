class Solution {
public:
    int maxArea(vector<int>& height) {

        int n = height.size();
        int st =0, end = n-1;

        int maxArea =0;

        while(st<end){
            
            int currentArea =0;

            if(height[st]<height[end]){
                currentArea = (height[st])*(end-st);
                st++;
            }else{
                currentArea = (height[end])*(end-st);
                 end--;
            }

            maxArea = max(maxArea, currentArea);

           


        }

        return maxArea;
        
    }
};

class Solution {
    public int searchInsert(int[] nums, int target) {
        // upper_bound 

        int l=0,r=nums.length-1;
        while(l<=r){
            int m=(l+r)/2;

            if(nums[m]>=target){
                r=m-1;
            }else l=m+1;
        }

        return l;

    }
}
import java.util.Arrays;

public class _3Sum_Closest {
	public static void main(String args[]) {
		int a[] = {-1,2,1,-4}, result = 0;
		result = threeSumClosest(a, 1);
		System.out.println(result);
	}
    public static int threeSumClosest(int[] nums, int target) {
    	int min = 1000000000, min2 = 1000000000;
    	
    	Arrays.sort(nums);
    	for(int n1 = 0; n1 < nums.length - 2; ++n1) {
    		int r = nums.length - 1;
    		if(n1 == 0 || nums[n1] != nums[n1 - 1]) {
    			for(int l = n1 + 1; l < r; ++l) {
    				int sum = nums[n1] + nums[l] + nums[r];
    				while(l < r && sum >= target) {
    					min = min > sum? sum: min;
    					--r;
    					sum = nums[n1] + nums[l] + nums[r];
    				}
    			}
    		}
    	}
    	
    	for(int n = 0; n < nums.length; ++n) {
    		nums[n] *= -1;
    	}
    	Arrays.sort(nums);
    	for(int n1 = 0; n1 < nums.length - 2; ++n1) {
    		int r = nums.length - 1;
    		if(n1 == 0 || nums[n1] != nums[n1 - 1]) {
    			for(int l = n1 + 1; l < r; ++l) {
    				int sum = nums[n1] + nums[l] + nums[r];
    				while(l < r && sum >= target * -1) {
    					min2 = min2 > sum? sum: min2;
    					--r;
    					sum = nums[n1] + nums[l] + nums[r];
    				}
    			}
    		}
    	}
    	
//    	System.out.println(min);
//    	System.out.println(min2);
        return min - target <= min2 + target? min: min2 * -1;
    }
}

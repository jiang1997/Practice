
public class _10RegExMatch {
	public static void main(String[] args) {
		isMatch("aaabbc","aa");
	}
    public static boolean isMatch(String s, String p) {
    	char[] sA = s.toCharArray();
    	char[] pA = p.toCharArray();
    	int[] sR = new int[1000];
    	int[][] pR = new int[2][1000];
    	int index = 0;
    	for(int n1 = 0; n1 < s.length(); ++n1 ) {
    		if(sA[index] != sA[n1]) {
    			index = n1;
    		}
    		++sR[index];
    	}
    	
    	for(int n1 = 0; n1 < p.length(); ++n1 ) {
    		if(sA[index] != sA[n1]) {
    			index = n1;
    		}
    		++sR[index];
    	}
    	System.out.println(sR[3]);

		return false;
    }
}

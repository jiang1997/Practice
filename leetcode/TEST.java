import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;

public class TEST {
	public static void main(String[] args) {
		HashMap<Integer, int[]> map = new HashMap<Integer, int[]>();
		map.put(1, new int[]{1});
		map.put(2, new int[]{2});
		map.put(3, new int[]{3});
		map.put(4, new int[]{4});
		Iterator i = map.entrySet().iterator();
		
		while(i.hasNext()) {
			Map.Entry<Integer, int[]> entry = (Map.Entry<Integer, int[]>) i.next();
			int[] arry = entry.getValue();
			int a = -55555;
			System.out.printf("%d %d %s\n", entry.getKey(), entry.getValue()[0],Integer.toString(a));
		}
	}
}

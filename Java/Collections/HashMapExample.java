package Java.Collections;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.TreeMap;

public class HashMapExample {
    public static void main(String[] args) {
        TreeMap<String, Integer> hashMap = new TreeMap<>();
        hashMap.put("One", 1);
        hashMap.put("Two", 2);
        hashMap.put("Three", 3);
        hashMap.put("Four", 4);

        // Iteration order is not guaranteed
        for (String key : hashMap.keySet()) {
            System.out.println(key + ": " + hashMap.get(key));
        }
        
        LinkedHashMap<Integer, Integer> hashMap2 = new LinkedHashMap<>();
        hashMap2.put(13, 2);
        hashMap2.put(12, 1);
        hashMap2.put(14, 3);
        for (Integer key : hashMap2.keySet())
            System.out.println(key + ": " + hashMap2.get(key));
        
    }
}
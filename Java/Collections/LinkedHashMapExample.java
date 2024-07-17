package Java.Collections;

import java.util.LinkedHashMap;

public class LinkedHashMapExample {
    public static void main(String[] args) {
        LinkedHashMap<String, Integer> linkedHashMap = new LinkedHashMap<>();
        linkedHashMap.put("Two", 2);
        linkedHashMap.put("One", 1);
        linkedHashMap.put("Three", 3);

        // Iteration order is guaranteed to be insertion order
        for (String key : linkedHashMap.keySet()) {
            System.out.println(key + ": " + linkedHashMap.get(key));
        }
    }
}

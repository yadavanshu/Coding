package Java.Collections;

import java.util.ArrayList;
import java.util.HashSet;

public class HashSetExample {
    public static void main(String[] args)
    {
        HashSet<ArrayList> set = new HashSet<>();
        HashSet<Integer> st = new HashSet<>();

        st.add(5);
        st.add(2);
        st.add(1);
        st.add(3);
        st.add(4);

        System.out.println(st);

        ArrayList<Integer> list1 = new ArrayList<>();
        ArrayList<Integer> list2 = new ArrayList<>();
        ArrayList<Integer> list3 = new ArrayList<>();

        list1.add(1);
        list1.add(2);
        list1.add(3);
        list2.add(1);
        list2.add(2);
        list2.add(4);
        list3.add(1);
        list3.add(2);
        list3.add(5);
        set.add(list1);
        set.add(list2);
        set.add(list3);

        System.out.println("Set: "+set);
        System.out.println(set.size());
    }
}

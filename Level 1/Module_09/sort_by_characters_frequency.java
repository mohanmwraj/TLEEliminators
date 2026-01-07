// package Level 1.Module_09;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sort_by_characters_frequency {
    public static void main(String[] args) {
        String s = "tree";
        System.out.println(frequencySort(s));
    }

    private static String frequencySort(String s) {
        if(s == null || s.length() == 0) {
            return s;
        }

        Map<Character, Integer> frequencyMap = new HashMap<>();
        for(char c : s.toCharArray()) {
            frequencyMap.put(c, frequencyMap.getOrDefault(c, 0) + 1);
        }   
        
        int maxFrequency = Collections.max(frequencyMap.values());
        
        List<List<Character>> buckets = new ArrayList<>();
        for(int i = 0; i <= maxFrequency; i++) {
            buckets.add(new ArrayList<>());
        }
        
        StringBuilder sb = new StringBuilder();
        for(int i = buckets.size() - 1; i >= 0; i--) {
            for(Character c : frequencyMap.keySet()) {
                for(int j = 0; j < i; ++j){
                    sb.append(c);
                }
            }
        }

        return sb.toString();
    }
}

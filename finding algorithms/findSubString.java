/*
给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 长度相同。

 s 中的 串联子串 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。

例如，如果 words = ["ab","cd","ef"]， 那么 "abcdef"， "abefcd"，"cdabef"， "cdefab"，"efabcd"， 和 "efcdab" 都是串联子串。 "acdbef" 不是串联子串，因为他不是任何 words 排列的连接。
返回所有串联子串在 s 中的开始索引。你可以以 任意顺序 返回答案。

 

示例 1：

输入：s = "barfoothefoobarman", words = ["foo","bar"]
输出：[0,9]
解释：因为 words.length == 2 同时 words[i].length == 3，连接的子字符串的长度必须为 6。
子串 "barfoo" 开始位置是 0。它是 words 中以 ["bar","foo"] 顺序排列的连接。
子串 "foobar" 开始位置是 9。它是 words 中以 ["foo","bar"] 顺序排列的连接。
输出顺序无关紧要。返回 [9,0] 也是可以的。
*/



//超出时间限制
class Solution {

    public static List<Integer> findAllOccurrences(String str, String subStr) {
        List<Integer> indices = new ArrayList<>();
        int index = 0;
        while ((index = str.indexOf(subStr, index)) != -1) {
            indices.add(index);
            index ++;
        }
        return indices;
    }
    public static Set<String> generatePermutations(String[] words) {
        Set<String> result = new HashSet<>();
        boolean[] used = new boolean[words.length];
        backtrack(words, used, new StringBuilder(), result);
        return result;
    }
    private static void backtrack(String[] words, boolean[] used, StringBuilder current, Set<String> result) {
        if (current.length() == calculateTotalLength(words)) {
            result.add(current.toString());
            return;
        }
        for (int i = 0; i < words.length; i++) {
            if (used[i]) continue;
            used[i] = true;
            current.append(words[i]);
            backtrack(words, used, current, result);
            current.delete(current.length() - words[i].length(), current.length());
            used[i] = false;
        }
    }
    private static int calculateTotalLength(String[] words) {
        return words.length * words[0].length();
    }
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();
        Set<Integer> set = new HashSet<>();
        Set<String> generatePermutations = generatePermutations(words);
        for (String word : generatePermutations) {
            List<Integer> indices = findAllOccurrences(s, word);
            set.addAll(indices);
        }
        result.addAll(set);
        return result;

    }
}

//滑动窗口
public class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();
        if (s == null || s.length() == 0 || words == null || words.length == 0) {
            return result;
        }

        int wordLen = words[0].length();
        int wordCount = words.length;
        int substringLen = wordLen * wordCount;

        // Create a map to store the frequency of words in the array
        Map<String, Integer> wordMap = new HashMap<>();
        for (String word : words) {
            wordMap.put(word, wordMap.getOrDefault(word, 0) + 1);
        }

        // Loop over all possible starting points
        for (int i = 0; i < wordLen; i++) {
            int left = i, right = i;
            int count = 0;
            Map<String, Integer> windowMap = new HashMap<>();

            while (right + wordLen <= s.length()) {
                // Get the next word in the window
                String word = s.substring(right, right + wordLen);
                right += wordLen;

                if (wordMap.containsKey(word)) {
                    windowMap.put(word, windowMap.getOrDefault(word, 0) + 1);
                    count++;

                    // If the word count exceeds the expected count, shrink the window
                    while (windowMap.get(word) > wordMap.get(word)) {
                        String leftWord = s.substring(left, left + wordLen);
                        windowMap.put(leftWord, windowMap.get(leftWord) - 1);
                        count--;
                        left += wordLen;
                    }

                    // If the window matches the word count, record the start index
                    if (count == wordCount) {
                        result.add(left);
                    }
                } else {
                    // If the word is not in words, reset the window
                    windowMap.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
}

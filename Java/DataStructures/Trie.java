import java.util.HashMap;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Trie {
    private TrieNode root;
    
    private static class TrieNode {
        Map<Character, TrieNode> children;
        boolean isEndOfWord;
        
        TrieNode() {
            children = new HashMap<Character, TrieNode>();
            isEndOfWord = false;
        }
    }
    
    public Trie() {
        root = new TrieNode();
    }
    
    public void insert(String word) {
        TrieNode current = root;
        for (char ch : word.toCharArray()) {
            if (!current.children.containsKey(ch)) {
                current.children.put(ch, new TrieNode());
            }
            current = current.children.get(ch);
        }
        current.isEndOfWord = true;
    }
    
    public boolean search(String word) {
        TrieNode current = root;
        for (char ch : word.toCharArray()) {
            if (!current.children.containsKey(ch)) {
                return false;
            }
            current = current.children.get(ch);
        }
        return current.isEndOfWord;
    }
    
    public boolean startsWith(String prefix) {
        TrieNode current = root;
        for (char ch : prefix.toCharArray()) {
            if (!current.children.containsKey(ch)) {
                return false;
            }
            current = current.children.get(ch);
        }
        return true;
    }
    
    public void delete(String word) {
        delete(root, word, 0);
    }
    
    private boolean delete(TrieNode current, String word, int index) {
        if (index == word.length()) {
            if (!current.isEndOfWord) {
                return false;
            }
            current.isEndOfWord = false;
            return current.children.isEmpty();
        }
        
        char ch = word.charAt(index);
        TrieNode node = current.children.get(ch);
        
        if (node == null) {
            return false;
        }
        
        boolean shouldDeleteChild = delete(node, word, index + 1);
        
        if (shouldDeleteChild) {
            current.children.remove(ch);
            return !current.isEndOfWord && current.children.isEmpty();
        }
        
        return false;
    }
    
    public List<String> getAllWords() {
        List<String> result = new ArrayList<>();
        getAllWords(root, new StringBuilder(), result);
        return result;
    }
    
    private void getAllWords(TrieNode node, StringBuilder prefix, List<String> result) {
        if (node.isEndOfWord) {
            result.add(prefix.toString());
        }
        
        for (Map.Entry<Character, TrieNode> entry : node.children.entrySet()) {
            prefix.append(entry.getKey());
            getAllWords(entry.getValue(), prefix, result);
            prefix.deleteCharAt(prefix.length() - 1);
        }
    }
    
    public List<String> getWordsWithPrefix(String prefix) {
        List<String> result = new ArrayList<>();
        TrieNode current = root;
        
        for (char ch : prefix.toCharArray()) {
            if (!current.children.containsKey(ch)) {
                return result;
            }
            current = current.children.get(ch);
        }
        
        getAllWords(current, new StringBuilder(prefix), result);
        return result;
    }
    
    public int countWords() {
        return countWords(root);
    }
    
    private int countWords(TrieNode node) {
        int count = 0;
        if (node.isEndOfWord) {
            count = 1;
        }
        
        for (TrieNode child : node.children.values()) {
            count += countWords(child);
        }
        
        return count;
    }
    
    public boolean isEmpty() {
        return root.children.isEmpty();
    }
    
    public void clear() {
        root = new TrieNode();
    }
    
    public String longestCommonPrefix() {
        if (isEmpty()) {
            return "";
        }
        
        StringBuilder lcp = new StringBuilder();
        TrieNode current = root;
        
        while (current.children.size() == 1 && !current.isEndOfWord) {
            Character ch = current.children.keySet().iterator().next();
            TrieNode nextNode = current.children.get(ch);
            lcp.append(ch);
            current = nextNode;
        }
        
        return lcp.toString();
    }
    
    public void display() {
        System.out.println("Trie contents:");
        List<String> words = getAllWords();
        for (String word : words) {
            System.out.println(word);
        }
    }
}
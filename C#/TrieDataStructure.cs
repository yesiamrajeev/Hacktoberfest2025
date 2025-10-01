/**
 * Trie (Prefix Tree) Data Structure Implementation in C#
 * 
 * A Trie is a tree-like data structure that proves to be quite efficient for 
 * solving problems related to strings. It provides O(m) search and insert time 
 * complexity, where m is the length of the string.
 * 
 * Applications:
 * - Auto-complete functionality
 * - Spell checkers
 * - IP routing (Longest prefix matching)
 * - Word games
 * 
 * Time Complexities:
 * - Insert: O(m) where m is the length of the word
 * - Search: O(m) where m is the length of the word
 * - Delete: O(m) where m is the length of the word
 * 
 * Space Complexity: O(ALPHABET_SIZE * N * M) where N is number of words and M is average length
 * 
 * @author Hacktoberfest2025 Contributor
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace HacktoberfestDSA
{
    /// <summary>
    /// TrieNode represents a single node in the Trie data structure
    /// </summary>
    public class TrieNode
    {
        public Dictionary<char, TrieNode> Children { get; set; }
        public bool IsEndOfWord { get; set; }
        public int WordCount { get; set; }  // Count of words ending at this node
        
        public TrieNode()
        {
            Children = new Dictionary<char, TrieNode>();
            IsEndOfWord = false;
            WordCount = 0;
        }
    }

    /// <summary>
    /// Trie (Prefix Tree) implementation with comprehensive functionality
    /// </summary>
    public class Trie
    {
        private TrieNode root;
        private int totalWords;

        /// <summary>
        /// Initialize the Trie with an empty root node
        /// </summary>
        public Trie()
        {
            root = new TrieNode();
            totalWords = 0;
        }

        /// <summary>
        /// Insert a word into the Trie
        /// </summary>
        /// <param name="word">The word to insert</param>
        public void Insert(string word)
        {
            if (string.IsNullOrEmpty(word))
                return;

            TrieNode current = root;
            word = word.ToLower(); // Case insensitive

            foreach (char c in word)
            {
                if (!current.Children.ContainsKey(c))
                {
                    current.Children[c] = new TrieNode();
                }
                current = current.Children[c];
            }

            if (!current.IsEndOfWord)
            {
                current.IsEndOfWord = true;
                totalWords++;
            }
            current.WordCount++;
        }

        /// <summary>
        /// Search for a word in the Trie
        /// </summary>
        /// <param name="word">The word to search for</param>
        /// <returns>True if word exists, false otherwise</returns>
        public bool Search(string word)
        {
            if (string.IsNullOrEmpty(word))
                return false;

            TrieNode current = root;
            word = word.ToLower();

            foreach (char c in word)
            {
                if (!current.Children.ContainsKey(c))
                {
                    return false;
                }
                current = current.Children[c];
            }

            return current.IsEndOfWord;
        }

        /// <summary>
        /// Check if any word in the Trie starts with the given prefix
        /// </summary>
        /// <param name="prefix">The prefix to check</param>
        /// <returns>True if prefix exists, false otherwise</returns>
        public bool StartsWith(string prefix)
        {
            if (string.IsNullOrEmpty(prefix))
                return true;

            TrieNode current = root;
            prefix = prefix.ToLower();

            foreach (char c in prefix)
            {
                if (!current.Children.ContainsKey(c))
                {
                    return false;
                }
                current = current.Children[c];
            }

            return true;
        }

        /// <summary>
        /// Get all words that start with the given prefix
        /// </summary>
        /// <param name="prefix">The prefix to search for</param>
        /// <returns>List of words with the given prefix</returns>
        public List<string> GetWordsWithPrefix(string prefix)
        {
            List<string> result = new List<string>();
            
            if (string.IsNullOrEmpty(prefix))
                return result;

            TrieNode current = root;
            prefix = prefix.ToLower();

            // Navigate to the prefix
            foreach (char c in prefix)
            {
                if (!current.Children.ContainsKey(c))
                {
                    return result; // Prefix doesn't exist
                }
                current = current.Children[c];
            }

            // Collect all words from this point
            CollectWords(current, prefix, result);
            return result;
        }

        /// <summary>
        /// Helper method to collect all words from a given node
        /// </summary>
        private void CollectWords(TrieNode node, string currentWord, List<string> result)
        {
            if (node.IsEndOfWord)
            {
                result.Add(currentWord);
            }

            foreach (var child in node.Children)
            {
                CollectWords(child.Value, currentWord + child.Key, result);
            }
        }

        /// <summary>
        /// Delete a word from the Trie
        /// </summary>
        /// <param name="word">The word to delete</param>
        /// <returns>True if word was deleted, false if word didn't exist</returns>
        public bool Delete(string word)
        {
            if (string.IsNullOrEmpty(word))
                return false;

            word = word.ToLower();
            return DeleteHelper(root, word, 0);
        }

        /// <summary>
        /// Helper method for deletion
        /// </summary>
        private bool DeleteHelper(TrieNode node, string word, int index)
        {
            if (index == word.Length)
            {
                // End of word reached
                if (!node.IsEndOfWord)
                    return false; // Word doesn't exist

                node.IsEndOfWord = false;
                node.WordCount--;
                totalWords--;

                // Return true if current has no children (can be deleted)
                return node.Children.Count == 0;
            }

            char c = word[index];
            if (!node.Children.ContainsKey(c))
                return false; // Word doesn't exist

            TrieNode childNode = node.Children[c];
            bool shouldDeleteChild = DeleteHelper(childNode, word, index + 1);

            if (shouldDeleteChild)
            {
                node.Children.Remove(c);
                // Return true if current node has no children and is not end of another word
                return node.Children.Count == 0 && !node.IsEndOfWord;
            }

            return false;
        }

        /// <summary>
        /// Get the count of words in the Trie
        /// </summary>
        /// <returns>Total number of unique words</returns>
        public int GetWordCount()
        {
            return totalWords;
        }

        /// <summary>
        /// Get all words stored in the Trie
        /// </summary>
        /// <returns>List of all words</returns>
        public List<string> GetAllWords()
        {
            List<string> result = new List<string>();
            CollectWords(root, "", result);
            return result;
        }

        /// <summary>
        /// Find the longest common prefix of all words in the Trie
        /// </summary>
        /// <returns>Longest common prefix string</returns>
        public string LongestCommonPrefix()
        {
            if (totalWords == 0)
                return "";

            StringBuilder prefix = new StringBuilder();
            TrieNode current = root;

            while (current.Children.Count == 1 && !current.IsEndOfWord)
            {
                var child = current.Children.First();
                prefix.Append(child.Key);
                current = child.Value;
            }

            return prefix.ToString();
        }

        /// <summary>
        /// Check if the Trie is empty
        /// </summary>
        /// <returns>True if empty, false otherwise</returns>
        public bool IsEmpty()
        {
            return totalWords == 0;
        }

        /// <summary>
        /// Display the Trie structure (for debugging)
        /// </summary>
        public void DisplayTrie()
        {
            Console.WriteLine("=== Trie Structure ===");
            DisplayTrieHelper(root, "", 0);
            Console.WriteLine($"Total Words: {totalWords}");
        }

        /// <summary>
        /// Helper method to display Trie structure
        /// </summary>
        private void DisplayTrieHelper(TrieNode node, string prefix, int depth)
        {
            if (node.IsEndOfWord)
            {
                Console.WriteLine($"{new string(' ', depth * 2)}'{prefix}' (End of Word - Count: {node.WordCount})");
            }

            foreach (var child in node.Children.OrderBy(x => x.Key))
            {
                Console.WriteLine($"{new string(' ', depth * 2)}{child.Key}");
                DisplayTrieHelper(child.Value, prefix + child.Key, depth + 1);
            }
        }
    }

    /// <summary>
    /// Auto-complete system using Trie
    /// </summary>
    public class AutoComplete
    {
        private Trie trie;
        private int maxSuggestions;

        public AutoComplete(int maxSuggestions = 10)
        {
            trie = new Trie();
            this.maxSuggestions = maxSuggestions;
        }

        /// <summary>
        /// Add a word to the auto-complete dictionary
        /// </summary>
        public void AddWord(string word)
        {
            trie.Insert(word);
        }

        /// <summary>
        /// Get auto-complete suggestions for a given prefix
        /// </summary>
        public List<string> GetSuggestions(string prefix)
        {
            var suggestions = trie.GetWordsWithPrefix(prefix);
            return suggestions.Take(maxSuggestions).ToList();
        }
    }

    /// <summary>
    /// Spell checker using Trie
    /// </summary>
    public class SpellChecker
    {
        private Trie dictionary;

        public SpellChecker()
        {
            dictionary = new Trie();
        }

        /// <summary>
        /// Add a word to the dictionary
        /// </summary>
        public void AddToDictionary(string word)
        {
            dictionary.Insert(word);
        }

        /// <summary>
        /// Check if a word is spelled correctly
        /// </summary>
        public bool IsCorrect(string word)
        {
            return dictionary.Search(word);
        }

        /// <summary>
        /// Get spelling suggestions (simplified - based on prefix matching)
        /// </summary>
        public List<string> GetSuggestions(string word, int maxSuggestions = 5)
        {
            // Simple suggestion based on prefixes
            var suggestions = new List<string>();
            
            for (int i = 1; i <= word.Length; i++)
            {
                string prefix = word.Substring(0, i);
                var prefixSuggestions = dictionary.GetWordsWithPrefix(prefix);
                suggestions.AddRange(prefixSuggestions.Take(maxSuggestions - suggestions.Count));
                
                if (suggestions.Count >= maxSuggestions)
                    break;
            }
            
            return suggestions.Distinct().Take(maxSuggestions).ToList();
        }
    }

    /// <summary>
    /// Program class to demonstrate Trie functionality
    /// </summary>
    public class Program
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("🌟 Trie Data Structure Implementation 🌟");
            Console.WriteLine("========================================");

            DemonstrateBasicTrie();
            DemonstrateAutoComplete();
            DemonstrateSpellChecker();

            Console.WriteLine("\n✨ All Trie demonstrations completed successfully! ✨");
            Console.ReadLine(); // Keep console open
        }

        static void DemonstrateBasicTrie()
        {
            Console.WriteLine("\n=== Basic Trie Operations ===");

            Trie trie = new Trie();

            // Insert words
            string[] words = { "apple", "app", "application", "apply", "banana", "band", "bandana" };
            Console.WriteLine("Inserting words: " + string.Join(", ", words));
            
            foreach (string word in words)
            {
                trie.Insert(word);
            }

            Console.WriteLine($"Total words in Trie: {trie.GetWordCount()}");

            // Search operations
            Console.WriteLine("\n--- Search Operations ---");
            Console.WriteLine($"Search 'app': {trie.Search("app")}");
            Console.WriteLine($"Search 'apple': {trie.Search("apple")}");
            Console.WriteLine($"Search 'appl': {trie.Search("appl")}");

            // Prefix operations
            Console.WriteLine("\n--- Prefix Operations ---");
            Console.WriteLine($"Starts with 'app': {trie.StartsWith("app")}");
            Console.WriteLine($"Starts with 'ban': {trie.StartsWith("ban")}");
            Console.WriteLine($"Starts with 'cat': {trie.StartsWith("cat")}");

            // Get words with prefix
            Console.WriteLine("\n--- Words with Prefix 'app' ---");
            var appWords = trie.GetWordsWithPrefix("app");
            Console.WriteLine(string.Join(", ", appWords));

            // All words
            Console.WriteLine("\n--- All Words in Trie ---");
            var allWords = trie.GetAllWords();
            Console.WriteLine(string.Join(", ", allWords));

            // Longest common prefix
            Console.WriteLine($"\nLongest Common Prefix: '{trie.LongestCommonPrefix()}'");

            // Delete operation
            Console.WriteLine("\n--- Delete Operation ---");
            Console.WriteLine($"Deleting 'app': {trie.Delete("app")}");
            Console.WriteLine($"Search 'app' after deletion: {trie.Search("app")}");
            Console.WriteLine($"Words with prefix 'app' after deletion: {string.Join(", ", trie.GetWordsWithPrefix("app"))}");
        }

        static void DemonstrateAutoComplete()
        {
            Console.WriteLine("\n=== Auto-Complete System ===");

            AutoComplete autoComplete = new AutoComplete(5);

            // Add programming languages
            string[] languages = {
                "javascript", "java", "python", "csharp", "cpp", "c", "swift",
                "kotlin", "go", "rust", "typescript", "php", "ruby"
            };

            foreach (string lang in languages)
            {
                autoComplete.AddWord(lang);
            }

            // Test auto-complete
            Console.WriteLine("\nAuto-complete suggestions:");
            string[] testPrefixes = { "j", "py", "c", "type" };

            foreach (string prefix in testPrefixes)
            {
                var suggestions = autoComplete.GetSuggestions(prefix);
                Console.WriteLine($"'{prefix}' -> {string.Join(", ", suggestions)}");
            }
        }

        static void DemonstrateSpellChecker()
        {
            Console.WriteLine("\n=== Spell Checker System ===");

            SpellChecker spellChecker = new SpellChecker();

            // Add dictionary words
            string[] dictionary = {
                "hello", "world", "programming", "algorithm", "data", "structure",
                "computer", "science", "software", "development", "code", "debug"
            };

            foreach (string word in dictionary)
            {
                spellChecker.AddToDictionary(word);
            }

            // Test spell checking
            string[] testWords = { "hello", "wrold", "progaming", "algoritm", "code" };

            Console.WriteLine("\nSpell checking results:");
            foreach (string word in testWords)
            {
                bool isCorrect = spellChecker.IsCorrect(word);
                Console.Write($"'{word}' -> {(isCorrect ? "✓ Correct" : "✗ Incorrect")}");
                
                if (!isCorrect)
                {
                    var suggestions = spellChecker.GetSuggestions(word, 3);
                    if (suggestions.Count > 0)
                    {
                        Console.WriteLine($" (Suggestions: {string.Join(", ", suggestions)})");
                    }
                    else
                    {
                        Console.WriteLine(" (No suggestions)");
                    }
                }
                else
                {
                    Console.WriteLine();
                }
            }
        }
    }
}
import java.util.*;

/**
 * Sieve of Eratosthenes Algorithm Implementation
 * 
 * The Sieve of Eratosthenes is an ancient algorithm used to find all prime numbers 
 * up to any given limit. It works by iteratively marking the multiples of each prime 
 * number starting from 2.
 * 
 * Time Complexity: O(n log log n)
 * Space Complexity: O(n)
 * 
 * 
 */
public class Sieveoferatothenes {
    
    /**
     * Find all prime numbers up to n using Sieve of Eratosthenes algorithm
     * 
     * @param n The upper limit (inclusive) to find primes up to
     * @return List of all prime numbers up to n
     */
    public static List<Integer> sieveOfEratosthenes(int n) {
        if (n < 2) {
            return new ArrayList<>();
        }
        
        // Create a boolean array "prime[0..n]" and initialize all entries as true
        boolean[] prime = new boolean[n + 1];
        Arrays.fill(prime, true);
        prime[0] = prime[1] = false; // 0 and 1 are not prime numbers
        
        // Start with the smallest prime number, 2
        for (int p = 2; p * p <= n; p++) {
            // If prime[p] is not changed, then it is a prime
            if (prime[p]) {
                // Mark all multiples of p starting from p*p
                for (int i = p * p; i <= n; i += p) {
                    prime[i] = false;
                }
            }
        }
        
        // Collect all prime numbers
        List<Integer> primes = new ArrayList<>();
        for (int i = 2; i <= n; i++) {
            if (prime[i]) {
                primes.add(i);
            }
        }
        
        return primes;
    }
    
   
    public static boolean[] sieveArray(int n) {
        if (n < 2) {
            return new boolean[0];
        }
        
        boolean[] prime = new boolean[n + 1];
        Arrays.fill(prime, true);
        prime[0] = prime[1] = false;
        
        for (int p = 2; p * p <= n; p++) {
            if (prime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    prime[i] = false;
                }
            }
        }
        
        return prime;
    }
    
    /**
     * Count the number of prime numbers up to n
     * 
     * @param n The upper limit
     * @return Count of prime numbers up to n
     */
    public static int countPrimes(int n) {
        if (n < 2) return 0;
        
        boolean[] prime = new boolean[n + 1];
        Arrays.fill(prime, true);
        prime[0] = prime[1] = false;
        
        int count = 0;
        for (int p = 2; p * p <= n; p++) {
            if (prime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    prime[i] = false;
                }
            }
        }
        
        for (int i = 2; i <= n; i++) {
            if (prime[i]) count++;
        }
        
        return count;
    }
    
    /**
     * Main method to demonstrate the Sieve of Eratosthenes algorithm
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("=== Sieve of Eratosthenes Algorithm ===");
        System.out.print("Enter the upper limit to find prime numbers: ");
        
        int n = scanner.nextInt();
        
        if (n < 2) {
            System.out.println("No prime numbers exist below 2.");
            scanner.close();
            return;
        }
        
        // Find all primes up to n
        long startTime = System.currentTimeMillis();
        List<Integer> primes = sieveOfEratosthenes(n);
        long endTime = System.currentTimeMillis();
        
        // Display results
        System.out.println("\nPrime numbers up to " + n + ":");
        System.out.println(primes);
        
        System.out.println("\nTotal count of primes: " + primes.size());
        System.out.println("Time taken: " + (endTime - startTime) + " ms");
        
        // Demonstrate other methods
        System.out.println("\nUsing countPrimes method: " + countPrimes(n) + " primes found");
        
        // Show first few and last few primes for large inputs
        if (primes.size() > 20) {
            System.out.println("\nFirst 10 primes: " + primes.subList(0, 10));
            System.out.println("Last 10 primes: " + 
                primes.subList(primes.size() - 10, primes.size()));
        }
        
        scanner.close();
    }
}
code :-

import java.util.Scanner;

public class SieveOfEratosthenes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the limit (n): ");
        int n = sc.nextInt();
        sc.close();

        boolean[] isPrime = new boolean[n + 1];

        // Initialize all numbers as prime
        for (int i = 2; i <= n; i++) {
            isPrime[i] = true;
        }

        // Sieve algorithm
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false; // Mark multiples as non-prime
                }
            }
        }

        // Print prime numbers
        System.out.println("Prime numbers up to " + n + ":");
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                System.out.print(i + " ");
            }
        }
    }
}

How it works:

1. Start with an array isPrime initialized to true for all numbers ≥ 2.


2. For each number i starting from 2, mark all multiples of i as false (not prime).


3. Continue until i*i > n.


4. Remaining true indices are prime numbers.



✅ This is efficient with a time complexity of O(n log l )


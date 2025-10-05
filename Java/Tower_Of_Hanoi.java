import java.util.Scanner;

class Solution {
    public int towerOfHanoi(int n, int from, int to, int aux) {
        if (n == 0) {
            return 0;
        }

        int moves1 = towerOfHanoi(n - 1, from, aux, to);

        System.out.println("Move disk " + n + " from rod " + from + " to rod " + to);
        int move2 = 1;

        int moves3 = towerOfHanoi(n - 1, aux, to, from);

        return moves1 + move2 + moves3;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Solution solver = new Solution();

        System.out.println("--- Tower of Hanoi Solver (Moves and Count) ---");
        System.out.print("Enter the number of disks (n): ");

        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            
            if (n < 0) {
                System.out.println("Please enter a non-negative number of disks.");
            } else {
                System.out.println("\n--- Sequence of Moves ---");
                // Rods are conventionally 1 (from), 3 (to), 2 (aux)
                int moves = solver.towerOfHanoi(n, 1, 3, 2);
                System.out.println("-------------------------");
                System.out.println("Total minimum moves required for " + n + " disks: " + moves);
            }
        } else {
            System.out.println("Invalid input. Please enter an integer.");
        }
        
        scanner.close();
    }
}

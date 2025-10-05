package Java;
import java.util.Scanner;

public class TowerOfHanoi {

    // Recursive method to solve Tower of Hanoi
    public static void solveHanoi(int n, char source, char auxiliary, char destination) {
        if (n == 1) {
            // Base case: only one disk, just move it from source to destination
            System.out.println("Move disk 1 from " + source + " to " + destination);
            return;
        }
        // Move top n-1 disks from source to auxiliary
        solveHanoi(n - 1, source, destination, auxiliary);

        // Move the nth disk from source to destination
        System.out.println("Move disk " + n + " from " + source + " to " + destination);

        // Move the n-1 disks from auxiliary to destination
        solveHanoi(n - 1, auxiliary, source, destination);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of disks: ");
        int n = sc.nextInt();
        System.out.println("Steps to solve Tower of Hanoi with " + n + " disks:");
        solveHanoi(n, 'A', 'B', 'C'); // A = source, B = auxiliary, C = destination
        sc.close();
    }
}

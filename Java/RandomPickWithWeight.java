import java.util.Random;

public class RandomPickWithWeight {
    private int[] prefix;
    private int totalSum;
    private Random rand;

    public RandomPickWithWeight(int[] w) {
        int n = w.length;
        prefix = new int[n];
        prefix[0] = w[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + w[i];
        }
        totalSum = prefix[n - 1];
        rand = new Random();
    }

    public int pickIndex() {
        // pick a random number in [1, totalSum]
        int r = rand.nextInt(totalSum) + 1;  
        // binary search for the first index such that prefix[idx] >= r
        int low = 0, high = prefix.length - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (prefix[mid] < r) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    // For testing
    public static void main(String[] args) {
        int[] w = {1, 3, 2};
        RandomPickWithWeight obj = new RandomPickWithWeight(w);

        // simulate picks and count frequencies
        int trials = 1000000;
        int[] count = new int[w.length];
        for (int i = 0; i < trials; i++) {
            int idx = obj.pickIndex();
            count[idx]++;
        }
        System.out.println("Frequencies:");
        for (int i = 0; i < count.length; i++) {
            System.out.printf("index %d: %.4f%n", i, (double)count[i] / trials);
        }
    }
}

import java.util.*;

/**
 * Strassen Matrix Multiplication Algorithm Implementation
 * 
 * Strassen's algorithm is a divide-and-conquer algorithm for matrix multiplication
 * that is asymptotically faster than the standard O(n³) algorithm.
 * It reduces the number of recursive multiplications from 8 to 7.
 * 
 * Time Complexity: O(n^log₂7) ≈ O(n^2.807)
 * Space Complexity: O(log n) for recursion stack + O(n²) for temporary matrices
 * 
 * @author Hacktoberfest2025 Contributor
 */
public class StrassenMatrixMultiplication {
    
    // Threshold below which to use standard multiplication
    private static final int THRESHOLD = 64;
    
    /**
     * Multiply two matrices using Strassen's algorithm
     * 
     * @param A First matrix
     * @param B Second matrix
     * @return Result matrix A × B
     * @throws IllegalArgumentException if matrices cannot be multiplied
     */
    public static int[][] strassenMultiply(int[][] A, int[][] B) {
        int n = A.length;
        
        // Validate input matrices
        if (!isValidForMultiplication(A, B)) {
            throw new IllegalArgumentException("Invalid matrices for multiplication");
        }
        
        // If matrices are not square or not power of 2, pad them
        int paddedSize = nextPowerOfTwo(Math.max(Math.max(A.length, A[0].length), 
                                                Math.max(B.length, B[0].length)));
        
        int[][] paddedA = padMatrix(A, paddedSize);
        int[][] paddedB = padMatrix(B, paddedSize);
        
        int[][] result = strassenRecursive(paddedA, paddedB);
        
        // Extract the actual result (remove padding)
        return extractMatrix(result, A.length, B[0].length);
    }
    
    /**
     * Recursive implementation of Strassen's algorithm
     * 
     * @param A First matrix (must be square and power of 2)
     * @param B Second matrix (must be square and power of 2)
     * @return Result matrix
     */
    private static int[][] strassenRecursive(int[][] A, int[][] B) {
        int n = A.length;
        
        // Base case: use standard multiplication for small matrices
        if (n <= THRESHOLD) {
            return standardMultiply(A, B);
        }
        
        int half = n / 2;
        
        // Divide matrices into quadrants
        int[][] A11 = getSubMatrix(A, 0, 0, half);
        int[][] A12 = getSubMatrix(A, 0, half, half);
        int[][] A21 = getSubMatrix(A, half, 0, half);
        int[][] A22 = getSubMatrix(A, half, half, half);
        
        int[][] B11 = getSubMatrix(B, 0, 0, half);
        int[][] B12 = getSubMatrix(B, 0, half, half);
        int[][] B21 = getSubMatrix(B, half, 0, half);
        int[][] B22 = getSubMatrix(B, half, half, half);
        
        // Calculate the 7 products using Strassen's formulas
        int[][] M1 = strassenRecursive(add(A11, A22), add(B11, B22));
        int[][] M2 = strassenRecursive(add(A21, A22), B11);
        int[][] M3 = strassenRecursive(A11, subtract(B12, B22));
        int[][] M4 = strassenRecursive(A22, subtract(B21, B11));
        int[][] M5 = strassenRecursive(add(A11, A12), B22);
        int[][] M6 = strassenRecursive(subtract(A21, A11), add(B11, B12));
        int[][] M7 = strassenRecursive(subtract(A12, A22), add(B21, B22));
        
        // Calculate result quadrants
        int[][] C11 = add(subtract(add(M1, M4), M5), M7);
        int[][] C12 = add(M3, M5);
        int[][] C21 = add(M2, M4);
        int[][] C22 = add(subtract(add(M1, M3), M2), M6);
        
        // Combine quadrants into result matrix
        return combineMatrices(C11, C12, C21, C22);
    }
    
    /**
     * Standard O(n³) matrix multiplication for base cases
     */
    private static int[][] standardMultiply(int[][] A, int[][] B) {
        int rows = A.length;
        int cols = B[0].length;
        int common = B.length;
        
        int[][] result = new int[rows][cols];
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = 0; k < common; k++) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        
        return result;
    }
    
    /**
     * Add two matrices
     */
    private static int[][] add(int[][] A, int[][] B) {
        int n = A.length;
        int[][] result = new int[n][n];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = A[i][j] + B[i][j];
            }
        }
        
        return result;
    }
    
    /**
     * Subtract two matrices (A - B)
     */
    private static int[][] subtract(int[][] A, int[][] B) {
        int n = A.length;
        int[][] result = new int[n][n];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = A[i][j] - B[i][j];
            }
        }
        
        return result;
    }
    
    /**
     * Extract a submatrix from the given matrix
     */
    private static int[][] getSubMatrix(int[][] matrix, int row, int col, int size) {
        int[][] subMatrix = new int[size][size];
        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                subMatrix[i][j] = matrix[row + i][col + j];
            }
        }
        
        return subMatrix;
    }
    
    /**
     * Combine four quadrant matrices into one matrix
     */
    private static int[][] combineMatrices(int[][] C11, int[][] C12, int[][] C21, int[][] C22) {
        int half = C11.length;
        int n = 2 * half;
        int[][] result = new int[n][n];
        
        // Copy C11
        for (int i = 0; i < half; i++) {
            for (int j = 0; j < half; j++) {
                result[i][j] = C11[i][j];
            }
        }
        
        // Copy C12
        for (int i = 0; i < half; i++) {
            for (int j = 0; j < half; j++) {
                result[i][j + half] = C12[i][j];
            }
        }
        
        // Copy C21
        for (int i = 0; i < half; i++) {
            for (int j = 0; j < half; j++) {
                result[i + half][j] = C21[i][j];
            }
        }
        
        // Copy C22
        for (int i = 0; i < half; i++) {
            for (int j = 0; j < half; j++) {
                result[i + half][j + half] = C22[i][j];
            }
        }
        
        return result;
    }
    
    /**
     * Pad matrix to make it square with size being power of 2
     */
    private static int[][] padMatrix(int[][] matrix, int newSize) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        
        int[][] padded = new int[newSize][newSize];
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                padded[i][j] = matrix[i][j];
            }
        }
        
        return padded;
    }
    
    /**
     * Extract the actual result matrix (remove padding)
     */
    private static int[][] extractMatrix(int[][] matrix, int rows, int cols) {
        int[][] result = new int[rows][cols];
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = matrix[i][j];
            }
        }
        
        return result;
    }
    
    /**
     * Find the next power of 2 greater than or equal to n
     */
    private static int nextPowerOfTwo(int n) {
        if (n <= 1) return 1;
        
        int power = 1;
        while (power < n) {
            power *= 2;
        }
        
        return power;
    }
    
    /**
     * Check if two matrices can be multiplied
     */
    private static boolean isValidForMultiplication(int[][] A, int[][] B) {
        if (A == null || B == null || A.length == 0 || B.length == 0) {
            return false;
        }
        
        return A[0].length == B.length;
    }
    
    /**
     * Print a matrix in a formatted way
     */
    private static void printMatrix(int[][] matrix, String name) {
        System.out.println("\n" + name + ":");
        
        if (matrix.length > 10 || matrix[0].length > 10) {
            System.out.println("Matrix is too large to display (" + 
                matrix.length + "x" + matrix[0].length + ")");
            return;
        }
        
        for (int[] row : matrix) {
            for (int val : row) {
                System.out.printf("%8d ", val);
            }
            System.out.println();
        }
    }
    
    /**
     * Generate a random matrix for testing
     */
    private static int[][] generateRandomMatrix(int rows, int cols, int maxValue) {
        Random random = new Random();
        int[][] matrix = new int[rows][cols];
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = random.nextInt(2 * maxValue + 1) - maxValue;
            }
        }
        
        return matrix;
    }
    
    /**
     * Compare two matrices for equality
     */
    private static boolean matricesEqual(int[][] A, int[][] B) {
        if (A.length != B.length || A[0].length != B[0].length) {
            return false;
        }
        
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A[0].length; j++) {
                if (A[i][j] != B[i][j]) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    /**
     * Main method to demonstrate Strassen Matrix Multiplication
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("=== Strassen Matrix Multiplication Algorithm ===");
        System.out.println("1. Manual input");
        System.out.println("2. Random matrices");
        System.out.println("3. Performance comparison");
        System.out.print("Choose an option (1-3): ");
        
        int choice = scanner.nextInt();
        
        switch (choice) {
            case 1:
                handleManualInput(scanner);
                break;
            case 2:
                handleRandomMatrices(scanner);
                break;
            case 3:
                performanceComparison();
                break;
            default:
                System.out.println("Invalid choice!");
        }
        
        scanner.close();
    }
    
    private static void handleManualInput(Scanner scanner) {
        System.out.print("Enter rows of first matrix: ");
        int rows1 = scanner.nextInt();
        System.out.print("Enter columns of first matrix: ");
        int cols1 = scanner.nextInt();
        
        System.out.print("Enter rows of second matrix: ");
        int rows2 = scanner.nextInt();
        System.out.print("Enter columns of second matrix: ");
        int cols2 = scanner.nextInt();
        
        if (cols1 != rows2) {
            System.out.println("Error: Cannot multiply matrices. Columns of first matrix must equal rows of second matrix.");
            return;
        }
        
        int[][] A = new int[rows1][cols1];
        int[][] B = new int[rows2][cols2];
        
        System.out.println("Enter elements of first matrix:");
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols1; j++) {
                A[i][j] = scanner.nextInt();
            }
        }
        
        System.out.println("Enter elements of second matrix:");
        for (int i = 0; i < rows2; i++) {
            for (int j = 0; j < cols2; j++) {
                B[i][j] = scanner.nextInt();
            }
        }
        
        long startTime = System.currentTimeMillis();
        int[][] result = strassenMultiply(A, B);
        long endTime = System.currentTimeMillis();
        
        printMatrix(A, "Matrix A");
        printMatrix(B, "Matrix B");
        printMatrix(result, "Result (A × B)");
        
        System.out.println("\nTime taken: " + (endTime - startTime) + " ms");
    }
    
    private static void handleRandomMatrices(Scanner scanner) {
        System.out.print("Enter matrix size (n for n×n matrices): ");
        int n = scanner.nextInt();
        System.out.print("Enter maximum value for random elements: ");
        int maxValue = scanner.nextInt();
        
        int[][] A = generateRandomMatrix(n, n, maxValue);
        int[][] B = generateRandomMatrix(n, n, maxValue);
        
        System.out.println("Generated random " + n + "×" + n + " matrices");
        
        if (n <= 10) {
            printMatrix(A, "Matrix A");
            printMatrix(B, "Matrix B");
        }
        
        long startTime = System.currentTimeMillis();
        int[][] result = strassenMultiply(A, B);
        long endTime = System.currentTimeMillis();
        
        if (n <= 10) {
            printMatrix(result, "Result (A × B)");
        }
        
        System.out.println("Time taken: " + (endTime - startTime) + " ms");
    }
    
    private static void performanceComparison() {
        System.out.println("\n=== Performance Comparison: Strassen vs Standard ===");
        
        int[] sizes = {64, 128, 256, 512};
        
        for (int n : sizes) {
            System.out.println("\nMatrix size: " + n + "×" + n);
            
            int[][] A = generateRandomMatrix(n, n, 100);
            int[][] B = generateRandomMatrix(n, n, 100);
            
            // Test Strassen algorithm
            long startTime = System.currentTimeMillis();
            int[][] strassenResult = strassenMultiply(A, B);
            long strassenTime = System.currentTimeMillis() - startTime;
            
            // Test standard algorithm
            startTime = System.currentTimeMillis();
            int[][] standardResult = standardMultiply(A, B);
            long standardTime = System.currentTimeMillis() - startTime;
            
            // Verify results are the same
            boolean resultsMatch = matricesEqual(strassenResult, standardResult);
            
            System.out.println("Strassen time: " + strassenTime + " ms");
            System.out.println("Standard time: " + standardTime + " ms");
            System.out.println("Speedup: " + String.format("%.2f", (double)standardTime / strassenTime) + "x");
            System.out.println("Results match: " + resultsMatch);
        }
    }
}
// Java program to illustrate Ackermann function

class Main 
{ 

    static int ack(int m, int n)
    {
        if (m == 0)
        {
            return n + 1;
        }
        else if((m > 0) && (n == 0))
        {
            return ack(m - 1, 1);
        }
        else if((m > 0) && (n > 0))
        {
            return ack(m - 1, ack(m, n - 1));
        }else
        return n + 1;
    }

    // Driver code
    public static void main(String args[]) 
    { 
        System.out.println(ack(1, 2)); 
    } 
} 

// This code is contributed by singh-isha

// The time complexity of this algorithm is: O(mA(m, n)) to compute A(m, n) 
 
// The space complexity of this algorithm is: O(m) to compute A(m, n) 

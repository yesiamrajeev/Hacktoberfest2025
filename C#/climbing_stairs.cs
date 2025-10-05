public int ClimbStairs(int n)
{
    if (n <= 2) return n;
    int a = 1, b = 2;
    for (int i = 3; i <= n; i++)
    {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

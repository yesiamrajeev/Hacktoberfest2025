public void MoveZeroes(int[] nums)
{
    int insertPos = 0;
    foreach (int num in nums)
    {
        if (num != 0)
        {
            nums[insertPos++] = num;
        }
    }
    while (insertPos < nums.Length)
    {
        nums[insertPos++] = 0;
    }
}

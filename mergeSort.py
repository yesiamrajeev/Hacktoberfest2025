def mrgsrt(arr):
    n = len(arr)
    if n == 1:
        return arr

    m = n // 2
    L = arr[:m]
    R = arr[m:]

    L = mrgsrt(L)
    R = mrgsrt(R)

    l_len = len(L)
    r_len = len(R)
    l, r = 0, 0

    sorted_arr = [0] * n
    i = 0

    # Merge both halves
    while l < l_len and r < r_len:
        if L[l] < R[r]:
            sorted_arr[i] = L[l]
            l += 1
        else:
            sorted_arr[i] = R[r]
            r += 1
        i += 1  # This must be inside the loop

    # Copy remaining elements of L[], if any
    while l < l_len:
        sorted_arr[i] = L[l]
        l += 1
        i += 1

    # Copy remaining elements of R[], if any
    while r < r_len:
        sorted_arr[i] = R[r]
        r += 1
        i += 1

    return sorted_arr

# Example usage
t = [5, 2, 9, 1, 5, 6]
print(mrgsrt(t))

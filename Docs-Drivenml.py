# calculator/calculations.py

def add(a, b):
    """
    Compute and return the sum of two numbers.

    Examples:
        >>> add(4.0, 2.0)
        6.0
        >>> add(4, 2)
        6.0

    Args:
        a (float): A number representing the first addend.
        b (float): A number representing the second addend.

    Returns:
        float: Arithmetic sum of `a` and `b`.
    """
    return float(a + b)

def subtract(a, b):
    """
    Compute and return the difference between two numbers.

    Examples:
        >>> subtract(5.0, 3.0)
        2.0

    Args:
        a (float): Minuend.
        b (float): Subtrahend.

    Returns:
        float: Difference between `a` and `b`.
    """
    return float(a - b)

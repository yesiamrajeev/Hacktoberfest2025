// Need for Parabolic Curve

// In a ternary search, we divide the search interval into three parts and discard one part in each iteration, until we find the desired value or determine that it doesn't exist in the interval. One common optimization used in ternary search involves using a parabolic curve to guide the search.

// To understand the need for a parabolic curve, let's consider a simple example. Suppose we have a unimodal function f(x) and we want to find its maximum value within a given interval [a, b]. One way to do this is to use a ternary search. We start by dividing the interval [a, b] into three parts, and then evaluate the function at the two points x1 and x2 that divide the interval.

// Suppose that f(x1) > f(x2). This means that the maximum value of f(x) is more likely to be in the interval [a, x2], since we know that f(x1) is already greater than f(x2). So, we can discard the interval [x2, b] and continue the search within the interval [a, x2].

// Now, instead of dividing the remaining interval into three parts again, we can use a parabolic curve to guide the search. We can fit a parabola to the three points (a, f(a)), (x1, f(x1)), and (x2, f(x2)), and find the maximum point of the parabola. Let's call this point xm. If the maximum value of the parabola is at xm, then we can discard the interval [x2, b] and continue the search within the interval [a, x2]. Otherwise, we can discard the interval [a, x1] and continue the search within the interval [x1, b].

// The advantage of using a parabolic curve is that it allows us to make more informed decisions about which part of the interval to discard in each iteration. By fitting a parabola to the function values at the three points, we can estimate the shape of the function and use this information to guide the search towards the maximum value more efficiently.

// In summary, a parabolic curve is used in ternary search to improve the efficiency of the search by guiding the search towards the maximum or minimum value of a unimodal function. By fitting a parabola to the function values at three points, we can estimate the shape of the function and use this information to make more informed decisions about which part of the interval to discard in each iteration.


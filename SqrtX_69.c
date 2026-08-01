/* 69
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

    For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

Example 1:

    Input: x = 4
    Output: 2
    Explanation: The square root of 4 is 2, so we return 2.

Example 2:

    Input: x = 8
    Output: 2
    Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.

Constraints:
    0 <= x <= 2^31 - 1
*/

# include <stdio.h>

int mySqrt(int x){
    if(x < 0){ return -1; }
    if(x == 0){ return 0; }

    double guess = x / 2.0;
    float preci = 0.000001;
    double prev_guess;

    do{
        prev_guess = guess;
        guess = (guess + (x / guess)) / 2.0; 
    } while((prev_guess - guess) > preci || (guess - prev_guess) > preci);

    return (int)guess;
}

int main() {
    int x = 2147483647;

    int result = mySqrt(x);
    (result == -1) ? printf("Sqrt: i") : printf("Sqrt: %d", result);
    
    return 0;
}

// 0 ms of runtime.
// 9.32 MB of mamory.

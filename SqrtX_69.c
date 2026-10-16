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

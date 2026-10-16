# include <stdio.h>
# include <stdbool.h>

bool isPalindrome(int x){
    if(x < 0){ return false; }    
    if(x % 10 == 0 && x != 0){ return false; }

    int inverted = 0;

    while(x > inverted){
        inverted = inverted * 10 + x % 10;
        x /= 10;
    }

    return (x == inverted || x == inverted / 10) ? true : false;
}

int main(){
    int x = 10;

    printf("%d", isPalindrome(x));

    return 0;
}

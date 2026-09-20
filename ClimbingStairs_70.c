# include <stdio.h>

int climbStairs(int n) {
    int i = 1, a = 0, b = 1, c = 0;

    while(i <= n){
        c = a + b;
        a = b;
        b = c;

        i++;
   }
    return c;
}

int main(){
    int amount = climbStairs(4);
    printf("%d\n", amount);

    return 0;
}

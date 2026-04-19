#include <stdio.h>

long long findXor(long long n){
    if(n % 4 == 0) return n;
    if(n % 4 == 1) return 1;
    if(n % 4 == 2) return n + 1;
    return 0;
}

int main(){
    long long l, r;
    scanf("%lld %lld", &l, &r);

    long long result = findXor(r) ^ findXor(l - 1);

    if(result % 2 == 0)
        printf("even");
    else
        printf("odd");

    return 0;
}

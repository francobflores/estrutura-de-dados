#include<stdio.h>

void somatorio(int x){
    if(x > 0){
    x += somatorio(x-1);
    printf("%d", x);
    }
}

int main(){
    somatorio(5);
    return 0;
}
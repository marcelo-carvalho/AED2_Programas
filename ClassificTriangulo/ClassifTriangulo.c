#include <stdio.h>

int main(){
    int a, b, c;
    int soma = 0;
    
    scanf("%d %d %d",&a,&b,&c);
    soma = a + b + c;

    if(a > soma /2 || b > soma /2 || c > soma /2){
        printf("NAO FORMA UM TRIANGULO\n");
    }
    else if(a == b){
       if(b == c){
           printf("EQUILATERO\n");
       }
       else {
           printf("ISOSCELES\n");
       }
    }
    else if (b == c){
        if(a == c){
           printf("EQUILATERO\n");
       }
       else {
           printf("ISOSCELES\n");
       }
    }
    else if (a == c){
        if(b == c){
           printf("EQUILATERO\n");
       }
       else {
           printf("ISOSCELES\n");
       }
    }
    else if(a != b && a != c && b != c){
        printf("ESCALENO\n");
    }

    return 0;
}
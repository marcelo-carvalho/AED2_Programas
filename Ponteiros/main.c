#include <stdio.h>
#include <stdlib.h>

int main(){

    int i, *p, *q;
    i = 0;
    
    
p = &i;
p = *&i;
//p = &*i;
i = *&*p;
i = *&p;
i = &*p;
p = &*&i;
q = *&*p;
q = **&p;
q = *&p;
q = &*p;
    
    return 0;
}
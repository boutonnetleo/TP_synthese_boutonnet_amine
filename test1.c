#include "test1.h"
int main(void){
    test2();
}
void test1(){
    sleep(1);
    exit(39);
}

void test2(){
    int tab[3];
    tab[500000]=1;
}
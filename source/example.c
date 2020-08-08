#include "./../include/example.h"

int MAC(int x, int y, int * sum){
    *sum = *sum + x * y;
    return *sum; 
}
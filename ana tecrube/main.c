#include <stdio.h>
#include <string.h>
#include "algorithms.h"


int main(void){
    
    int taban, us;
    printf("Üslü sayı al: \n");
    scanf("%d%d", &taban, &us);
    printf("Sonuç: %d\n", powRecursive(taban, us));
    
    
    return 0;
}



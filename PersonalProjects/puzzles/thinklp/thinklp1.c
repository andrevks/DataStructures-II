#include <stdio.h>



int main () {
    
        printf("\nFire  -   Police   -   Sanitation\n");
        int Permutations = 0;

        for(int Fire = 1;Fire < 8;Fire++){
            for(int Police = 2; Police < 7; Police++){
                for(int Sanitation = 1; Sanitation < 8; Sanitation++){
                    if( (Police % 2 == 0 && (Fire+Police+Sanitation) == 12)) {

                        if(Fire != Police && Fire != Sanitation && Police != Sanitation){

                            printf("\n%d   -   %d    -   %d",Fire,Police,Sanitation);
                            Permutations++;
                        }
                        
                    }
                }
            }
        }
        printf("\n");
        printf("----------------------\n");
        printf("Permutations Available: %d\n",Permutations);
    return 0;
}
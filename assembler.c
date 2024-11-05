#include <stdio.h>
#include <string.h>
#define N 100 
#include <ctype.h>

int k = 0, i = 0;
char ArSpace[N], ArNoSpace[N];

void compere(FILE *ptr) {
    if (strcmp(ArNoSpace, "RA=0") == 0) {
        fprintf(ptr, "00001000\n");
    } else if (strcmp(ArNoSpace, "RA=1") == 0) {
        fprintf(ptr, "00001001\n");
    } else if (strcmp(ArNoSpace, "RA=2") == 0) {
        fprintf(ptr, "00001010\n");
    }else if (strcmp(ArNoSpace, "RA=3") == 0) {
        fprintf(ptr, "00001011\n");
    }else if (strcmp(ArNoSpace, "RA=4") == 0) {
        fprintf(ptr, "00001100\n");
    }else if (strcmp(ArNoSpace, "RA=5") == 0) {
        fprintf(ptr, "00001101\n");
    }else if (strcmp(ArNoSpace, "RA=6") == 0) {
        fprintf(ptr, "00001110\n");
    }else if (strcmp(ArNoSpace, "RA=7") == 0) {
        fprintf(ptr, "00001111\n");
    }else if (strcmp(ArNoSpace, "RB=0") == 0) {
        fprintf(ptr, "00011000\n");
    }else if (strcmp(ArNoSpace, "RB=1") == 0) {
        fprintf(ptr, "00011001\n");
    }else if (strcmp(ArNoSpace, "RB=2") == 0) {
        fprintf(ptr, "00011010\n");
    }else if (strcmp(ArNoSpace, "RB=3") == 0) {
        fprintf(ptr, "00011011\n");
    }else if (strcmp(ArNoSpace, "RB=4") == 0) {
        fprintf(ptr, "00011100\n");
    }else if (strcmp(ArNoSpace, "RB=5") == 0) {
        fprintf(ptr, "00011101\n");
    }else if (strcmp(ArNoSpace, "RB=6") == 0) {
        fprintf(ptr, "00011110\n");
    }else if (strcmp(ArNoSpace, "RB=7") == 0) {
        fprintf(ptr, "00011111\n");
    } else if (strcmp(ArNoSpace, "RO=RA") == 0) {
        fprintf(ptr, "00100000\n");
    } else if (strcmp(ArNoSpace, "RB=RA+RB") == 0) {
        fprintf(ptr, "00010000\n");
    } else if (strcmp(ArNoSpace, "RB=RA-RB") == 0) {
        fprintf(ptr, "00010100\n");
    } else if (strcmp(ArNoSpace, "JC=0") == 0) {
        fprintf(ptr, "01110000\n");
    }else if (strcmp(ArNoSpace, "JC=1") == 0) {
        fprintf(ptr, "01110001\n");
    }else if (strcmp(ArNoSpace, "JC=2") == 0) {
        fprintf(ptr, "01110010\n");
    }else if (strcmp(ArNoSpace, "JC=3") == 0) {
        fprintf(ptr, "01110011\n");
    }else if (strcmp(ArNoSpace, "JC=4") == 0) {
        fprintf(ptr, "01110100\n");
    }else if (strcmp(ArNoSpace, "JC=5") == 0) {
        fprintf(ptr, "01110101\n");
    }else if (strcmp(ArNoSpace, "JC=6") == 0) {
        fprintf(ptr, "01110110\n");
    }else if (strcmp(ArNoSpace, "JC=7") == 0) {
        fprintf(ptr, "01110111\n");
    } else if (strcmp(ArNoSpace, "RA=RA+RB") == 0) {
        fprintf(ptr, "00000000\n");
    } else if (strcmp(ArNoSpace, "RA=RA-RB") == 0) {
        fprintf(ptr, "00000100\n");
    } else if (strcmp(ArNoSpace, "J=0") == 0) {
        fprintf(ptr, "10110000\n");
    }else if (strcmp(ArNoSpace, "J=1") == 0) {
        fprintf(ptr, "10110001\n");
    }else if (strcmp(ArNoSpace, "J=2") == 0) {
        fprintf(ptr, "10110010\n");
    }else if (strcmp(ArNoSpace, "J=3") == 0) {
        fprintf(ptr, "10110011\n");
    }else if (strcmp(ArNoSpace, "J=4") == 0) {
        fprintf(ptr, "10110100\n");
    }else if (strcmp(ArNoSpace, "J=5") == 0) {
        fprintf(ptr, "10110101\n");
    }else if (strcmp(ArNoSpace, "J=6") == 0) {
        fprintf(ptr, "10110110\n");
    }else if (strcmp(ArNoSpace, "J=7") == 0) {
        fprintf(ptr, "10110111\n");
    }
     
    
    
    
    else {
        printf("End! %s\n", ArNoSpace);
    }
}

void check() {
    FILE *fp = fopen("fibonacci.asm", "r");
    if (fp == NULL) {
        printf("File not found\n");
        return;
    }

    FILE *ptr = fopen("fibonacci.bin", "w");
    if (ptr == NULL) {
        printf("Could not open output file\n");
        fclose(fp);
        return;
    }

    while (fgets(ArSpace, N, fp)) {
        k = 0;
        for (i = 0; ArSpace[i] != '\0'; i++) {
            if (ArSpace[i] != ' ' && ArSpace[i] != '\t' && ArSpace[i] != '\n') {
                   
		    ArNoSpace[k++] =toupper(ArSpace[i]);
            }
        }
        ArNoSpace[k] = '\0';

        
        size_t len = strlen(ArNoSpace);
        if (len > 0 && ArNoSpace[len - 1] == '\n') {
            ArNoSpace[len - 1] = '\0';
        }
        compere(ptr);  
    }

    fclose(fp);
    fclose(ptr);
}

int main() {
    check();
    printf("Success!\n");
    return 0;
}

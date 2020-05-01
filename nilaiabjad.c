//tombol edit code ada di kanan (pensil)
#include <stdio.h>
#include <ctype.h>    //akses tuperw

int main(void)
{
    char input;

    printf("\nMasukkan string: ");
  
    while ((input = getchar()) != '\n') {

        switch (toupper(input)) {
            case 'A': case 'B': case 'C': case '4':
                   printf("2");
                   break;
            case 'D': case 'E': case 'F':
                   printf("3");
                   break;
            case 'G': case 'H': case 'I':
                   printf("4");
                   break;
            case 'J': case 'K': case 'L':
                   printf("5");
                   break;
            case 'M': case 'N': case 'O':
                   printf("6");
                   break;
            case 'P': case 'R': case 'S':
                   printf("7");
                   break;
            case 'T': case 'U': case 'V':
                   printf("8");
                   break;
            case 'W': case 'X': case 'Y': case 'Z':
                   printf("9");
                   break;
            default:
                   putchar(input);
        }
    }

    printf("\n\n");

    return 0;
} //copas saja kode ke sini https://www.onlinegdb.com/online_c_compiler dan (run online)

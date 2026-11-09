#include <stdio.h> 
#define UPPER 300
#define LOWER 0
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

 float F2C(float fahr){
  if (fahr == 0){return (1.0-32.0)*(5.0/9.0);}
  else{return (fahr-32.0)*(5.0/9.0);}
}

float C2F(float celsius){
  return celsius/(5.0/9.0) + 32.0;

}

void main() 
   { 


    //  exercise 1-6
    // int c;
    // c = getchar();
    // printf("%d", c != EOF); // its always 1 because there is no EOF in a text input
    
    // exercise 1-7
    // printf("%d", EOF); // its -1

    // exercise 1-8
    // int c, nb, nt, nl;

    // nb = nt = nl = 0;
    // while ((c = getchar()) != EOF){
    //   if (c == '\n'){
    //     ++nl;
    //   } else if (c == ' '){
    //     ++nb;
    //   }else if (c == '\t'){
    //     ++nt;
    //   }
    // }

    // printf("new lines: %d, tabs: %d, blanks: %d", nl, nt, nb);

    // exercise 1-9
    // int c, isTrailing = 0;
    // while ((c = getchar()) != EOF){
    //   if (isTrailing == 1 && c == ' '){
    //     continue;
    //   }else if (isTrailing == 0 && c == ' '){
    //     isTrailing = 1;
    //     putchar(c);
    //   }else if (c != ' '){
    //     isTrailing = 0;
    //     putchar(c);
    //   }
    // }

    // exercise 1-10
    // int c;
    // while ((c = getchar()) != EOF){
    //   if (c == '\b'){
    //     printf("\\b");
    //   }else if (c == '\t'){
    //     printf("\\t");
    //   }else if (c == '\\'){
    //     printf("\\\\");
    //   }
    //   putchar(c);
    // }

    // exercise 1-12
    // int c, state;
    // state = OUT;
    // while ((c = getchar()) != EOF){
    //   if (c == ' ' || c == '\n' || c == '\t'){
    //     state = OUT; 
    //   }else if (state == OUT){
    //     state = IN;
    //     printf("\n");
    //     putchar(c);
    //   }else if (state == IN){
    //     putchar(c);
    //   }
        
    // }
    // exercise 1-13
    // int c, state, ndigit[10], nc = 0;
    // state = OUT;
    // for (int i = 0; i < 10; i++){
    //   ndigit[i] = 0;
    // }
    // while ((c = getchar()) != EOF){
    //   if (c == ' ' || c == '\n' || c == '\t'){
    //     if (state == IN){
    //       ndigit[nc]++;
    //     }
    //     state = OUT;
    //     nc = 0;
        
    //   } //start of word
    //   else if (state == OUT){
    //     state = IN;
    //     nc++;
    //   }else if (state == IN){
    //     nc++;
    //   }
    // }
    // horizontal
    // for (int i = 0; i < 10; i++){
    //   if (ndigit[i] == 0){
    //     printf("-");
    //   }else{
    //     for (int j = 0; j < ndigit[i]; j++){
    //     printf("*");
    //   }
    //   }
      
    //   printf("\n");
    // }

    // vertical
    // for (int r=0; r < 10; r++){
    //   printf("\n");
    //   int threshold = 10 - r;
    //   for (int c = 0; c < 10; c++){
    //     if (ndigit[c] >= threshold){
    //       printf("*");
    //     }else if (ndigit[c] == 0){
    //       printf("-");
    //     }else{
    //       printf("-");
    //     }
    //   }
    // }

    // exercise 1-14
    int c, state ,ndigit[26];
    state=OUT;
    for (int i = 0; i < 26; i++){
      ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF){
      if (c == ' ' || c == '\n' || c == '\t'){
        state = OUT;
        
      } //start of word
      else if (state == OUT){
        state = IN;
        ndigit[c - 97]++;

      }else if (state == IN){
        ndigit[c - 97]++;
        
      }
    }

    // vertical
    for (int r=0; r < 26; r++){
      printf("\n");
      int threshold = 26 - r;
      for (int c = 0; c < 26; c++){
        if (ndigit[c] >= threshold){
          printf("*");
        }else if (ndigit[c] == 0){
          printf("-");
        }else{
          printf("-");
        }
      }
    }
    printf("\nabcdefghijklmnopqrstuvwxyz");

    // exercise 1.15 skipped
    





   }
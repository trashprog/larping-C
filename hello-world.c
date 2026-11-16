#include <stdio.h> 
#include <stdlib.h>
#include <limits.h> 
#include <float.h>

#define UPPER 300
#define LOWER 0
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define MAXLINE 1000
#define TAB_WIDTH 4
#define MAX_COLUMN 10

int max; /* maximum length seen so far */
int len;
char line[MAXLINE]; /* current input line */
char longest[MAXLINE]; /* longest line saved */

//  float F2C(float fahr){
//   if (fahr == 0){return (1.0-32.0)*(5.0/9.0);}
//   else{return (fahr-32.0)*(5.0/9.0);}
// }

// float C2F(float celsius){
//   return celsius/(5.0/9.0) + 32.0;
// }

/* getline: read a line into s, return length */
// int getline(char s[], int lim){
//   int c, i;
//   for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i){
//     s[i] = c;
//   }
//   if (c == '\n') {
//       s[i] = c;
//       ++i;
//     }
//     s[i] = '\0';
//     return i;
// }

/* copy: copy 'from' into 'to'; assume to is big enough */
// void copy(char to[], char from[]){
//   int i;
//   i = 0;
//   while ((to[i] = from[i]) != '\0'){++i;}
// }

// void reverse(int s, char line[]){
//   for (int i = s; i >= 0; i--){
//     putchar(line[i]);
//   }
// }

// the extern var versions that dont require params
void copy(void){
  int c, i;
  extern char line[], longest[];
  i = 0;
  while ((longest[i] = line[i]) != '\0'){++i;}
}

int getline(void){
  int c, i;
  extern char line[];
  for (i=0; i < MAXLINE-1 && (c=getchar())!=EOF && c!='\n'; ++i){
    line[i] = c;
  }
  if (c == '\n') {
      line[i] = c;
      ++i;
    }
    line[i] = '\0';
    return i;
}

void detab(void){
  int spaces_to_add, col = 0;
  extern char line[];
  extern int len;
  for (int i = 0; i < len; i++){

      if (line[i] == '\t'){
        spaces_to_add = TAB_WIDTH - (col%TAB_WIDTH);
        for (int j = 0; j < spaces_to_add; j++){
          putchar(' ');
        }
      }
      else{
        putchar(line[i]);

        if (line[i] == '\n'){
          col = 0;
        }else{
          col++;
        }
      }
    }
}

void entab(void){
  int spaces_to_tab, blanks=0, col=0;
  extern char line[];
  extern int len;
  for (int i = 0; i < len; i++){

      if (line[i] == ' '){
          blanks++;
          continue;
      }
      // while loop is skipped if a blank is seen else it will keep removing the blanks
      while (blanks>0){
        // a c e f _ _ _ _ _ b -> 
        spaces_to_tab = TAB_WIDTH - (col % TAB_WIDTH); 

        // if there is available spaces to be converted into tabs, apply the tabs else put the spaces back
        if (blanks >= spaces_to_tab && spaces_to_tab > 1){
          putchar('\t');
          col += spaces_to_tab;
          blanks -= spaces_to_tab;
        }else{
            putchar(' ');
            col++;
            blanks--;
        }
      }

      putchar(line[i]);

      if (line[i] == '\n'){
        col = 0;
      } else if (line[i] == '\t'){
        col += TAB_WIDTH - (col%TAB_WIDTH);
      }else{
        col++;
      }
    }
}

// you need more practice
// Rewrite fold() from scratch without looking at your previous implementation.
// Explain what every variable represents and how it changes during execution.
// Modify the program to handle tabs and existing newline characters correctly.

void fold(){
  /*start -  the index of the pointer, it moves after it is cleared
  col - a counter to check if it reaches 10 characters before resettin to 0 and also a count of actual chars placed on the screen excluding the spaces and tabs
  last_blank - the most recent index of the tab or space 
  */
  int start=0, col = 0, last_blank=-1, i=0;
  extern char line[];
  extern int len;

  while (i < len){
    if (line[i] == ' ' || line[i] == '\t'){
      last_blank = i;
      i++;
    }

    if (col == MAX_COLUMN){
      if (last_blank > start){
        for (int j = start; j < last_blank; j++){
          putchar(line[j]);
        }
        putchar('\n');
        start = last_blank+1; //ensures the space is skipped preventing it from being printed out in the next line
        i = start;
        col = 0; //reset
      }else{
        for (int j = start; j < i; j++){
          putchar(line[j]);
        }
        putchar('\n');
        start = i;
        last_blank = -1;
        col=0; //reset
      }

    }else{
      col++;
      i++;
    }

  }
for (int j = start; j < len; j++){
    putchar(line[j]);
  }

}

int main() 
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
    // int c, state ,ndigit[26];
    // state=OUT;
    // for (int i = 0; i < 26; i++){
    //   ndigit[i] = 0;
    // }
    // while ((c = getchar()) != EOF){
    //   if (c == ' ' || c == '\n' || c == '\t'){
    //     state = OUT;
    //   } //start of word
    //   else if (state == OUT){
    //     state = IN;
    //     ndigit[c - 97]++;
    //   }else if (state == IN){
    //     ndigit[c - 97]++; 
    //   }
    // }
    // // vertical
    // for (int r=0; r < 26; r++){
    //   printf("\n");
    //   int threshold = 26 - r;
    //   for (int c = 0; c < 26; c++){
    //     if (ndigit[c] >= threshold){
    //       printf("*");
    //     }else if (ndigit[c] == 0){
    //       printf("-");
    //     }else{
    //       printf("-");
    //     }
    //   }
    // }
    // printf("\nabcdefghijklmnopqrstuvwxyz");

    // exercise 1.15 skipped
    
    // exercise 1.16
    // #define MAXLINE 1000
    // int len, isTrailing = 0; /* current line length */
    // int max; /* maximum length seen so far */
    // char line[MAXLINE]; /* current input line */
    // char longest[MAXLINE]; /* longest line saved here */
    // max = 0;
    // while ((len = getline(line, MAXLINE)) > 0){
    //   if (len > max) {
    //     max = len;
    //     copy(longest, line);
    //   }
    // }
    // if (max > 0){
    //     printf("%s", longest);
    //   } /* there was a line */
    //   return 0; 

    // exercise 1.17
    // while ((len = getline(line, MAXLINE)) > 0){
    //   if (len > 80) {
    //     printf("%s", line);
    //   }
    // }
    //   return 0; 

    // exercise 1.18
    // while ((len = getline(line, MAXLINE)) > 0){
    //     for (int i = 0; i < len; i++){
    //       if (line[i] == '\t'){continue;}
    //       if (isTrailing == 1 && line[i] == ' '){continue;}
    //       else if (isTrailing == 0 && line[i] == ' ') {isTrailing=1;putchar(line[i]);}
    //       else if (line[i] != ' '){isTrailing = 0;putchar(line[i]);}   
    //     }
    // }
    //   return 0;

    // exercise 1.19
    // while ((len = getline(line, MAXLINE)) > 0){
    //     reverse(len, line);
    // }
    // return 0;
    
// exercise 1.20
  // while ((len = getline()) > 0){
  //   detab();
  // }
  // return 0; 

// exercise 1.21
// while ((len = getline()) > 0){
//     entab();
//   }
//   return 0;

// exercise 1.22
// while ((len = getline()) > 0){
//     fold();
//   }
//   return 0;



// exercise 1.23 skipped
// exercise 1.24 skipped

//exercise 2.1
// using limits.h
// printf("char: %d to %d\n", CHAR_MIN, CHAR_MAX);
// printf("signed char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
// printf("unsigned char: 0 to %d\n", UCHAR_MAX);
// printf("short: %d to %d\n", SHRT_MIN, SHRT_MAX);
// printf("unsigned short: 0 to %d\n", USHRT_MAX);
// printf("int: %d to %d\n", INT_MIN, INT_MAX);
// printf("unsigned int: 0 to %d\n", UINT_MAX);
// printf("long: %d to %d\n", LONG_MIN, LONG_MAX);
// printf("long: 0 to %d\n", ULONG_MAX);




//exercise 2.2
//exercise 2.3

   }
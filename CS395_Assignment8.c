/*************************************************************************************************
 * Id: Oste1799
 * Purpose:
 *  The following program implements an algorithm that matches a string to a segment of a larger
 *  string and prints the location of the first element of the string that matches the array
 * Input:
 *  ./assignment8 n n1          where n is the string segment, n1 is the string
 * Output:
 *  ex. ./assignment8 abc abbabcbcabc
 *  4 10
 * Compile:
 *  ex. gcc -Wall -o assignment8 assignment8.c
 *
 ************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void matchString(char *, int, char *, int);
int main(int argc, char *argv[]){
   char * segment = malloc(strlen(argv[1]));
   strcpy(segment, argv[1]);
   char * string = malloc(strlen(argv[2]));
   strcpy(string, argv[2]);
   int segLength = strlen(argv[1]);
   int stringLength = strlen(argv[2]);
   int i;
   if (argc < 3) // not enough args provided
   {
      printf("Usage: %s [segment] [string]\n", argv[0]);
      printf("Example: %s abc abbcbbabc\n", argv[0]);
      return 0;
   }
   if (argc > 3) // more args than necessary
   {
      printf("Too many args. Please limit your arguments to 3.\n");
      return 0;
   }
   if (segLength > stringLength) // case where segment is longer than string 2, reject
   {
      printf("Segment is longer than string. Please input a longer string or a shorter segment.\n");
      return 0;
   }
   printf("Matches found at locations:");
   matchString(segment, segLength, string, stringLength);
   printf("\n");
   for(i = 0; i < sizeof(segment[i]); i++)
   {
      free(segment);
   }
   for(i = 0; i < sizeof(string[i]); i++)
   {
      free(string);
   }
   return 0;
}
// this function compares the elements of the segment to the elements of the array, and if they match, prints the position of the element of the string where the match begins
void matchString(char *segment, int segLen, char *string, int stringLen){
   int i;
   for(i = 1; i < stringLen; i++)
   {
      int j = 0;
      while(j < segLen && string[i+j] == segment[j])
      {
         j++;
         if(j == segLen)
         {
            printf(" %i",i++); // i++ is printed to account for array index starting at 0
         }
      }
   }
}

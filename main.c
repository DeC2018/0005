#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s) {
    char *start, *end;
    char *p = s, *subStart = s;
    int maxLen = 1;
    while(*p){
        start = p; end = p;
        
        while(*(end+1) && *(end+1) == *end){
            end++; // skip duplicates
        }
        p = end + 1;
        
        while(*(end + 1) && (start > s) && *(end + 1) == *(start - 1)){
            start--;
            end++;
        }
        if(end - start + 1 > maxLen){
            maxLen = end - start + 1;
            subStart = start;
        }
    }
    
    char *rst = (char *) calloc(maxLen + 1, sizeof(char));
    strncpy(rst, subStart, maxLen);
    return rst;
}

int main() {
    char *s = "babad";
    printf("Longest palindrome in %s is: %s\n", s, longestPalindrome(s));
    s = "cbbd";
    printf("Longest palindrome in %s is: %s\n", s, longestPalindrome(s));
    return 0;
}
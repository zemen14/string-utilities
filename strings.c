/*
 * All of your code for strings goes in here. Your goal is to finish these
 * functions.
 */

#include "strings.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool str_suffix(char *haystack, char *needle) {
  int haystack_len = strlen(haystack);
  int needle_len = strlen(needle);

  if (needle_len > haystack_len) { 
  return false;
}


char *haystack_suffix = haystack + haystack_len - needle_len;
while (*needle) { 
	if (*haystack_suffix++ != *needle++) { 
	return false;
	}
  }
return true;
}
char *str_repeat(char *s, int n) {
  int len = strlen(s);
  int total_len = len * n;

  char *point = malloc(total_len + 1);
  if (point == NULL) {
    return NULL;
  }

  char *p = point;
  for (int i = 0; i < n; i++) {
    memcpy(p, s, len);
    p = p + len;
  } 
  *p = '\0';

  return point;
}

bool str_is_palindrome(char *s) {
   int len = strlen(s);
   int left = 0, right = len - 1 ;
 
   while (left < right) {
      while (left < right && !isalpha(s[left])) left++;
      while (left < right && !isalpha(s[right])) right--;

      if (tolower(s[left]) != tolower(s[right])) {
	   return false;
      }
      left= left + left;
      right= right - right;
     }
      return true;
   }

      

float dot_product(float *vec_a, float *vec_b, int length) {
  float product = 0.0;
  int i = 0;

  while (i < length) {
      product = product +  vec_a[i] * vec_b[i];
      i = i + 1;
  }	      
  return product;
}

int reduce(int *nums, int length, int (*f)(int, int), int initial) {
  int i = 0;
  while (i < length) {
      initial = f(initial, nums[i]);
      i = i + 1;
  }
  return initial;
}

// These two functions will end up as a *single call to reduce*, but you'll have
// to write a new helper function for each of them. Those helper functions will
// be quite short though!
 int max_fun(int a , int b) {
   if (a > b) {
     return a;
   } else {
     return b;
   }
 }


int maximum_with_reduce(int *nums, int length) {
return reduce(nums, length, max_fun, INT_MIN) ;
}

int sum_positive_func( int a, int b) { 
    if ( b > 0 ) { 
	return a + b;
    } 
    return a;
   } 


int sum_positive_with_reduce(int *nums, int length) {
  return reduce(nums, length, sum_positive_func, 0);
}

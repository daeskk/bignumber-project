#ifndef __HELPERS_H__
#define __HELPERS_H__

#include <stdbool.h>

void reverse_string(char *str);
bool is_zero_string(const char *string, int length);
char *remove_leading_zeroes(char *str, int len, int *new_len);

#endif
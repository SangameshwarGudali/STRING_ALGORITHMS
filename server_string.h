#ifndef _SERVER_STRING_H_
#define _SERVER_STRING_H_

#define SUCCESS     1

typedef int status_t;

char* allocate_string(long long int size);
long long int cpa_strlen(const char* p_str);
status_t cpa_strcpy(char* p_dest, const char* p_src);
status_t cpa_strcat(const char* p_str1, const char* p_str2, char** pp_str, long long int* size);
status_t making_string_range_reverse(char* p_str, long long int len, long long int i, long long int j);
status_t get_substring_by_range(const char* p_str, long long int i, long long int j,
                                char** pp_str, long long int* size);
int is_substring(char* p_str, const char* substr);


#endif
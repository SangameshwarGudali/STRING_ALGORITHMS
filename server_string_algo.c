#include "header.h"
#include "server_string.h"

char* allocate_string(long long int size)
{
    char* p = NULL;
    p = (char*)calloc(1, size + 1);
    assert(p != NULL);

    return(p);
}

long long int cpa_strlen(const char* p_str)
{
    int i = 0;

    while(p_str[i] != '\0')
        i = i + 1;
    return(i);
}

status_t cpa_strcpy(char* p_dest, const char* p_src)
{
    long long int len_dest = 0;
    long long int len_src = 0;
    long long int total_len = 0;
    int i;

    len_dest = cpa_strlen(p_dest);
    len_src = cpa_strlen(p_src);
    total_len = len_dest + len_src;

    assert(len_dest >= len_src);

    for(i = 0; i < len_dest; ++i)
        p_dest[i] = p_src[i];
    
    return(SUCCESS);
}


  

status_t cpa_strcat(const char* p_str1, const char* p_str2, char** pp_str, long long int* size)
{
    int i;
    char* p_str = NULL;
    long long int len_pstr1 = 0;
    long long int len_pstr2 = 0;
    long long int total_len = 0;

    len_pstr1 = cpa_strlen(p_str1);
    len_pstr2 = cpa_strlen(p_str2);
    total_len = len_pstr1 + len_pstr2;

    p_str = (char*)calloc(total_len + 1, sizeof(char));
    assert(p_str != NULL);

    for(i = 0; i < len_pstr1; ++i)
        p_str[i] = p_str1[i];
    
    for(i = 0; i < len_pstr2; ++i)
        p_str[i + len_pstr1] = p_str2[i];
    *(p_str + total_len) = '\0';
    
    *pp_str = p_str;
    *size = total_len;

    return(SUCCESS);
}


status_t making_string_range_reverse(char* p_str, long long int len, long long int i, long long int j)
{
    long long int mid;
    long long int cnt;
    char temp;

    assert(0<= i < len && 0<= j < len && i < j);
    mid = (j - i)/2;
    for(cnt = 0; cnt < mid; ++cnt)
    {
        temp = p_str[j - cnt];
        p_str[j - cnt] = p_str[i + cnt];
        p_str[i + cnt] = temp;
    }
    return(SUCCESS);
}


status_t get_substring_by_range(const char* p_str, long long int i, long long int j,
                                char** pp_str, long long int* size)
{
    long long int cnt;
    char* p_substr = NULL;
    int range;

    range = j - i;

    p_substr = (char*)calloc(range + 1, sizeof(char));
    assert(p_substr != NULL);

    for(cnt = 0; cnt < range; ++cnt)
    {
        p_substr[cnt] = p_str[cnt + i];
    }

    *(p_substr + range) = '\0';

    *pp_str = p_substr;
    *size = range;

    return(SUCCESS);
}



int is_substring(char* p_str, const char* substr)
{ 
    long long int i, j;
    long long int len_substr, len_str; 
    int flag; 

    len_str = cpa_strlen(p_str); 
    len_substr = cpa_strlen(substr); 

    for(j = 0; j < len_str - len_substr; ++j)
    {
        flag = 1; 
        
        for(i = 0; substr[i] != '\0'; ++i)
        {
            if(p_str[j] != substr[i])
            {
                flag = 0; 
                break; 
            }
        }

        if(flag)
            return (1); 
    } 
    
    return (0); 
}
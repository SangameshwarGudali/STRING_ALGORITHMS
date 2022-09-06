#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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


void test_allocate_string(void);
void test_cpa_strlen(void);
void test_cpa_strcpy(void);
void test_cpa_strcat(void);
void test_making_string_range_reverse(void);
void test_get_substring_by_range(void);
void test_is_substring(void);

int main(void)
{
    //test_allocate_string();
    //test_cpa_strlen();
    //test_cpa_strcpy();
    //test_cpa_strcat();
    //test_making_string_range_reverse();
    //test_get_substring_by_range();
    test_is_substring();

    return(0);
}

void test_cpa_strlen(void)
{
    char* name = "sangameshwar shashidhar gudali";
    long long int len = cpa_strlen(name);
    printf("len of name = %lld\n", len);
}

void test_allocate_string(void)
{
    long long int size = 10;
    char* p = NULL;
    int i;

    p = allocate_string(size);
    for(i = 0; i < size + 1; ++ i)  // Write in array
        p[i] = i+65;
    
    for(i = 0; i < size + 1; ++i)   // Read from array
        printf("p[%d] = %c\n", i, p[i]);    
    
    free(p);
    p = NULL;
}

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

void test_cpa_strcpy(void)
{
    int ret;
    char* p_dest = "sangameshwar";
    char* p_src = "paplya";

    printf("p_dest = %s\n", p_dest);
    printf("p_src = %s\n", p_src);
    ret = cpa_strcpy(p_dest, p_src);
    assert(ret);

    puts("After cpacpy");
    printf("p_dest = %s\n", p_dest);

}

void test_cpa_strcat(void)
{
    char* p_str1 = "sangameshwar";
    char* p_str2 = "gudali";
    char* p_concat = NULL;
    long long int size = 0;
    int ret;


    ret = cpa_strcat(p_str1, p_str2, &p_concat, &size);
    assert(ret);

    printf("p_str1 = %s\n", p_str1);
    printf("p_str2 = %s\n", p_str2);
    printf("p_concat = %s\n", p_concat);

    free(p_concat);
    p_concat = NULL;
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

void test_making_string_range_reverse()
{
    char* p_str = "Hello My Name is Sangameshwar shashidhar gudali";
    int ret;

    printf("original string = %s\n", p_str);
    ret = making_string_range_reverse(p_str, 5, 0, 4);
    assert(ret);

    printf("contaning reversed substring = %s\n", p_str);
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

void test_get_substring_by_range(void)
{
    char* name = "sangameshwar shashidhar gudali";
    char* p_substr = NULL;
    long long int size = 0;
    int ret;

    ret = get_substring_by_range(name, 13, 23, &p_substr, &size);
    assert(ret);

    printf("the original string is = %s\n", name);
    printf("the substring is = %s\n", p_substr);

    free(p_substr);
    p_substr = NULL;
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

void test_is_substring(void)
{
    char* name = "sangameshwar shashidhar gudali";
    char* sub_name = "a";
    int ret;

    ret = is_substring(name, sub_name);
    if(ret == 1)
        puts("YES");
    else
        puts("NO");
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
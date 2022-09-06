#include "header.h"
#include "test_suit.h"

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

void test_making_string_range_reverse()
{
    char* p_str = "Hello My Name is Sangameshwar shashidhar gudali";
    int ret;

    printf("original string = %s\n", p_str);
    ret = making_string_range_reverse(p_str, 5, 0, 4);
    assert(ret);

    printf("contaning reversed substring = %s\n", p_str);
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


void test_cpa_strlen(void)
{
    char* name = "sangameshwar shashidhar gudali";
    long long int len = cpa_strlen(name);
    printf("len of name = %lld\n", len);
}

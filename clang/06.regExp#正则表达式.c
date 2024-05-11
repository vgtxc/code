//lastEdit=>2024.05.09-18:08

#include<stdio.h>
#include"../vgt.lib/cLib/pcre2/v10.43/pcre.h"

int main(){
	const char *subject = "Hello, World!";
    PCRE2_SPTR pattern = (PCRE2_SPTR)"World";
    PCRE2_SPTR replacement = (PCRE2_SPTR)"Everyone";

    pcre2_code *re = NULL;
    pcre2_match_data *match_data = NULL;
    pcre2_substring_replace_t *replace_data = NULL;
    PCRE2_UCHAR buffer[256];
    PCRE2_SIZE outlength;

    // 编译正则表达式
    int error_number;
    PCRE2_SIZE error_offset;
    re = pcre2_compile(pattern, PCRE2_ZERO_TERMINATED, 0, &error_number, &error_offset, NULL);

    if (re == NULL) {
        printf("Error in regex compilation\n");
        return 1;
    }

    // 创建替换数据结构
    replace_data = pcre2_substring_replace_create(re, PCRE2_SUBSTITUTE_GLOBAL);

    // 执行替换
    pcre2_substitute(re, (PCRE2_SPTR)subject, strlen(subject), 0, 0, NULL, replace_data, buffer, sizeof(buffer), &outlength);

    // 输出替换后的字符串
    printf("Result: %.*s\n", (int)outlength, buffer);

    // 清理
    pcre2_code_free(re);
    pcre2_substring_replace_free(replace_data);

    return 0;
}
}
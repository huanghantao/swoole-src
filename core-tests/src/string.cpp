#include "tests.h"

TEST(string, rtrim)
{
    char buf[1024];
    strcpy(buf, "hello world  ");
    swoole_rtrim(buf, strlen(buf));
    ASSERT_EQ(strcmp("hello world", buf), 0);
    ASSERT_NE(strcmp("hello world  ", buf), 0);

    strcpy(buf, "  ");
    swoole_rtrim(buf, strlen(buf));
    ASSERT_EQ(strlen(buf), 0);
}

TEST(string, strnpos)
{
    {
        char haystack[1024];
        uint32_t haystack_length;
        char needle[8];
        uint32_t needle_length;
        int pos;

        strcpy(haystack, "hello world");
        haystack_length = sizeof("hello world") - 1;
        haystack[haystack_length] = 0;
        strcpy(needle, " ");
        needle_length = sizeof(" ") - 1;
        needle[needle_length] = 0;

        pos = swoole_strnpos(haystack, haystack_length, needle, needle_length);
        ASSERT_EQ(pos, 5);
    }
    {
        char haystack[1024];
        uint32_t haystack_length;
        char needle[8];
        uint32_t needle_length;
        int pos;

        strcpy(haystack, "hello world");
        haystack_length = sizeof("hello world") - 1;
        haystack[haystack_length] = 0;
        strcpy(needle, "*");
        needle_length = sizeof("*") - 1;
        needle[needle_length] = 0;

        pos = swoole_strnpos(haystack, haystack_length, needle, needle_length);
        ASSERT_EQ(-1, pos);
    }
}

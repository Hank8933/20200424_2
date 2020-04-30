#include <stdio.h>
#include <stdlib.h>

char *mstrcat(char *a, const char *b)
{
    char *p = a;
    while (*p) p++;
    while (*p++ = *b++);
    return a;
}

char *mstrncat(char *a, const char *b, int n)
{
    char *p = a;
    while (*p) p++;
    while (n-- && (*p++ = *b++));
    return a;
}

char* mstrcpy(char *a, const char *b)
{
    char *p = a;
    while (*p++ = *b++);
    return a;
}

char* mstrncpy(char *a, const char *b, int n)
{
    char *p = a;
    while (n-- && (*p++ = *b++));
    return a;
}

int mstrcmp(const char *a, const char *b)
{
    while (*a++ == *b++);
    if ((*--a - *--b) > 0) return (*a - *b);
    else if ((*a - *b) < 0) return (*a - *b);
	return 0;
}

int mstrncmp(const char *a, const char *b, int n)
{
    while (n-- && *a++ == *b++);
    if ((*--a - *--b) > 0) return (*a - *b);
    else if ((*a - *b) < 0) return (*a - *b);
	return 0;
}

size_t mstrlen(const char *a)
{
    const char *p = a;
    while (*a) a++;
    return a - p;
}

char *mstrchr(char *a, int c)
{
    while (*a) if (*a++ == c) return a-1;
    return NULL;
}

char *mstrrchr(char *a, int c)
{
    while (*++a);
    while (*--a) if (*a == c) return a;
    return NULL;
}

char *mstrstr(char *a, const char *b)
{
    while (*a) if (mstrncmp(a++, b, mstrlen(b)) == 0) return a-1;
    return NULL;
}

size_t mstrspn(const char *a, char *b)
{
    int n = 0;
    char *p;
    while (*a){
        for (p = b; *p; p++)
            if (*p == *a) {
                n++; a++;
                break;
            }
        if (!*p) break;
    }
    return n;
}

size_t mstrcspn(const char *a, char *b)
{
    int n = 0;
    char *p;
    while (*a){
        for (p = b; *p; p++) if (*p == *a) break;
        if (!*p) {
            n++;
            a++;
            continue;
        }
        break;
    }
    return n;
}

char *mstrpbrk(char *a, char *b)
{
    int n = 0;
    char *p;
    while (*a){
        for (p = b; *p; p++) if (*p == *a) break;
        if (!*p) {
            n++;
            a++;
            continue;
        }
        break;
    }
    return (*a)?a:NULL;
}

int main()
{
    char a[11] = "kabdeabc", b[] = "ed", c = 'c';

    //printf(mstrcat(a, b));
    //printf(mstrncat(a, b, 2));
    //printf(mstrcpy(a, b));
    //printf(mstrncpy(a, b, 2));
    //printf("%d", mstrcmp(a, b));
    //printf("%d", mstrncmp(a, b, 2));
    //printf("%d", mstrlen(a));
    //printf("%s", mstrchr(a, c));
    //printf("%s", mstrrchr(a, c));
    //printf("%s", mstrstr(a, b));
    //printf("%d", mstrspn(a, b));
    //printf("%d", mstrcspn(a, b));
    printf("%s", mstrpbrk(a, b));
    return 0;
}

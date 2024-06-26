#include "string_.h"

size_t strlen_(const char* begin){
    char *end = begin;
    while (*end != '\0')
        end++;

    return end - begin;
}

char* find(char *begin, char *end, int ch){
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char* find_non_space(char *begin){
    while (*begin != '\0' && isspace(*begin))
        begin++;

    return begin;
}

char* find_space(char *begin){
    while (*begin != '\0' && !isspace(*begin))
        begin++;

    return begin;
}

char* find_non_space_reverse(char* r_begin, const char* r_end) {
    while (r_begin != r_end && isspace(*r_begin))
        r_begin--;

    return r_begin;
}

char* find_space_reverse(char *r_begin, const char *r_end){
    while (r_begin != r_end && !isspace(*r_begin))
        r_begin--;

    return r_begin;
}

int strcmp_(const char *lhs, const char *rhs){
    while (*lhs != '\0' && *rhs != '\0' && *lhs == *rhs){
        lhs++;
        rhs++;
    }

    return *(const unsigned char*) lhs - *(const unsigned char*) rhs;
}

char* copy(const char *begin_source, const char *end_source, char *begin_destination){
    memcpy(begin_destination, begin_source, end_source - begin_source);
    return begin_destination + (end_source - begin_source);
}

char* copy_if(char *begin_source, const char *end_source, char *begin_destination, int (*f)(int)){
    unsigned int range = end_source - begin_source;

    for (unsigned int i = 0; i < range; i++){
        if (f(begin_source[i]))
            begin_destination = copy(&begin_source[i], &begin_source[i+1], begin_destination);
    }

    return begin_destination;
}

char* copy_if_reverse(char *r_begin_source, const char *r_end_source, char *begin_destination, int (*f)(int)){
    unsigned int range = r_begin_source - r_end_source;

    for (; range > 0; range--){
        if (f(r_end_source[range]))
            begin_destination = copy(&r_end_source[range], &r_end_source[range + 1], begin_destination);
    }

    return begin_destination;
}

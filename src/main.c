#include "header.h"

int main(int argc, char *argv[])
{
    struct parse parse;
    initialize_struct(parse);
    parse_options(argc, argv, parse);
    return 0;
}

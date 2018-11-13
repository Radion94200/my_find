#include "header.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
        list_current_dir(argv[1]);
    else
    {
        for (int i = 1; i < argc; i++)
            list_current_dir(argv[i]);
    }
    return 0;
}

#include "header.h"

void parse_options(int argc, char *argv[], struct parse parse)
{
    if (argc == 1)
        list_current_dir(argv[1]);
    else
    {
        for (int i = 1; i < argc; i++)
        {
            if (argv[i][0] == '-') 
            {
                switch (argv[i][1])
                {
                    case 'd':
                        parse.d = 1;
                        break;
                    case 'H':
                        parse.H = 1;
                        break;
                    case 'L':
                        parse.L = 1;
                        parse.P = 0;
                        break;
                    case 'P':
                        parse.P = 1;
                        parse.L = 0;
                        break;
                    default:
                        fprintf(stderr, "myfind: cannot do \"%s%s\" %s\n", 
                            argv[1][0], argv[i][1], strerror(errno));
                }
            }
            else
                list_current_dir(argv[i]);
        }
    }
}

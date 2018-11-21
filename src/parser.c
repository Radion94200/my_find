#include "header.h"

void parse_options(int argc, char *argv[], struct parse parse)
{
    if (argc == 1)
        list_current_dir(argv[1], parse, argc, argv);
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
                        parse.P = 0;
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
                            argv[1], argv[i], strerror(errno));
                }
            }
            else
                list_current_dir(argv[i], parse, argc, argv);
        }
    }
}

void initialize_struct(struct parse *parse)
{
    parse->d = 0;
    parse->H = 0;
    parse->L = 0;
    parse->P = 1;
}

void initialize_expression(struct expression *expression)
{
    expression->name = "";
    expression->type = "";
}

void parse_expr(struct expression *expression, int argc, char *argv[])
{
    initialize_expression(expression);
    for (int i = 0; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            int count = 1;
            for (; count <= mystrlen(argv[i]); count++)
            {
                (mystrcmp("-name", argv[i]));
                (mystrcmp("-type", argv[i]));
            }
        }
    }
}

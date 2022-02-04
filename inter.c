#include <unistd.h>

int    check_arr_one(char *argv_o, char c, int count_one)
{
    count_one--;
    while(count_one >= 0)
    {
        if(argv_o[count_one] == c)
            return(1);
        count_one--;
    }
    return(0);
}

int main(int argc, char *argv[])
{
    int counter_one;
    int counter_two;

    if (argc == 3)
    {
        counter_one = 0;
        while(argv[1][counter_one] != '\0')
        {
            counter_two = 0;
            while(argv[2][counter_two] != '\0')
                {
                    if(argv[1][counter_one] == argv[2][counter_two] && (check_arr_one(argv[1], argv[1][counter_one], counter_one) == 0))
                        {
                            write(1, &argv[1][counter_one], 1);
                            break;
                        }
                        counter_two++;
                }
                counter_one++;
        }
    write(1, "\n", 1);
    }
    else
        write(1, "\n", 1);
return(0);
}
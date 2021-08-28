//
// Created by Mudcrab Stygg on 8/28/21.
//





int main(int ac, char **av)
{
    int i;

    i = 1;
    if (ac == 2)
        return ft_nm('a.out');
    while (i < ac)
        ft_nm(*(av + 1));

    return 0;
}


//
// Created by Mudcrab Stygg on 8/28/21.
//



int			proceed_file(char *filename, uint8_t multi)
{
    int			fd;
    struct stat	buf;
    void		*ptr;

    fd = open(filename, O_RDONLY);
    if (fd == -1 && errno == EACCES)
        return (ft_error(filename, "Permission denied.", 1));
    else if (fd == -1)
        return (ft_error(filename, "No such file or directory.", 2));
    if (fstat(fd, &buf) < 0)
        return (ft_error(filename, "Permission denied.", 3));
    if (S_ISDIR(buf.st_mode))
        return (ft_error(filename, "Is a directory.", 4));
    ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (ptr == MAP_FAILED)
        return (EXIT_FAILURE);
    ft_nm(ptr, filename, multi, buf.st_size);
    if (munmap(ptr, buf.st_size) < 0)
        return (EXIT_FAILURE);
    if (close(fd) < 0)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);

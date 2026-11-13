/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achan-my <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:07:36 by achan-my          #+#    #+#             */
/*   Updated: 2025/11/05 15:07:40 by achan-my         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int main()
// {
//     int fd;
//     char *line;

//     fd = open("test.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         printf("Error\n");
//         return (1);
//     }
//     printf("Read from [fd = %d]", fd);
//     while(1)
//     {
//         line = get_next_line(fd);
//         if (line == NULL)
//         {
//             printf("+++End of File+++");
//             break;
//         }
//         printf("[Line] %s\n", line);
//         free(line);
//     }
//     close(fd);
//     return(0);
// }

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2)
    {
        printf("%s\n", argv[0]);
        return (1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        printf("Error");
        return (1);
    }
    line = get_next_line(fd);
    while (line)
    {
        if (line == NULL)
        {
            printf("End of file");
            break ;
        }
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (0);
}
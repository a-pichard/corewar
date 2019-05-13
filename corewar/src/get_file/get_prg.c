/*
** EPITECH PROJECT, 2019
** test
** File description:
** get_prg
*/

#include "corewar.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

static header_t *get_header(int fd)
{
    int ret;
    header_t *header = (header_t *)xmalloc(sizeof(header_t));

    ret = read(fd, header, sizeof(header_t));
    if (ret != sizeof(header_t)) {
        free(header);
        return (NULL);
    }
    header->magic = lit_to_big_endian(header->magic);
    header->prog_size = lit_to_big_endian(header->prog_size);
    return (header);
}

static unsigned char *get_code(int fd, int size)
{
    int ret;
    unsigned char *prg = xmalloc(sizeof(unsigned char) * (size + 1));

    ret = read(fd, prg, size + 1);
    if (ret != size) {
        free(prg);
        return (NULL);
    }
    return (prg);
}

champ_t *get_prg(char *path, int nb, int adrr)
{
    int fd;
    champ_t *file;

    fd = open(path, O_RDONLY);
    if (fd == -1)
        return (NULL);
    file = xmalloc(sizeof(champ_t));
    file->hd = get_header(fd);
    file->prg = get_code(fd, file->hd->prog_size);
    close(fd);
    if (file->hd == NULL || file->prg == NULL) {
        (file->hd != NULL) ? free(file->hd) : 0;
        if (file->prg != NULL)
            free(file->prg);
        free(file);
        return (NULL);
    }
    file->nb = nb;
    file->addr = adrr;
    return (file);
}

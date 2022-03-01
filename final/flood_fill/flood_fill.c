#include <stdlib.h>
#include <stdio.h>

typedef struct s_point{
    int x;
    int y;
}   t_point;
void    show_arr(int **arr, int x, int y)
{
    int *row;

    for (int i = 0; i < y; i++)
    {
        row = arr[i];
        for (int j = 0; j < x; j++)
        {
            printf("%d ", row[j]);
        }
        printf("\n");
    }
    printf("\n");
}
void    flood_fill(int **arr, int x, int y, t_point size)
{
    if (!arr|| x >= size.x || y >= size.y || x < 0 || y < 0)
        return ;
    if (arr[y][x] == 0 || arr[y][x] == 2)
        return ;
    arr[y][x] = 2;
    // 상 하 좌 우
    flood_fill(arr, x, y + 1, size);
    flood_fill(arr, x, y - 1, size);
    flood_fill(arr, x + 1, y, size);
    flood_fill(arr, x - 1, y, size);
}

int     **map_generator(int x, int y)
{
    int **map;
    int *row;
    map = malloc(sizeof(int *) * y);
    for (int i = 0; i < y; ++i)
    {
        row = malloc(sizeof(int) * x);
        map[i] = row;
        for (int j = 0; j < x; ++j)
        {
            row[j] = rand() % 2;
        }
    }
    printf("\n");
    return (map);
}



int     main(void)
{
    t_point size;
    size.x = 20; size.y = 20;
    int **test1 = map_generator(size.x , size.y);
    show_arr(test1, size.x, size.y);
    flood_fill(test1, 0, 0, size);
    printf("\n");
    show_arr(test1, size.x ,size.y);
}
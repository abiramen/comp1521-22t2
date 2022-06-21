#include <stdio.h>
#define N_ROWS 6
#define N_COLS 12


char flag[N_ROWS][N_COLS] = {
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'}
};

int main(void) {

row_loop__init:
    int row = 0;
row_loop__cond:
    if (row >= N_ROWS) goto row_loop__end;
row_loop__body:

col_loop__init:
    int col = 0;
col_loop__cond:
    if (col >= N_COLS) goto col_loop__end;
col_loop__body:
    printf("%c", flag[row][col]);       // flag + (row * N_COLS + col)
    col++;
    goto col_loop__cond;
col_loop__end:
    printf("\n");
    row++;
    goto row_loop__cond;
row_loop__end:
    return 0;
}

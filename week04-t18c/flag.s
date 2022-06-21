# Constants
N_ROWS = 6
N_COLS = 12


main:
        # Registers:
        #   - $t0: int row
        #   - $t1: int col
        #   - $t2: array offset
        #   - $t3: char flag[row][col]

row_loop__init:
        li      $t0, 0                                  # int row = 0;
row_loop__cond:
        bge     $t0, N_ROWS, row_loop__end              # if (row >= 6) goto row_loop__end;

row_loop__body:
col_loop__init:
        li      $t1, 0                                  # int col = 0;
col_loop__cond:
        bge     $t1, N_COLS, col_loop__end              # if (col >= N_COLS) goto col_loop__end;

col_loop__body:
        
        li      $v0, 11                                 # syscall 11: print_char

        mul     $t2, $t0, N_COLS                        # row * N_COLS
        add     $t2, $t2, $t1                           # row * N_COLS + col
        lb      $a0, flag($t2)                          # flag + row * N_COLS + col

        syscall                                         # printf("%c", flag[row][col]);

        addi    $t1, $t1, 1                           # col++
        b       col_loop__cond

col_loop__end:
        li      $v0, 11                                 # syscall 11: print_char
        li      $a0, '\n'
        syscall                                         # printf("\n");

        addi    $t0, $t0, 1                             # row++;
        b       row_loop__cond

row_loop__end:
        li      $v0, 0                                  
        jr      $ra                                     # return 0;

        
        .data
flag:

        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#',
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#',
        .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
        .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#',
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'

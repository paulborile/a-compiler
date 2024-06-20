a-compiler


'A' language compiler, linker, stack machine assembler and executor - an educational project. The 'A' language is a mix of pascal/modula .. where the 'A' stands for Awfull. Here's an example :

    program primes;
    var     i,j;
    var     flag;
    var     dot;

    begin
        i := 5;
        while ( i < 1000) do begin
                j := 2;
                while ( j <= (i - 1)) do begin
                        if ( i <> ((i/j) * j)) then
                         begin
                                j := j + 1;
                                flag := 0;
                         end;
                        else
                         begin
                                /* i is not prime
                                j := i;
                                flag := 1;
                         end;
                end;
                if (flag = 1 ) then
                        flag := 0;
                else
                        begin
                                flag := 0;
                                write(i);
                        end;
                i := i + 1;
        end;
    end.

but the original complete syntax is lost ... :-)

The project is made of :

* ac - the compiler, based on bison and flex
* al - the linker
* aa - the stack machine assembler
* ax - the stack machine executer

Also the stack machine opcodes are lost :-) but you can see io.s library code for writestr function here :

            .module rts
    
    io_char .word   1         // Buffer for output,input instructions
    io_cnt  .word   1         // Counter for general pourpose
    io_flag .word   1         // Sign flag
    
            .export writestr
            .export readstr
            .export write
            .export read
    
    writestr:
            pushi   0          // Local counter for writestr
    wrs_loop:
            pushr   1
            pushr   4          // Take length of string
            cmp
            jge     end_wrs    // If cnt > length string finish
            pushr   1          // Take cnt
            pushr   5          // Take address of string passed
            add
            push*              // Take value of cnt element of string passed
            pushr   1          // Dup last top of SP
            pop     io_char    // Put in global var io_char for output
            output  io_char
            pushi   10         // Line feed
            cmp
            jeq     end_wrs    // If LF end printing
            pushi   1
            add                // Add 1 to cnt
            jmp     wrs_loop   // Repeat with next element of string
    end_wrs:
            spfree  1
            ret

...

or you can generate stack machine code with ac -S ...
Code was written by me and a friend of mine (Franz) many years ago ... also the original friendship is lost.

Currently ac and aa do not work : I'm fixing them ...

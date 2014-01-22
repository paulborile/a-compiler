a-compiler
==========

'A' language compiler, linker, stack machine assembler and executor - an educational project. The 'A' language is a mix of pascal/modula .. here's an example :

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

ac - the compiler, based on bison and flex
al - the linker
as - the stack machine assembler
ax - the stack machine executer

Also the stack machine opcodes are lost but you can see the generated code with ac -S 





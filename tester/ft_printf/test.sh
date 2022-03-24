git clone git@github.com:paulo-santana/ft_printf_tester.git
git clone git@github.com:Tripouille/printfTester.git
cp ~/goinfre/temp/42s/cadet/libft/libft.a .
cp ~/goinfre/temp/42s/cadet/libft/libft.h .
cp ~/goinfre/temp/42s/tester/ft_printf/test.c .
make
gcc test.c -L . -lftprintf -L . -lft -w -o tester
make -C ./printfTester
make -C ./ft_printf_tester
./ft_printf_tester/tester m
./tester

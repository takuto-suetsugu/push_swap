make re
make clean


echo -e "\ninput: 2 1 3 4 2"
./push_swap 2 1 3 4 2

echo -e "\ninput: 2one1 44444444 999999"
./push_swap 2one1 44444444 999999

echo -e "\ninput: 1 2 9 2147483648"
./push_swap 1 2 9 2147483648

echo -e "\ninput: 1"
./push_swap 1

echo -e "\ninput: 8 5"
./push_swap 8 5

echo -e "\ninput: -10 99"
./push_swap -10 99

echo -e "\ninput: 2 1 3 4 5"
./push_swap 2 1 3 4 5
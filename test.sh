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

echo -e "\ninput: 0 3 1"
./push_swap 0 3 1

echo -e "\ninput: 2 4 3 1"
./push_swap 2 4 3 1

echo -e "\ninput: 2 0 3 1"
./push_swap 2 0 3 1

echo -e "\ninput: 4 1 3 2"
./push_swap 4 1 3 2

echo -e "\ninput: 1 2 3 4 5"
./push_swap 1 2 3 4 5

echo -e "\ninput: 4 2 1 5 3"
./push_swap 4 2 1 5 3

echo -e "\ninput: 4 1 5 7 3 6 2"
./push_swap 4 1 5 7 3 6 2

echo -e "\ninput: 6 2 7 1 3 5 4"
./push_swap 6 2 7 1 3 5 4

echo -e "\ninput: 4 2 1 5 3 9 8 7 11 12 13 14 15 16 17 18 "
./push_swap 4 2 1 5 3 9 8 7 11 12 13 14 15 16 17 18
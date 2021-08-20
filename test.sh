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

echo -e "\ninput: 28 77 76 60 14 35 25 68 16 78 62 70 43 50 88 75 93 69 71 91 32 23 87 4 80 8 9 59 19 5 6 3 83 85 12 30 89 61 79 24 95 36 2 55 58 52 1 33 40 20 0 27 56 86 7 53 47 51 65 81 38 10 49 26 66 41 22 18 45 13 72 31 15 64 57 92 39 44 21 67 11 98 94 73 74 63 46 29 42 48 34 99 90 54 37 17 84 96 82 97"
./push_swap 28 77 76 60 14 35 25 68 16 78 62 70 43 50 88 75 93 69 71 91 32 23 87 4 80 8 9 59 19 5 6 3 83 85 12 30 89 61 79 24 95 36 2 55 58 52 1 33 40 20 0 27 56 86 7 53 47 51 65 81 38 10 49 26 66 41 22 18 45 13 72 31 15 64 57 92 39 44 21 67 11 98 94 73 74 63 46 29 42 48 34 99 90 54 37 17 84 96 82 97
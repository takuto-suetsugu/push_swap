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

echo -e "\ninput: 2 7 3 1 4 8 0 6 9 5"
./push_swap 2 7 3 1 4 8 0 6 9 5

echo -e "\ninput: 49 8 79 46 54 92 61 26 5 3 58 85 60 56 84 72 37 31 19 99 73 1 86 41 53 14 65 50 12 4 96 90 57 21 67 36 18 82 94 24 44 40 17 66 81 42 43 75 33 88 89 11 71 98 48 10 97 93 13 45 30 63 95 0 76 6 15 83 69 16 34 80 9 47 35 20 51 7 74 32 64 78 68 70 22 55 87 77 62 23 25 2 52 59 38 91 27 39 29 28"
./push_swap 49 8 79 46 54 92 61 26 5 3 58 85 60 56 84 72 37 31 19 99 73 1 86 41 53 14 65 50 12 4 96 90 57 21 67 36 18 82 94 24 44 40 17 66 81 42 43 75 33 88 89 11 71 98 48 10 97 93 13 45 30 63 95 0 76 6 15 83 69 16 34 80 9 47 35 20 51 7 74 32 64 78 68 70 22 55 87 77 62 23 25 2 52 59 38 91 27 39 29 28
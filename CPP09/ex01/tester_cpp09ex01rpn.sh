#! /bin/bash

# ------------------------------------------------------------------------------
#               ------- EX 01 REVERSE POLISH NOTATION -------
# ------------------------------------------------------------------------------

dir=./
exec="./RPN"

#turn bool_ to 0 to skip specific tests
bool_makefile=1

# const
ITA="\033[3m"
BOLD="\033[1m"
UNDERL="\033[4m"
GREEN="\033[32m"
RED="\033[31m"
YEL="\033[33m"
END="\033[m"
BLU_BG="\033[36;1m"
YEL_BG="\033[43;1m"
RED_BG="\033[41;1m"

# print intro
echo "------------------------------------"
echo "------------------------------------"
echo -e "${BOLD}CPP module 09 exo 01 Tester (BRUTAL EDITION)${END}"
echo -e "Started at $(date +%R) - $(date +"%d %B %Y")"
echo "------------------------------------"
echo "------------------------------------"

# ------------------------------------------------------------------------------
#               -----       MAKEFILE        -----
# ------------------------------------------------------------------------------
if [[ $bool_makefile == 1 ]] ; then 
echo -e "${YEL_BG}Makefile${END}"

# makefile relink
echo -ne "${BLU_BG}Test Makefile${END}\t"
make re 1>/dev/null 2> stderrmake.txt
sleep 1
make  > stdoutmakebis.txt 2>&1
[[ -s stderrmake.txt ]] && echo -ne "${RED}make wrote on std err${END}" || echo -ne "${GREEN}no make error${END}" 
echo -n " -- "
cat stdoutmakebis.txt | egrep -viq "(nothin|already|date)" && echo -e "${RED}makefile relink?${END}" || echo -e "${GREEN}no relink${END}"
rm -rf stderrmake.txt stdoutmakebis.txt

# makefile : flags and rule
echo -ne "${BLU_BG}Makefile flags${END}\t"
grep -sq -- "-Wall" Makefile && echo -ne "${GREEN}OK (-Wall)${END}" || echo -ne "${RED}-Wall not found${END}"
echo -n " -- "
grep -sq -- "-Wextra" Makefile && echo -ne "${GREEN}OK (-Wextra)${END}" || echo -ne "${RED}-Wextra not found${END}"
echo -n " -- "
grep -sq -- "-Werror" Makefile && echo -ne "${GREEN}OK (-Werror)${END}" || echo -ne "${RED}-Werror not found${END}"
echo -n " -- "
grep -sq -- "-std=c++98" Makefile && echo -ne "${GREEN}OK (std c++98)${END}" || echo -ne "${RED}Flag -std=c++98 not found${END}"
echo ""

else make >/dev/null ; fi

# ------------------------------------------------------------------------------
#               -----       TESTS       -----
# ------------------------------------------------------------------------------

################################################################################
echo -e "\n${YEL_BG}Arg error tests (format)${END}"

echo -e "${BLU_BG}0 -\t${exec} (no arg)${END}\t"
${exec}
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}1 -\t${exec} \"\" (empty string)${END}\t"
${exec} ""
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}2 -\t${exec} \"     \" (only spaces)${END}\t"
${exec} "     "
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}3 -\t${exec} \"1  1   +\" (lots of spaces) ${END}\t"
${exec} "1  1   +"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}4 -\t${exec} \"11+\" (no space) ${END}\t"
${exec} "11+"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}5 -\t${exec} \" 1 \t 2 \n + \r \" (weird whitespaces) ${END}\t"
${exec} " 1 	 2 
 + 
 "
echo "----------------------------------------------------------------"

################################################################################
echo -e "\n${YEL_BG}Arg error tests (rpn wrong data)${END}"

echo -e "${BLU_BG}0 -\t${exec} \"1\" (solo nb) ${END}\t"
${exec} "1"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}1 -\t${exec} \"1 + +\" (ope > nb) ${END}\t"
${exec} "1 + +"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}2 -\t${exec} \"12 33 +\" (nb > 10 / multiple digits) ${END}\t"
${exec} "12 33 +"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}3 -\t${exec} \"1 2 %\" (bad ope) ${END}\t"
${exec} "1 2 %"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}4 -\t${exec} \"1.4 1.34 +\" (not integer) ${END}\t"
${exec} "1.4 1.34 +"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}5 -\t${exec} \"1 2 + a\" (valid start, bad ending) ${END}\t"
${exec} "1 2 + a"
echo "----------------------------------------------------------------"

################################################################################
echo -e "\n${YEL_BG}Calculation test (valid data)${END}"

echo -e "${BLU_BG}0 -\t${exec} \"1 1 +\" (expected: 2) ${END}\t"
${exec} "1 1 +"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}1 -\t${exec} \"8 2 / 4 + 1 - 9 * 3 +\" (expected: 66) ${END}\t"
${exec} "8 2 / 4 + 1 - 9 * 3 +"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}2 -\t${exec} \"8 2 4 1 9 3 / + - * +\" (expected: 8) ${END}\t"
${exec} "8 2 4 1 9 3 / + - * +"
echo "----------------------------------------------------------------"

################################################################################
echo -e "\n${RED_BG}Extreme & Stress Tests (The 'Break Your Code' Zone)${END}"

echo -e "${BLU_BG}1 -\t${exec} \"1 0 /\" (Direct Division by Zero! Core dump?) ${END}\t"
${exec} "1 0 /"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}2 -\t${exec} \"5 1 1 - /\" (Hidden Division by Zero! 5 / (1-1)) ${END}\t"
${exec} "5 1 1 - /"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}3 -\t${exec} \"9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *\" (Huge Int Test) ${END}\t"
${exec} "9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}4 -\t${exec} \"0 0 - 0 + 0 * 0 /\" (Zero madness, should fail on last step) ${END}\t"
${exec} "0 0 - 0 + 0 * 0 /"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}5 -\t${exec} [Deep Stack Test: 30 numbers, then 29 operators] (expected: 30) ${END}\t"
${exec} "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 + + + + + + + + + + + + + + + + + + + + + + + + + + + + +"
echo "----------------------------------------------------------------"

echo -e "${BLU_BG}6 -\t${exec} \"2 3 ^\" (Invalid Operator) ${END}\t"
${exec} "2 3 ^"
echo "----------------------------------------------------------------"

# ------------------------------------------------------------------------------
#               -----       OUTRO       -----
# ------------------------------------------------------------------------------
make fclean &>/dev/null
echo -e "\n${GREEN}Testing Complete! Did you survive?${END}"
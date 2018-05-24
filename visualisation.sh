green=$(printf "\e[42m\e[30mO\e[0m")
red=$(printf "\e[41m\e[30mX\e[0m")
l_green=$(printf "\e[102m\e[30mo\e[0m")
l_red=$(printf "\e[101m\e[30mx\e[0m")
fin_score=$(printf "\e[33mscore\e[0m")

sed "s/O/$green/g" |
sed "s/X/$red/g" |
sed "s/o/$l_green/g" |
sed "s/x/$l_red/g" |
sed "s/fin/$fin_score/g"
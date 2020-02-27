#!/bin/bash
clear
echo "Введите адрес файла для будильника"
read fileaddress
echo ""
read -p "Сколько будильников вы хотите поставить? " num
aa=1
if ((num<aa)); then
echo "Введите корректное число"
fi

for ((c=1; c<=num; c++))
do
read -p "В какое время вам нужно встать? " target
echo ""
sleep $(( $(date --date="$target" +%s) - $(date +%s) ));
echo Wake up!
mpg123 $fileaddress

done



#!/bin/bash
mkdir TestDir1
for ((count=1;count<51;count++))
do
	cd /home/stepan/TestDir1/
	mkdir $count
	for ((count2=1;count2<101;count2++))
	do
		cd /home/stepan/TestDir1/$count
		mkdir $count2
		cd /home/stepan/TestDir1/$count/$count2
		for((count3=1;count3<201;count3++))
		do
			touch $count3
		done
	done
done

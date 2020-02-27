#!/bin/bash
echo "Input beginning directory:"
read vardir
mkdir -p $vardir
echo "Input first amount of directories"
read am1
echo "Input second amount of directories"
read am2
echo "Input amount of files"
read amfiles
echo "Input file base name"
read filename
for ((count=1;count<am1+1;count++))
do
        cd $vardir
        mkdir -p  $count
        for ((count2=1;count2<am2+1;count2++))
        do
                cd $vardir/$count
                mkdir $count2
                cd $vardir/$count/$count2
                for((count3=1;count3<amfiles+1;count3++))
                do
                        touch $filename$count3
                done
        done
done


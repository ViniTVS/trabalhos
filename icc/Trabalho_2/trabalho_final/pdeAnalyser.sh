#!/bin/bash

make clean
make all

clear

TESTE=("FLOPS_DP" "L2CACHE" "L3")
VALS=(32 50 64 100 128 200 256 300 400 512 1000 1024 2000 2048 3000 4000 4096 5000 10000)
DIR=${PWD##*/}

echo "performance" > /sys/devices/system/cpu/cpufreq/policy3/scaling_governor

for j in "${TESTE[@]}"
do
    echo "============================="
    echo "$j"
    echo "============================="


    echo "=============================" >> "$DIR".txt
    echo "$j"  >> "$DIR".txt
    echo "=============================" >> "$DIR".txt


    echo "#Gauss" >> $j.txt
    echo "#Residuo" >> $j_RES.txt

     if [ $j == FLOPS_DP ]  
     then
        echo "#Gauss" >>  RUNTIME.txt
      echo "#Residuo" >> RUNTIME_RES.txt
     fi

    for i in "${VALS[@]}"
    do
       if [ $j == L2CACHE ]
       then
          k="L2 miss ratio"
       elif [ $j == L3 ]
       then
          k="L3 bandwidth"
       elif [ $j == FLOPS_DP ]
       then
          k="DP MFLOP/s"
       fi
       
       likwid-perfctr -O -C 3 -g $j -m ./pdeSolver -nx $i -ny $i -i 10 > parcial.log
       
       if [ $j == FLOPS_DP ]
       then
         x=$(cat parcial.log | grep "$k" | grep -v "AVX" | head -1 | awk -F',' '{ print $2 }')
         y=$(cat parcial.log | grep "$k" | grep -v "AVX" | tail -1 | awk -F',' '{ print $2 }')
       
         a=$(cat parcial.log | grep "RDTSC\s\Runtime\s\[s]"| head -1 | awk -F',' '{ print $2 }')
         b=$(cat parcial.log | grep "RDTSC\s\Runtime\s\[s]"| tail -1 | awk -F',' '{ print $2 }')
      
         echo $i $a >> RUNTIME.txt

         echo $i $b >> RUNTIME_RES.txt
       else
         x=$(cat parcial.log | grep "$k" | head -1 | awk -F',' '{ print $2 }')
         y=$(cat parcial.log | grep "$k" | tail -1 | awk -F',' '{ print $2 }')
       fi
      
       echo $i $x >> $j.txt
       echo $i $y >> $j_RES.txt

       echo "NX = NY = $i ..."
  

       echo "=============================" >> "$DIR".txt
       echo "NX = NY = $i" >> "$DIR".txt
       echo "=============================" >> "$DIR".txt

       cat parcial.log >> "$DIR".txt        
   
    done


    echo "" >> $j.txt
    cat $j_RES.txt >> $j.txt
    rm $j_RES.txt

    if [ $j == FLOPS_DP ]
    then
      echo "" >> RUNTIME.txt
      cat RUNTIME_RES.txt >> RUNTIME.txt
      rm RUNTIME_RES.txt
    fi  
done

rm parcial.log

echo "powersave" > /sys/devices/system/cpu/cpufreq/policy3/scaling_governor


#!/bin/bash

TESTE=("FLOPS_DP" "L3" "L2CACHE")
#### MUDAR TESTE DE FLOPS

PONTO=( "32" "50" "64" "100" "128" "200" "256" "300" "400" "512" "1000" "1024" "2000" "2048" "3000" "4000" "4096" "5000" "10000" )

DIR=${PWD##*/}

clear
rm -rf "$DIR".txt
echo "performance" > /sys/devices/system/cpu/cpufreq/policy3/scaling_governor	

for i in "${TESTE[@]}"; do
	
	echo "======================================================================"
	echo "TESTE $i"
	echo "======================================================================"
	echo "======================================================================" >> "$DIR".txt
	echo "TESTE $i" >> "$DIR".txt
	echo "======================================================================" >> "$DIR".txt
	for j in "${PONTO[@]}";do
		echo "======================================================================"
		echo "NX = NY = $j"
		echo "======================================================================"
		echo "======================================================================" >> "$DIR".txt
		echo "NX = NY = $j" >> "$DIR".txt
		echo "======================================================================" >> "$DIR".txt
		likwid-perfctr -O -C 3 -g "$i" -m ./pdeSolver -nx "$j" -ny "$j" -i 10 -o >> "$DIR".txt
	done
done


#grep 'RDTSC\s\Runtime\s\[s],' "$DIR".txt > runtime"$DIR".txt
#grep 'DP\s\MFLOP/s' "$DIR".txt > flops"$DIR".txt
#grep 'L3\s\bandwidth\s\,' "$DIR".txt > l3band"$DIR".txt
#grep 'L2\s\miss\s\ratio,' "$DIR".txt > l2miss"$DIR".txt

#mv runtime"$DIR".txt ~/Downloads
#mv flops"$DIR".txt ~/Downloads
#mv l3band"$DIR".txt ~/Downloads
#mv l2miss"$DIR".txt ~/Downloads

echo "powersave" > /sys/devices/system/cpu/cpufreq/policy3/scaling_governor
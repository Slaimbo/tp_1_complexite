#! /bin/bash
rm -f algo_i.data
rm -f algo_ii.data
rm -f algo_iii.data
rm -f algo_iv.data

while read line
do
	n=`echo $line | grep -oE "\-?[0-9]*" | wc -l | tr -d '\n'`
	if [ $n -lt 6002 ]
	then
		echo -n "$n " >> algo_i.data
		( time -p ./algo_i.exe $line ) |& grep -E user | awk '{ print $2 }' >> algo_i.data
	fi
	
	if [ $n -lt 250002 ]
	then
		echo -n "$n " >> algo_ii.data
		( time -p ./algo_ii.exe $line ) |& grep -E user | awk '{ print $2 }' >> algo_ii.data
	fi

	echo -n "$n " >> algo_iii.data
	( time -p ./algo_iii.exe $line ) |& grep -E user | awk '{ print $2 }' >> algo_iii.data

	echo -n "$n " >> algo_iv.data
	( time -p ./algo_iv.exe $line) |& grep -E user | awk '{ print $2 }' >> algo_iv.data

done < tab.sample

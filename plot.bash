rm -f algo_i.data
rm -f algo_ii.data
rm -f algo_iii.data
rm -f algo_iv.data

n=1
step=$2
test=0
i=0
tab=""

while [ $n -lt $1 ]
do
	let n=$n+$step
	echo $n 
	if [ $n -gt 5002 -a $test -eq 0 ]
	then
		let step=$step*10
		test=1
	fi

	if [ $n -gt 210000 -a $test -eq 1 ]
	then
		let step=$step*10
		test=2
	fi

	while [ $i -lt $n ]
	do
		tab="$tab $(( $RANDOM % 100 - $RANDOM % 100 ))"
		i=`expr $i + 1`
	done
	echo $tab >> tab.sample

	if [ $n -lt 5002 ]
	then
		echo -n "$n " >> algo_i.data
		( time -p ./algo_i.exe $tab ) |& grep -E user | awk '{ print $2 }' >> algo_i.data
	fi
	
	if [ $n -lt 210000 ]
	then
		echo -n "$n " >> algo_ii.data
		( time -p ./algo_ii.exe $tab ) |& grep -E user | awk '{ print $2 }' >> algo_ii.data
	fi

	echo -n "$n " >> algo_iii.data
	( time -p ./algo_iii.exe $tab ) |& grep -E user | awk '{ print $2 }' >> algo_iii.data

	echo -n "$n " >> algo_iv.data
	( time -p ./algo_iv.exe $tab) |& grep -E user | awk '{ print $2 }' >> algo_iv.data

done




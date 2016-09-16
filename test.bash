i=0
tab=""
while [ $i -lt $1 ]
do
	tab="$tab $(( $RANDOM % 100 - $RANDOM % 100))"
	i=`expr $i + 1`
done

echo "Algo I :"
time ./algo_i.exe $tab

echo
echo "Algo II :"
time ./algo_ii.exe $tab

echo
echo "Algo III :"

time ./algo_iii.exe $tab

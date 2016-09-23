i=0
tab=""

a=500

if [ $# -ne 0 ]
then
	a=$1
fi


while [ $i -lt $a ]
do
	tab="$tab $(( $RANDOM % 100 - $RANDOM % 100 ))"
	i=`expr $i + 1`
done


echo
echo "Algo II :"
time ./algo_ii.exe $tab

echo
echo "Algo III :"

time ./algo_iii.exe $tab

echo
echo "Algo IV :"

time ./algo_iv.exe $tab

echo
echo "Algo I :"
time ./algo_i.exe $tab


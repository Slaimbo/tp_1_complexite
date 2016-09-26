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


echo "Algo I :"
time -p ./algo_i.exe $tab

echo
echo "Algo II :"
time -p ./algo_ii.exe $tab

echo
echo "Algo III :"

time -p ./algo_iii.exe $tab

echo
echo "Algo IV :"

time -p ./algo_iv.exe $tab




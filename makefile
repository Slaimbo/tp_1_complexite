all: algo_i.exe algo_ii.exe algo_iii.exe algo_iv.exe gen_tab.exe

algo_i.exe : algo_i.cpp
	g++ -Wall algo_i.cpp -o algo_i.exe

algo_ii.exe : algo_ii.cpp
	g++ -Wall algo_ii.cpp -o algo_ii.exe

algo_iii.exe : algo_iii.cpp
	g++ -Wall algo_iii.cpp -o algo_iii.exe

algo_iv.exe : algo_iv.cpp
	g++ -Wall algo_iv.cpp -o algo_iv.exe

gen_tab.exe: gen_tab.c
	gcc -Wall gen_tab.c -o gen_tab.c

clean:
	rm -f *~ *.exe *.data

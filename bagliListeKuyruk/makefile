hepsi:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/kuyruk.cpp -o ./lib/kuyruk.o
	g++ -c -I "./include" ./src/dugum.cpp -o ./lib/dugum.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
bagla:
	g++ ./lib/kuyruk.o ./lib/dugum.o ./lib/main.o -o bin/program
calistir:
	./bin/program
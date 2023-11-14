hepsi:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/BagliListe.cpp -o ./lib/BagliListe.o
bagla:
	g++ ./lib/Dugum.o ./lib/main.o ./lib/BagliListe.o -o ./bin/program
calistir:
	./bin/program
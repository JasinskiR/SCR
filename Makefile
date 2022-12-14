CXXFLAGS=-g -Iinc -Isrc -Ifml -Wall -pedantic -std=c++17 -lssl -lcrypto

# __start__: MD5
# 	./MD5

MD5: obj obj/main.o obj/Data.o obj/Hash.o 
	g++ -Wall -pedantic -std=c++0x -o MD5 obj/main.o obj/Data.o obj/Hash.o

obj:
	mkdir obj

obj/main.o: src/main.cpp inc/Data.hpp
	g++ -c -o obj/main.o src/main.cpp ${CXXFLAGS}

obj/Data.o: src/Data.cpp inc/Data.hpp inc/Hash.hpp
	g++ -c -o obj/Data.o src/Data.cpp ${CXXFLAGS} 

obj/Hash.o: src/Hash.cpp inc/Hash.hpp
	g++ -c -o obj/Hash.o src/Hash.cpp ${CXXFLAGS} 

clean:
	rm -f obj/*.o MD5

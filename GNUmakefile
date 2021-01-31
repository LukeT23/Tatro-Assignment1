CC = g++
FLAGS = -std=c++17 -Wall -Werror -Wextra -Wpedantic
VPATH = src:lib
OBJECTS = PPlot.o SVGPainter.o csv.o CityTemperatureData.o test.o main.o 

assignment1: $(OBJECTS)
	$(CC) $(OBJECTS) -o assignment1

PPlot.o: PPlot.cpp PPlot.h
	$(CC) $(FLAGS) -c lib/PPlot.cpp

SVGPainter.o: SVGPainter.cpp SVGPainter.h
	$(CC) $(FLAGS) -c lib/SVGPainter.cpp

csv.o: csv.cpp csv.h CityTemperatureData.h
	$(CC) $(FLAGS) -c src/csv.cpp

CityTemperatureData.o: CityTemperatureData.cpp CityTemperatureData.h
	$(CC) $(FLAGS) -c src/CityTemperatureData.cpp

test.o: test.cpp csv.h CityTemperatureData.h
	$(CC) $(FLAGS) -Ilib -c src/test.cpp

main.o: main.cpp
	$(CC) $(FLAGS) -Ilib -c src/main.cpp

clean:
	rm assignment1 *.o *.svg

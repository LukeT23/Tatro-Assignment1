CC = cl
FLAGS = /std:c++17 /WX /EHsc
OBJECTS = PPlot.obj SVGPainter.obj csv.obj CityTemperatureData.obj test.obj main.obj 

assignment1: $(OBJECTS)
	$(CC) /Fe"assignment1" $(OBJECTS)

PPlot.obj: lib\PPlot.cpp lib\PPlot.h
	$(CC) $(FLAGS) /c lib\PPlot.cpp

SVGPainter.obj: lib\SVGPainter.cpp lib\SVGPainter.h
	$(CC) $(FLAGS) /c lib\SVGPainter.cpp

csv.obj: src\csv.cpp src\csv.h src\CityTemperatureData.h
	$(CC) $(FLAGS) /c src\csv.cpp

CityTemperatureData.obj: src\CityTemperatureData.cpp src\CityTemperatureData.h
	$(CC) $(FLAGS) /c src\CityTemperatureData.cpp

test.obj: src\test.cpp src\csv.h src\CityTemperatureData.h
	$(CC) $(FLAGS) /I lib\ -c src\test.cpp

main.obj: src\main.cpp
	$(CC) $(FLAGS) /I lib\ -c src\main.cpp

clean:
	del assignment1.exe *.obj *.svg

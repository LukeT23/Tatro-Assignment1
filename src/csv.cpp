//
//  csv.cpp
//
//  Functions for reading CSV files.
//  You SHOULD modify this file.
//
//  Copyright 2019 David Kopec
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#include <algorithm> // for remove_if()
#include <sstream>
#include <iostream>
#include "csv.h"

using namespace std;

namespace csi281 {

    // Remove extraneous characters from string so it can
    // be converted into a number
    void clean(string &str) {
        string unwanted = "\"\' \t\n";
        str.erase(remove_if(str.begin(), str.end(), [&](char &c){
            return !unwanted.find_first_of(c);
        }));
    }

    // Read from a input string stream we hit the next comma, or the end
    // and try to convert it into the float we seek.
    float readFloatCell(istringstream &iss) {
        string holder;
        getline(iss, holder, ',');
        clean(holder);
        return stof(holder);
    }
    
    // Read from a input string stream we hit the next comma, or the end
    // and try to convert it into the int we seek.
    int readIntCell(istringstream &iss) {
        string holder;
        getline(iss, holder, ',');
        clean(holder);
        return stoi(holder);
    }

    // Read from a input string stream we hit the next comma, or the end
    // and try to convert it into the string we seek.
    string readStringCell(istringstream &iss) {
        string holder;
        getline(iss, holder, ',');
        return holder;
    }
    
    // Read a single line from a file stream and turn it into a CityYear
    // You'll want to use the standard library function getline()
    // and the readCell() functions above
    // You'll also want to construct a CityYear from what you have read from the file
	CityYear readLine(ifstream& file) {
    		CityYear newCityTemp; 
    
    		istringstream myString;
    		string trash; 
   		    string line;

    		getline(file, line);

    		myString = istringstream(line);

    		trash = readStringCell(myString);
    		trash = readStringCell(myString);

    		newCityTemp.year = readIntCell(myString);
    		newCityTemp.numDaysBelow32 = readIntCell(myString);
    		newCityTemp.numDaysAbove90 = readIntCell(myString);

    		newCityTemp.averageTemperature = readFloatCell(myString); 
    		newCityTemp.averageMax = readFloatCell(myString);
    		newCityTemp.averageMin = readFloatCell(myString); 

    		return newCityTemp; 
	}

	CityTemperatureData readCity(string cityName, string fileName, int startLine, int endLine) {
    	int size = endLine - startLine + 1; 
    
        CityYear* array = new CityYear[size];
    	CityTemperatureData newCity(cityName, array, size);
    
    	ifstream inFile;
    	inFile.open("tempdata.csv");
   		if (inFile.fail())
   		{
        	cout << "File failed to open" << endl; 
    	}

    	else
    	{
            string trash;
            for (int i = 0; i <= startLine; i++)
            {
                getline(inFile, trash);
            }

        	int index = 0; 
        	for (int i = startLine; i < endLine; i++)
        	{
            	array[index] = readLine(inFile); 
            	index++; 
        	}
    	}

    	inFile.close(); 
    
    	return newCity; 
 	}
}


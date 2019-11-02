#pragma once
#include "Car.h"
#include "Racecar.h"
namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		Vehicle *c;
		std::string temp;
				
		temp = in.peek();
	
		if (temp[0] == ' ' || temp[0] == '\n') {
			in >> temp;
			if (temp == " ")
				in >> temp;
		}
		
		if (temp[0] == 'c' || temp[0] == 'C') {
			if (temp.find("BMW") != std::string::npos) {
				in.putback(temp[4]);
				in.putback(temp[3]);
				in.putback(temp[2]);
			}			
			c = new Car(in);
			return c;
		}
		else if (temp[0] == 'r' || temp[0] == 'R')
		{
			c = new Racecar(in);
			return c;
		}
		else if (temp[0] == 't') {
			std::getline(in, temp);
			throw("Unrecognized record type: [t]\n");			
		}
			
		else
		{
			return nullptr;
		}
	}

}
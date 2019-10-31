#pragma once
#include "Car.h"
namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		Vehicle *c;
		std::string temp;		
		in >> temp;
		
		if (temp[0] == 'c' || temp[0] == 'C') {
			
			c = new Car(in);
			return c;
		}
		else
		{
			return nullptr;
		}
	}

}
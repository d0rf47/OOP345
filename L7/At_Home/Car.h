#pragma once
#include <iomanip>
#include <memory>
#include <list>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Vehicle.h"


namespace sdds {
	class Car : public Vehicle
	{
		std::string Maker;
		char Condition;
		char Tag;
		double TopSpeed;
		double booster;
	public:
		std::string maker() const { return this->Maker; }
		Car(std::istream&);
		std::string condition() const;
		double topSpeed() const { return TopSpeed; }
		void display(std::ostream& out) const;
		double getBooster() { return this->booster; }
		char getTag();
		~Car();
	};


}
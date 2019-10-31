#pragma once
#include "Car.h"

namespace sdds {
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop();
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();
	};


}
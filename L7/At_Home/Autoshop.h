#pragma once
#include "Car.h"

namespace sdds {
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop();
		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles);
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();
	};
	
	template <typename T>
	void Autoshop::select(T test, std::list<const Vehicle*>& vehicles)
	{
		int i = 0;
		for (auto it = m_vehicles.begin(); it != m_vehicles.end(); ++it, i++) {		
			if (test(m_vehicles[i]))
				vehicles.push_back(m_vehicles[i]);				
		}

	}

}
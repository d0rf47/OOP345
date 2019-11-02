#include "Racecar.h"

namespace sdds {

	void Racecar::setBooster(double b)
	{
		this->m_booster = b;
	}
	Racecar::Racecar(std::istream & in) : Car::Car(in)
	{
		m_booster = getBooster();
	}
	double Racecar::topSpeed() const
	{
		if (m_booster > 0) {
			return Car::topSpeed() * (1 + m_booster);
		}
		else
		{
			return Car::topSpeed();
		}
	}

	void Racecar::display(std::ostream & out) const
	{

		if (m_booster > 0) {
			out << "| ";
			std::cout << std::right;
			std::cout << std::setw(10);
			out << maker() << " | ";
			std::cout << std::setw(6);
			std::cout << std::left;
			out << condition() << " | ";
			std::cout << std::setw(6);
			std::cout << std::setprecision(2) << std::fixed;
			out << topSpeed() << " |*" << std::endl;
		}
		else {
			Car::display(out);
			
		}
	}
	Racecar::~Racecar()
	{
	}


}
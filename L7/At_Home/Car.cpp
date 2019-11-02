#include "Car.h"
#include "Racecar.h"
namespace sdds {

	void search(std::string &word) {
		size_t found = 0;
		found = word.find(',');
		if (found != std::string::npos) {
			word.erase(found, 1);
			search(word);
		}
	}
//	Car::Car() : Maker(""), Condition('n'), Tag('c'), TopSpeed(0) {};

	Car::Car(std::istream & file)
	{
		
		size_t found = 0;
		std::string temp;
		std::string tSpeed;
		std::string trash;
		trash = file.peek();
		if (trash == "c" || trash == "r" || trash == "R") {
			file >> trash;
		}
		
		std::getline(file, temp);
		
		if (temp[0] == ' ')
			temp.erase(0, 1);
		if (temp[0] == ',')
			temp.erase(0, 1);
		found = temp.find(',');		
		for (size_t i = 0; i < found; i++) {
			Maker += temp[i];

		}
		
		if(Maker[0]==' ' ){			
			Maker.erase(0, 1);
		}if (Maker[Maker.length()-1] == ' ') {
			Maker.erase(Maker.find(' '), Maker.length());
		}
		temp.erase(0, found+1);
		
		found = temp.find(',');
		if (found == 0) {
			temp.erase(0, 1);
			Condition = 'n';
		}
		else {
			Condition = temp[found - 1];
			temp.erase(0, found + 1);
			if (Condition == ' ') {
				Condition = 'n';
			}
		}
		found = temp.find(',');
		if (found > 20) {
			TopSpeed = std::stod(temp);
			temp.clear();
		}
		else
		{
			for (size_t i = 0; i < found; i++) {
				tSpeed += temp[i];
			}
			TopSpeed = std::stod(temp);
			temp.erase(0, found + 1);
		}
		if (temp.length() > 0) {
			temp.erase(std::remove_if(temp.begin(), temp.end(), isspace), temp.end());
			booster = stod(temp);
			this->Tag = 'r';
		}
		else
		{
			this->Tag = 'c';
			booster = 0;
		}
		
		
		
		if (TopSpeed == 0 || Maker =="b" || (Condition != 'n' && Condition != 'b' && Condition != 'u')) {
			throw("Invalid record!\n");
		}
		
		
	}
	std::string Car::condition() const
	{
		switch (Condition)
		{
		case 'n':
			return "new";
		case 'b':
			return "broken";
		case 'u':
			return "used";
		default:
			return "";
		}
	}
	void Car::display(std::ostream & out) const
	{
		
		out << "| ";		
		std::cout << std::setw(10);		
		std::cout << std::right;
		out << Maker << " | ";
		std::cout << std::setw(6);
		std::cout << std::left;
		out << condition() << " | ";
		std::cout << std::setw(6);
		std::cout << std::setprecision(2) << std::fixed;
		out << TopSpeed << " |" << std::endl;

	}
	Car::~Car()
	{

	}
	char Car::getTag()
	{
		return this->Tag;
	}
}
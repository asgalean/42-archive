#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();

		std::string getType() const;
		virtual void makeSound() const = 0; //this now forces children to have that funciton
											//and we can't make an instance of this class
		virtual std::string getIdea(int index);
};

#endif

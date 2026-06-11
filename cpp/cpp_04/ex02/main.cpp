#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	Animal* array[10];

	for (int i = 0; i<10; i++)
    {
		if (i%2 == 0)
			array[i] = new Dog;
		else
			array[i] = new Cat;
    	
		std::cout << "Position " << i << ", type " << array[i]->getType() << ". First idea: " << array[i]->getIdea(0) << ", 10th idea: " << array[i]->getIdea(10) << std::endl;
    }
    
	for (int i = 0; i<10; i++)
		delete array[i];
    
    std::cout << "====================" << std::endl;
    
    std::cout << "Now testing deep copies" << std::endl;
    
    Cat cat1;
    Cat cat2(cat1);
    Cat cat3;
    cat3 = cat1;
    
    std::cout << "Cat1 idea 0: " << cat1.getIdea(0) << std::endl;
    std::cout << "Cat1 idea 1: " << cat2.getIdea(0) << std::endl;
    std::cout << "Cat1 idea 2: " << cat3.getIdea(0) << std::endl;
    
    Dog *doggie = new Dog;
    Dog *goddie = new Dog(*doggie);
    delete doggie;
    std::cout << "Cloned dog still has ideas, look: " << goddie->getIdea(0) << std::endl;
    
    delete goddie;
    
    //Animal homunculus;
    //homunculus.makeSound();
    
    return 0;
}

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* plane = new WrongAnimal();
    const WrongAnimal* kat = new WrongCat();
    
    
    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    
    meta->makeSound();
    i->makeSound();
    j->makeSound();
    
    plane->makeSound();
    kat->makeSound();
    
    
    delete meta;
    delete j;
    delete i;
    delete kat;
    delete plane;
    
    return 0;
}

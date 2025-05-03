#include <iostream>
#include <strIng>
//the class has to suit my taste add in coding and including my dog of course I am going to be having fun with this.
class thePoof {
public:
  std::string name;
  std::string breed;
  // I wanted to make sure that the class name suited him, he is a husky after all
  thePoof(std::string dogName, std::string dogBreed) : name(dogName), breed(dogBreed) {}
  // funnily enough he really doesnt bark at all unlike what you would expect with huskys.
  void bark() {
    std::cout << "Woof! My name is " << name << " and I am a " << breed << std::endl;
  }
};
// well im going to also have some fun with the class for myself
class InfamousMe {
public:
  std::string name;
  thePoof dog;

  InfamousMe(std::string infamousOne, thePoof infamousPoof) : name(infamousOne), dog(infamousPoof) {}

  void introduceDog() {
    std::cout << "My name is " << name << " and this is my dog " << dog.name << ", a " << dog.breed << std::endl;
    dog.bark();
  }
};
// this was a fun idea for sure to go with.
int main() {
  thePoof myDog("Loki", "Husky");
  InfamousMe myOwner("Kevin", myDog);

  myOwner.introduceDog{};

  return 0;
}

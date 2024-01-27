#include <iostream>
#include "Person.hpp"
#include "PersonBuilder.hpp"
#include "PersonAdressBuilder.hpp"
#include "PersonJobBuilder.hpp"

int main(){
    
    Person person = Person::create().lives().at("Schappachstr.").in("Berlin").with_postal_code("12527")
                  .works().as("Artist").at_company("Magnificent Matter").earning(200000);
    
    std::cout << person;
    return 0;
}



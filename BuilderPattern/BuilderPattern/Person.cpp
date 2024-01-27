//
//  Person.cpp
//  BuilderPattern
//
//  Created by Alexander Poletajev on 27/01/24.
//

#include "Person.hpp"
#include "PersonBuilder.hpp"

PersonBuilder Person::create(){
    return PersonBuilder();
}

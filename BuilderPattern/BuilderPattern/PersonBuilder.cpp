//
//  PersonBuilder.cpp
//  BuilderPattern
//
//  Created by Alexander Poletajev on 27/01/24.
//

#include "PersonBuilder.hpp"
#include "PersonAdressBuilder.hpp"
#include "PersonJobBuilder.hpp"


PersonAddressBuilder PersonBuilderBase::lives() const {
    return PersonAddressBuilder(this->p);
}

PersonJobBuilder PersonBuilderBase::works() const {
    return PersonJobBuilder(this->p);
}

PersonBuilderBase::PersonBuilderBase(Person& person): p{person} {}

PersonBuilder::PersonBuilder() : PersonBuilderBase(p) {}




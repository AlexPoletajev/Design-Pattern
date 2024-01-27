//
//  Person.hpp
//  BuilderPattern
//
//  Created by Alexander Poletajev on 27/01/24.
//

#ifndef Person_hpp
#define Person_hpp

#include <string>
#include <sstream>

class PersonBuilder;

class Person{

    // Adress Information
    std::string street_adress, post_code, city;
    
    // Occupational Information
    std::string position, company;
    int salary{0};
    
public:
    static PersonBuilder create();
    
    friend std::ostream& operator<<(std::ostream& stream, const Person& p) {
        
        stream  << "StreetAdress: " << p.street_adress << std::endl
                << "Postal Code:  " << p.post_code << std::endl
                << "City:         " << p.city << std::endl
                << "Occupation:   " << p.position << std::endl
                << "Company:      " << p.company << std::endl
                << "Salary:       " << p.salary << "€" << std::endl;
        
        return stream;
                
    }
    friend class PersonBuilder;
    friend class PersonAddressBuilder;
    friend class PersonJobBuilder;
};

#endif /* Person_hpp */

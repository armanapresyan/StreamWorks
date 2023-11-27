#ifndef ADDRESSBOOK_HPP
#define ADDRESSBOOK_HPP

#include <string>
#include <fstream>
#include <map>
#include <vector>



class Addressbook{
 
public:
   Addressbook();

public:
   void addContactData();
   void deleteContactData();
   void editContact(); 
   void seeAllContact();
   void init();

private:
    std::fstream m_contact;
    std::vector<std::map<std::string, std::string>> m_data;
};



#endif //ADDRESSBOOK_HPP
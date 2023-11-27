#include "Addressbook.hpp"
#include <iostream>
#include <string>
#include <vector>

Addressbook::Addressbook() = default;

void Addressbook::addContactData() {
    std::map<std::string, std::string> contact;

    std::cout << "Hello!" << std::endl;

    std::cout << "Please write your name! ";
    std::string name;
    std::cin >> name;
    contact["Name"] = name;

    std::cout << "Please write your email! ";
    std::string email;
    std::cin >> email;
    contact["Email"] = email;

    std::cout << "Please write your phoneNumber! ";
    std::string number;
    std::cin >> number;
    contact["PhoneNumber"] = number;

    m_data.push_back(contact);

    m_contact.open("contact.json", std::ios::out);
    if (!m_contact.is_open()) {
        std::cout << "Error: File didn't open!" << std::endl;
        return;
    }

    
    

    for (size_t i = 0; i < m_data.size(); ++i) {
        if (i > 0) {
            m_contact << ",";
        }

        m_contact << "{" << std::endl;
        m_contact << "\"Name\": \"" << m_data[i].at("Name") << "\"," << std::endl;
        m_contact << "\"Email\": \"" << m_data[i].at("Email") << "\"," << std::endl;
        m_contact << "\"PhoneNumber\": \"" << m_data[i].at("PhoneNumber") << "\"" << std::endl;
        m_contact << "}";
    }

    

    m_contact.close();
}


void Addressbook::deleteContactData() {
    std::cout << "Please tell us the name you want to delete! ";
    std::string name;
    std::cin >> name;

    
    for (auto it = m_data.begin(); it != m_data.end(); ++it) {
        if (it->at("Name") == name) {
            m_data.erase(it);

            
            m_contact.open("contact.json", std::ios::out | std::ios::trunc);
            if (!m_contact.is_open()) {
                std::cerr << "Error: File didn't open!" << std::endl;
                return;
            }

            for (size_t i = 0; i < m_data.size(); ++i) {
                m_contact << "{" << std::endl;
                m_contact << "\"Name\": \"" << m_data[i].at("Name") << "\"," << std::endl;
                m_contact << "\"Email\": \"" << m_data[i].at("Email") << "\"," << std::endl;
                m_contact << "\"PhoneNumber\": \"" << m_data[i].at("PhoneNumber") << "\"" << std::endl;
                m_contact << "}";
            }
    

           
            m_contact.close();

            std::cout << "Contact deleted successfully!" << std::endl;
            return; 
        }
    }

    std::cout << "Contact not found!" << std::endl;
}



void Addressbook::editContact() {
    std::cout << "Please tell us the name you want to edit! ";
    std::string name;
    std::cin >> name;

    for (auto it = m_data.begin(); it != m_data.end(); ++it) {
        if (it->at("Name") == name) {
            std::cout << "Please enter the new name: ";
            std::string newName;
            std::cin >> newName;

            std::cout << "Please enter the new email: ";
            std::string newEmail;
            std::cin >> newEmail;

            std::cout << "Please enter the new phone number: ";
            std::string newNumber;
            std::cin >> newNumber;

            it->at("Name") = newName;
            it->at("Email") = newEmail;
            it->at("PhoneNumber") = newNumber;

            m_contact.open("contact.json", std::ios::out | std::ios::app);
            if (!m_contact.is_open()) {
                std::cerr << "Error: File didn't open!" << std::endl;
                return;
            }

            m_contact << "{" << std::endl;
            m_contact << "\"Name\": \"" << it->at("Name") << "\"," << std::endl;
            m_contact << "\"Email\": \"" << it->at("Email") << "\"," << std::endl;
            m_contact << "\"PhoneNumber\": \"" << it->at("PhoneNumber") << "\"" << std::endl;
            m_contact << "}";

            m_contact.close();

            std::cout << "Contact edited successfully!" << std::endl;
            return;
        }
    }

    std::cout << "Contact not found!" << std::endl;
}

void Addressbook::seeAllContact(){
    for (auto it = m_data.begin(); it != m_data.end(); ++it) {
        std::cout << "{" << std::endl;
        std::cout << "Name"  << " : " << it->at("Name") << std::endl;
        std::cout << "Email"  << " : " << it->at("Email") << std::endl;
        std::cout << "PhoneNumber"  << " : " << it->at("PhoneNumber") << std::endl;
        std::cout << "}" << std::endl;
    }
}



void Addressbook::init() {
    while (true) {
        std::cout << "Here we start our program. Please mention the tasks:\n"
                     "1. Add new data to your contact (press 1)\n"
                     "2. Delete data from your contact (press 2)\n"
                     "3. Edit the data (press 3)\n"
                     "4. See all data (press 4)\n"
                     "0. Exit the program (press 0)\n" << std::endl;

        int action = 0;
        std::cin >> action;

        if (action == 0) {
            std::cout << "Exiting the program. Goodbye!" << std::endl;
            break; 
        }

        switch (action) {
            case 1:
                addContactData();
                break;
            case 2:
                deleteContactData();
                break;
            case 3:
                editContact();
                break;
            case 4:
                seeAllContact();
                break;
            default:
                std::cout << "Wrong action. Please try again." << std::endl;
                break;
        }
    }
}


#pragma once
#include <string>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
public:
    Contact();
    bool setContact();
    bool check_str(std::string str);
    std::string getFirstName() { return firstName.substr(0, 8); };
    std::string getLastName() { return lastName.substr(0, 8); };
    std::string getNickName() { return nickName.substr(0, 8); };
    std::string getDarkestSecret() { return darkestSecret.substr(0, 8); };
};
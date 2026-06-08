#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

    void setFirstName(std::string value);
    void setLastName(std::string value);
    void setNickname(std::string value);
    void setPhoneNumber(std::string value);
    void setDarkestSecret(std::string value);
};

#endif
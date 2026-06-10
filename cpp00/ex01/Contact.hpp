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

    void setFirstName(const std::string& value);
    void setLastName(const std::string& value);
    void setNickname(const std::string& value);
    void setPhoneNumber(const std::string& value);
    void setDarkestSecret(const std::string& value);
};

#endif
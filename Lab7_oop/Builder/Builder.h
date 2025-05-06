#pragma once
#include <iostream>
using namespace std;

class User
{
public:
    string firstName;
    string lastName;
    string age;
    string phone;
    string email;
    string city;
    string ToString();
};

class UserBuilder
{
public:
    void CreateNewUser();
    User *GetThisUser();
    ~UserBuilder();

    virtual void SetName() = 0;
    virtual void SetLastName() = 0;
    virtual void SetAge() = 0;
    virtual void SetPhone() = 0;
    virtual void SetEmail() = 0;
    virtual void SetCity() = 0;

protected:
    User *user;
};

class UserRM : public UserBuilder
{
public:
    virtual void SetName() override;
    virtual void SetLastName() override;
    virtual void SetAge() override;
    virtual void SetPhone() override;
    virtual void SetEmail() override;
    virtual void SetCity() override;
};

class UserAF : public UserBuilder
{
public:
    virtual void SetName() override;
    virtual void SetLastName() override;
    virtual void SetAge() override;
    virtual void SetPhone() override;
    virtual void SetEmail() override;
    virtual void SetCity() override;
};

class UserLP : public UserBuilder
{
public:
    virtual void SetName() override;
    virtual void SetLastName() override;
    virtual void SetAge() override;
    virtual void SetPhone() override;
    virtual void SetEmail() override;
    virtual void SetCity() override;
};

class UserRegistration
{
private:
    UserBuilder *_userBuilder;

public:
    void SetUserBuilder(UserBuilder *uBuilder);
    User *GetUser();
    void ConstructUser();
};
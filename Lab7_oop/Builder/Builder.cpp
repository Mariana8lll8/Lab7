#include <iostream>
#include "Builder.h"
using namespace std;

string User::ToString() { return string("\nUser: " + firstName + lastName + "\n" + "Age: " + age + "\n" + "Phone: " + phone + "\n" + "Email: " + email + "\n" + "City: " + city + "\n" + "--- User registered! ---\n\n"); }

void UserBuilder::CreateNewUser() { user = new User(); }
User* UserBuilder:: GetThisUser() { return user; }
UserBuilder::~UserBuilder() { delete user; }

void UserRM::SetName() { this->user->firstName = "Mariana "; }
void UserRM::SetLastName() { this->user->lastName = "Roman"; }
void UserRM::SetAge() { this->user->age = "18"; }
void UserRM::SetPhone() { this->user->phone = "+380632584884";}
void UserRM::SetEmail() { this->user->email = "Mariana.Roman@lnu.edu.ua"; }
void UserRM::SetCity() { this->user->city = "Lviv\n"; }

void UserAF::SetName() { this->user->firstName = "Anastasiia "; }
void UserAF::SetLastName() { this->user->lastName = "Fradkova"; }
void UserAF::SetAge() { this->user->age = "18"; }
void UserAF:: SetPhone() { this->user->phone = "+380661484985"; }
void UserAF::SetEmail() { this->user->email = "Anastasiia.Fradkova@lnu.edu.ua"; }
void UserAF::SetCity() { this->user->city = "Lviv\n"; }

void UserLP::SetName() { this->user->firstName = "Pavlo "; }
void UserLP::SetLastName() { this->user->lastName = "Levush"; }
void UserLP::SetAge() { this->user->age = "??"; }
void UserLP:: SetPhone() { this->user->phone = "+380950780400"; }
void UserLP::SetEmail() { this->user->email = "Pavlo.Levush@lnu.edu.ua"; }
void UserLP::SetCity() { this->user->city = "Lviv\n"; }

void UserRegistration::SetUserBuilder(UserBuilder* uBuilder) { _userBuilder = uBuilder; }
User* UserRegistration::GetUser() { return _userBuilder->GetThisUser(); }
void UserRegistration::ConstructUser() 
{
    _userBuilder->CreateNewUser();
    _userBuilder->SetName();
    _userBuilder->SetLastName();
    _userBuilder->SetAge();
    _userBuilder->SetPhone();
    _userBuilder->SetEmail();
    _userBuilder->SetCity();
}


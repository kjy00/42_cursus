#include "./Contact.hpp"

std::string Contact::getFirstName() {
	return this->first_name;
}
std::string Contact::getLastName() {
	return this->last_name;
}
std::string Contact::getNickname() {
	return this->nickname;
}
std::string Contact::getPhoneNbr() {
	return this->phone_number;
}
std::string Contact::getSecret() {
	return this->darkest_secret;
}
void Contact::setFirstName(std::string first_name) {
	this->first_name = first_name;
}
void Contact::setLastName(std::string last_name) {
	this->last_name = last_name;
}
void Contact::setNickname(std::string nickname) {
	this->nickname = nickname;
}
void Contact::setPhoneNbr(std::string phone_number) {
	this->phone_number = phone_number;
}
void Contact::setSecret(std:: string darkest_secret) {
	this->darkest_secret = darkest_secret;
}

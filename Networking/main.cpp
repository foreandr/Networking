#include <string>
#include <iostream>
#include "encrypytionTester.h"
int main() {
	std::string name = "andre";
	std::string nameEN = lenCeaser2encrypt(name);
	std::cout << nameEN << "\n" << lenCeaser2decrypt(nameEN);

}
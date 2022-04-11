//Jose Velazquez
//Shop

#pragma once
#include <iostream>
#include <string>
#include <iomanip>

#define e '\n';

using namespace std;

class Shop {
private:
	int opc = 0, var, counterA = 0, num = 1, counterB = 5, counterC = 0, counterD = 0, numB;
	string usernameA[5], passwordA[5], productA[8]{ "Keyboard" , "Mouse" , "Monitor" , "PC" , "Headset" }, cartC[5];
	string usernameB, passwordB, productB;
	float priceA[8]{ 40 , 20 , 200 , 100 , 50 };
	float priceB, cartA[5], cartB, total = 0;


public:
	Shop();

	void Welcome();
	void Menu();
	void Login();
	void CreateAccount();
	void ShopF();
	void Buy();
	void Sell();
	void Cart();
	void Default();
	int Verification();
	void Exit();


};
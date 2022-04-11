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
	int Opc = 0, Var, CounterA = 0, Num = 1, CounterB = 5, CounterC = 0, CounterD = 0, NumB;
	string UsernameA[5], PasswordA[5], ProductA[8]{ "Keyboard" , "Mouse" , "Monitor" , "PC" , "Headset" }, CartC[5];
	string UsernameB, PasswordB, ProductB;
	float PriceA[8]{ 40 , 20 , 200 , 100 , 50 };
	float PriceB, CartA[5], CartB, Total = 0;


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
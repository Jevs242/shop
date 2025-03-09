//Jose Velazquez
//Shop

#include "shop.h"

Shop::Shop()
{
	Welcome();
	Menu();
}

void ClearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Pause() {
#ifdef _WIN32
    system("pause");
#else
    std::cout << "Press Enter to continue...";
    std::cin.ignore();
    std::cin.get();
#endif
}

void Shop::Welcome()
{
	cout << setw(25) <<"Welcome" << e;
}

void Shop::Menu()
{
	do {
		cout << setw(30) << "Shop Online\n\n";
		cout << "....................Menu...................." << e;
		cout << "1.Login | 2.Create Account | 3.Exit" << e;
		cin >> opc;
		ClearScreen();

		switch (opc)
		{
		case 1:
			Login();
			break;
		case 2:
			CreateAccount();
			break;
		case 3:
			Exit();
			break;
		default:

			break;
		}
	} while (opc != 3);
}

void Shop::Login()
{
	cout << " |Login| " << e;

	if (counterA < 1)
	{
		ClearScreen();
		cout << "You haven't yet created an account\nCreate an account\n" << e;
	}
	else
	{
		cout << "Enter your username" << e;
		cin >> usernameB;
		cout << "Enter your password" << e;
		cin >> passwordB;
		var = Verification();
		ClearScreen();
		if (var > -1)
		{
			ShopF();
		}
		else
		{
			cout << "This account doesn't exist" << e;
		}
	}

}

void Shop::CreateAccount()
{
	cout << " |Create Account| " << e;
	if (counterA < 3)
	{
		cout << "Enter a Username" << e;
		cin >> usernameA[counterA];
		cout << "Enter a Password" << e;
		cin >> passwordA[counterA];
		counterA++;
	}
	ClearScreen();
}

void Shop::Sell()
{
	cout << " |Sell|" << e;
	if (counterB < 7)
	{
		cout << "Enter a product do you wish to sell" << e;
		cin >> productA[counterB];
		cout << "Enter a price on the product" << e;
		cin >> priceA[counterB];
		counterB++;
		ClearScreen();
	}
	else
	{
		ClearScreen();
		cout << "The maximum you can add is two products" << e;
	}
}

void Shop::Buy()//Compra
{
	cout << " |Buy|" << e;
	num = 1;
	cout << "#" << setw(14) << "Product" << setw(14) << "Price" << e;
	for (int i = 0; i < counterB; i++)
	{
		cout << num << "." << setw(13) << productA[i] << setw(13) << "$" << priceA[i] << e;
		num++;
	}
	cout << "What do you want to buy?" << e;
	cin >> counterC;
	{
		cartB = priceA[counterC - 1];
		cartC[counterD] = productA[counterC - 1];
		cartA[counterD] = priceA[counterC - 1];
		counterD++;
	}
	total += cartB;
	ClearScreen();
}

void Shop::Default()
{
	cout << "Invalid option" << e;
}

int Shop::Verification()
{
	for (int i = 0; i < counterA; i++)
	{
		if (usernameB == usernameA[i] && passwordB == passwordA[i])
		{
			return i;
			break;
		}
	}
	return -1;
}

void Shop::Exit()
{
	ClearScreen();
	cout << " |Exit| \n" << "See you later!!" << e;
	Pause();
	exit(1);
}

void Shop::ShopF()
{
	cout << setw(28) << " |Welcome " << usernameA[var] << "|" << e;
	opc++;
	do {
		cout << setw(28) << " Conected to " << " " << usernameA[var] << e;
		cout << "1.Buy | 2.Sell | 3.Cart" "(" << counterD << ") | ""4.Logout | 5.Exit" << e;
		cin >> opc;
		switch (opc)
		{
		case 1:
			Buy();
			break;

		case 2:
			Sell();
			break;
		case 3:
			Cart();
			break;
		case 4:
			ClearScreen();
			Menu();
			break;
		case 5:
			Exit();
			Pause();
			break;
		default:
			Default();
			break;
		}
	} while (opc != 5);


}

void Shop::Cart()//Carrito de comprar
{
	cout << " |Cart|" << e;
	num = 1;
	if (counterD > 0)
	{
		for (int i = 0; i < counterD; i++)
		{
			cout << num << "." << setw(13) << cartA[i] << "$" << setw(13) << cartC[i] << e;
			num++;

		}
		cout << "\n" << "The total amount payable is: " << setw(7) << "$" << total << e;
		cout << "1.Pay" "  |  "  "2.Continue Shopping" << e;
	}
	else
	{
		ClearScreen();
		cout << "You have nothing in the cart" << e;
		ShopF();
	}
	cin >> opc;
	ClearScreen();
	switch (opc)
	{
	case 1:

		ClearScreen();
		cout << "Paying...\n";
		ClearScreen();
		cout << "...Your payment has been successfully completed..." << e;
		total = 0;
		counterD = 0;
		break;
	case 2:
		void Cart();
		break;
	default:
		Default();
		break;
	}
}

int  main()
{
	Shop Shop;
	Pause();
	return 0;
}


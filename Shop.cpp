//Jose Velazquez
//Shop

#include "Shop.h"

Shop::Shop()
{
	Welcome();
	Menu();
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
		cin >> Opc;
		system("cls");

		switch (Opc)
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
	} while (Opc != 3);
}

void Shop::Login()
{
	cout << " |Login| " << e;

	if (CounterA < 1)
	{
		system("cls");
		cout << "You haven't yet created an account\nCreate an account\n" << e;
	}
	else
	{
		cout << "Enter your username" << e;
		cin >> UsernameB;
		cout << "Enter your password" << e;
		cin >> PasswordB;
		Var = Verification();
		system("cls");
		if (Var > -1)
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
	if (CounterA < 3)
	{
		cout << "Enter a Username" << e;
		cin >> UsernameA[CounterA];
		cout << "Enter a Password" << e;
		cin >> PasswordA[CounterA];
		CounterA++;
	}
	system("cls");
}

void Shop::Sell()
{
	cout << " |Sell|" << e;
	if (CounterB < 7)
	{
		cout << "Enter a product do you wish to sell" << e;
		cin >> ProductA[CounterB];
		cout << "Enter a price on the product" << e;
		cin >> PriceA[CounterB];
		CounterB++;
		system("cls");
	}
	else
	{
		system("cls");
		cout << "The maximum you can add is two products" << e;
	}
}

void Shop::Buy()
{
	cout << " |Buy|" << e;
	Num = 1;
	cout << "#" << setw(14) << "Product" << setw(14) << "Price" << e;
	for (int i = 0; i < CounterB; i++)
	{
		cout << Num << "." << setw(13) << ProductA[i] << setw(13) << "$" << PriceA[i] << e;
		Num++;
	}
	cout << "What do you want to buy?" << e;
	cin >> CounterC;
	{
		CartB = PriceA[CounterC - 1];
		CartC[CounterD] = ProductA[CounterC - 1];
		CartA[CounterD] = PriceA[CounterC - 1];
		CounterD++;
	}
	Total += CartB;
	system("cls");
}

void Shop::Default()
{
	cout << "Invalid option" << e;
}

int Shop::Verification()
{
	for (int i = 0; i < CounterA; i++)
	{
		if (UsernameB == UsernameA[i] && PasswordB == PasswordA[i])
		{
			return i;
			break;
		}
	}
	return -1;
}

void Shop::Exit()
{
	system("cls");
	cout << " |Exit| \n" << "See you later!!" << e;
	system("Pause");
	exit(1);
}

void Shop::ShopF()
{
	cout << setw(28) << " |Welcome " << UsernameA[Var] << "|" << e;
	Opc++;
	do {
		cout << setw(28) << " Conected to " << " " << UsernameA[Var] << e;
		cout << "1.Buy | 2.Sell | 3.Cart" "(" << CounterD << ") | ""4.Logout | 5.Exit" << e;
		cin >> Opc;
		switch (Opc)
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
			system("cls");
			Menu();
			break;
		case 5:
			Exit();
			system("Pause");
			break;
		default:
			Default();
			break;
		}
	} while (Opc != 5);


}

void Shop::Cart()
{
	cout << " |Cart|" << e;
	Num = 1;
	if (CounterD > 0)
	{
		for (int i = 0; i < CounterD; i++)
		{
			cout << Num << "." << setw(13) << CartA[i] << "$" << setw(13) << CartC[i] << e;
			Num++;

		}
		cout << "\n" << "The total amount payable is: " << setw(7) << "$" << Total << e;
		cout << "1.Pay" "  |  "  "2.Continue Shopping" << e;
	}
	else
	{
		system("cls");
		cout << "You have nothing in the cart" << e;
		ShopF();
	}
	cin >> Opc;
	system("cls");
	switch (Opc)
	{
	case 1:

		system("cls");
		cout << "Paying...\n";
		system("cls");
		cout << "...Your payment has been successfully completed..." << e;
		Total = 0;
		CounterD = 0;
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
	system("Pause");
	return 0;
}


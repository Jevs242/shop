//Jose E Velazquez Sepulveda
//Final: Tienda

//Librerias
#include <iostream>
#include <string>
#include <iomanip>

//Defines
#define e '\n'


using namespace std;

//Funciones
void mensaje();
void  menu();
void iniciarsesion();
void  crearcuenta();
void  salir();
void  df();
void  tienda();
void  compra();
void  vender();
void carrito();
int  verificacion();

//Declaraciones de variables

float  precio[8]{ 40 , 20 , 200 ,100,50 }, preciob, carrc[5], carr, total;
int opc = 0, counter = 0, var, num = 1, counter2 = 5, counter3, counter4, numc;
string nombre[5], nombreb, passwordb, password[5], producto[8]{ "Teclado" , "Mouse" , "Monitor" , "PC" , "Audifono" }, productob, carrp[5];


int  main()
{
	//Llamada de funciones
	mensaje();
	menu();
	system("Pause");
	return 0;
}

int verificacion()//Funcion de verificacion
{
	for (int i = 0; i < counter; i++)
	{
		if (nombreb == nombre[i] && passwordb == password[i])
		{
			return i;
			break;

		}
	}
	return -1;
}

//Funciones
void mensaje()//Mensaje de bienvenida
{
	cout << "                 Bienvenido" << e << e;
}
void menu()//Menu Principal
{
	do {
		cout << "                Tienda Online\n\n" "....................Menu...................." << e << e;
		cout << "1.Iniciar Sesion | 2.Crear Cuenta | 3.Salir" << e;
		cin >> opc;
		system("cls");//Borrar pantalla

		switch (opc)
		{
		case 1:
			iniciarsesion();
			break;
		case 2:
			crearcuenta();
			break;
		case 3:
			salir();
			break;
		default:
			df();
			break;
		}
	} while (opc != 3);

}

void iniciarsesion()//Iniciar Sesion
{
	cout << " |Iniciar Sesion| " << e;

	if (counter < 1)
	{
		system("cls");
		cout << "No se ha creado ninguna cuenta\nCree una cuenta\n" << e;
	}
	else
	{
		cout << "Ingrese su nombre de usuario" << e;
		cin >> nombreb;
		cout << "Ingrese su password" << e;
		cin >> passwordb;
		var = verificacion();
		system("cls");
		if (var > -1)
		{
			tienda();
		}
		else
		{
			cout << "Esa cuenta no existe" << e;
		}
	}

}

void crearcuenta()//Crear Cuenta
{
	cout << " |Crear Cuenta| " << e;
	if (counter < 3)
	{
		cout << "Entre un nombre de usuario" << e;
		cin >> nombre[counter];
		cout << "Entre un password" << e;
		cin >> password[counter];
		counter++;
	}
	system("cls");
}

void salir()//Salir
{
	system("cls");
	cout << " |Salir| \n" << "Hasta Luego!!" << e;
	system("Pause");
	exit(1);//Terminar el programa
}

void df()//Default
{
	cout << "Opcion no valida" << e;
}

void tienda()//Menu De Tienda
{
	cout << setw(28) << " |Bienvenido " << nombre[var] << "|" << e;
	opc++;
	do {
		cout << setw(28) << " Conectado en" << " " << nombre[var] << e;
		cout << "1.Comprar | 2.Vender | 3.Carrito" "(" << counter4 << ") | ""4.Logout | 5.Salir" << e;
		cin >> opc;
		switch (opc)
		{
		case 1:
			compra();
			break;

		case 2:
			vender();
			break;
		case 3:
			carrito();
			break;
		case 4:
			system("cls");
			menu();
			break;
		case 5:
			salir();
			system("Pause");
			break;
		default:
			df();
			break;
		}
	} while (opc != 5);


}

void compra()//Compra
{
	cout << " |Comprar|" << e;
	num = 1;
	cout << "#" << setw(14) << "Producto" << setw(14) << "Precio" << e;
	for (int i = 0; i < counter2; i++)
	{
		cout << num << "." << setw(13) << producto[i] << setw(13) << "$" << precio[i] << e;
		num++;
	}
	cout << "Que desea comprar?" << e;
	cin >> counter3;
	{
		//Pasando valores a las variables del carrito
		carr = precio[counter3 - 1];
		carrp[counter4] = producto[counter3 - 1];
		carrc[counter4] = precio[counter3 - 1];
		counter4++;
	}
	total = total + carr;
	system("cls");
}

void vender()//Vender
{
	cout << " |Vender|" << e;
	if (counter2 < 7)
	{
		cout << "Ingrese un producto que desea vender" << e;
		cin >> producto[counter2];
		cout << "Ingrese un precio al producto" << e;
		cin >> precio[counter2];
		counter2++;
		system("cls");
	}
	else
	{
		system("cls");
		cout << "Maximo puedes agregar dos productos" << e;
	}
}

void carrito()//Carrito de comprar
{
	cout << " |Carrito|" << e << e;
	num = 1;
	if (counter4 > 0)
	{
		for (int i = 0; i < counter4; i++)
		{
			cout << num << "." << setw(13) << carrp[i] << setw(13) << "$" << carrc[i] << e;
			num++;

		}
		cout << e << "Su Total a pagar es: " << setw(7) << "$" << total << e << e;
		cout << "1.Pagar" "  |  "  "2.Seguir Comprando" << e;
	}
	else
	{
		system("cls");
		cout << "No tienes ningun producto en el carrito" << e;
		tienda();
	}
	cin >> opc;
	system("cls");
	switch (opc)
	{
	case 1:

		system("cls");
		cout << "Pagando...\n";
		system("cls");
		cout << "...Su pago fue realizado con exito..." << e;
		total = 0;
		counter4 = 0;
		break;
	case 2:
		void carrito();
		break;
	default:
		df();
		break;
	}
}



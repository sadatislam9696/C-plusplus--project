
#include<bits/stdc++.h>
using namespace std;
#include<fstream>
#include<windows.h>
const  char ch = 27;
#define  colour_sky  ch << "[96m"

class shoping
{
private:
    int pcode;
    float price, dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void modify();
    void rem();
    void reciept();
    void list();
};

void shoping :: modify()
{
    fstream data, data1;
    int pkey, token = 0, go_back;

    cout << "\n\t\t\t\t                  Modify the product              " << endl;
    cout << "\t\t\t\t------------------------- o -----------------------" << endl;
    cout << "\t\t\t\tIf you want Go back press [0] else [1] : "; cin >> go_back;
        if(!go_back){
            system("Cls");
            administrator();
        }
    cout << "\t\t\t\tProduct code       : "; cin >> pkey;
    cout << "\t\t\t\t\tProduct new code : "; cin >> pcode;
    cout << "\t\t\t\t\tProduct name     : "; cin >> pname;
    cout << "\t\t\t\t\tProduct price    : "; cin >> price;
    cout << "\t\t\t\t\tProduct discount : "; cin >> dis;
    system("cls");

    data.open("database.txt", ios::in);
    data1.open("database1.txt", ios::app|ios::out);

    int c, p, d;
    string n;

    if(!data)
    {
        cout << "\n\n\n\t\t\t\t\t Empty database ";
        administrator();
    }
    else
    {
        data >> c >> n >> p >> d;
        while(!data.eof())
        {
            if(pkey == c)
            {
                data1 << pcode << " " << pname << " " << price << " " << dis << endl;
                cout << "\n\n\n\t\t\t\t\tRecord Inserted" << endl;
                Sleep(2500); system("cls");
                token++;
            }
            else
            {
                data1 << c << " " << n << " " << p << " " << d << endl;
            }
            data >> c >> n >> p >> d;
        }
        data.close(); data1.close();
    }

    remove("database.txt");
    rename("database1.txt", "database.txt");

    if(token == 0)
    {
        cout << "\n\n\n\t\t\t\t\tRecord not found sorry" << endl;
        Sleep(2500); system("cls");
    }
    administrator();
}
void shoping :: rem()
{
    fstream data, data1;
    int token = 0, pkey, go_back;

    cout << "\n\t\t\t\t                  Delete the product              " << endl;
    cout << "\t\t\t\t------------------------- o ------------------------" << endl;
    cout << "\t\t\t\tIf you want Go back press [0] else [1] : "; cin >> go_back;
        if(!go_back){
            system("Cls");
            administrator();
        }
    cout << "\t\t\t\tEnter the product code : ";
    cin >> pkey;

    data.open("database.txt", ios::in);

    if(!data)
    {
        cout << "\t\t\t\tEmpty database" << endl;
        administrator();
    }
    else
    {
        data1.open("database1.txt", ios::app|ios::out);
        data >> pcode >> pname >> price >> dis;

        while(!data.eof())
        {
            if(pkey == pcode)
            {
                token++;
            }
            else
            {
                data1 << pcode << " " << pname << " " << price << " " << dis << endl;
            }
            data >> pcode >> pname >> price >> dis;
        }

        data1.close(); data.close();
    }

    remove("database.txt");
    rename("database1.txt", "database.txt");

    if(token == 0)
    {
        cout << "\n\n\n\t\t\t\t\tRecord not found sorry !" << endl;
        Sleep(2500); system("cls");
    }
    else
    {
        cout << "\n\n\n\t\t\t\t\tRecord Deleted successfull " << endl;
        Sleep(2500); system("cls");
    }
    administrator();
}
void shoping :: add()
{
a:
    fstream data;
    int c, p, d, token = 0, go_back;
    string n;

    cout << "\n\t\t\t\t                   Add new product               " << endl;
    cout << "\t\t\t\t------------------------ o ------------------------" << endl;
    cout << "\t\t\t\tIf you want Go back press [0] else [1] : "; cin >> go_back;
        if(!go_back){
            system("Cls");
            administrator();
        }
    cout << "\t\t\t\t1.Product code     : "; cin >> pcode;
    cout << "\t\t\t\t2.Product name     : "; cin >> pname;
    cout << "\t\t\t\t3.Product price    : "; cin >> price;
    cout << "\t\t\t\t4.Product discount : "; cin >> dis;
    system("cls");

    data.open("database.txt", ios::in);

    if(!data)
    {
        data.open("database.txt", ios::app|ios::out);
        data << pcode << " " << pname << " " << price << " " << dis << endl;
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while(!data.eof())
        {
            if(pcode == c)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
        if(token >= 1)
        {
            cout << "\n\n\n\t\t\t\tThis product is already exist please try again !" << endl;
            Sleep(2500); system("cls");
            goto a;
        }
        else
        {
            data.open("database.txt", ios::app|ios::out);
            data << pcode << " " << pname << " " << price << " " << dis << endl;
        }
        data.close();
    }
    cout << "\n\n\n\t\t\t\t\tRecord Inserted" << endl;
    Sleep(2500); system("cls");
    administrator();
}
void shoping :: administrator()
{
a:
    int choise;
    cout << "\n\t\t\t\t                 Select your option              " << endl;
    cout << "\t\t\t\t------------------------ o ------------------------" << endl;
    cout << "\t\t\t\t1.Add new product                                  " << endl;
    cout << "\t\t\t\t2.Modify product                                   " << endl;
    cout << "\t\t\t\t3.Delete product                                   " << endl;
    cout << "\t\t\t\t4.Go Back menu                                     " << endl;
    cout << "\t\t\t\tPlease select your option : ";
    cin >> choise;
    system("Cls");

    switch(choise)
    {
    case 1:
        add();
        break;
    case 2:
        modify();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "\n\n\n\t\t\t\tInvalid choise ! please select the given option";
        Sleep(2500);
        system("Cls");
        goto a;
    }
}
void shoping :: menu()
{
m:
    int choise;
    cout << colour_sky <<  endl << endl;
    cout << colour_sky <<  "\t\t\t\t               SUPERMARKET MAIN MENU               " << endl;
    cout << colour_sky <<  "\t\t\t\t------------------------ o ------------------------" << endl;
    cout << colour_sky <<  "\t\t\t\t1.Administrator                                    " << endl;
    cout << colour_sky <<  "\t\t\t\t2.Buyer                                            " << endl;
    cout << colour_sky <<  "\t\t\t\t3.Exit                                             " << endl;
    cout << colour_sky <<  "\t\t\t\tPlease select your choise : ";
    cin >> choise;
    system("Cls");

    switch(choise)
    {
    case 1:
    {
x:
        string email, password;
        int go_back;

        cout << "\n\t\t\t\t                   Plese Loging                  " << endl;
        cout << "\t\t\t\t------------------------ o ------------------------" << endl;
        cout << "\t\t\t\tIf you want Go back press [0] else [1] : "; cin >> go_back;
        if(!go_back){
            system("Cls");
            menu();
        }
        cout << "\t\t\t\tEnter your email  : "; cin >> email;
        cout << "\t\t\t\tEnter password    : "; cin >> password;

        system("Cls");

        if(email == "p" and password == "s")
        {
            cout << "\n\n\n\t\t\t\t\tLoging successful" << endl;
            Sleep(2500); system("cls");
            administrator();
        }
        else
        {
            cout << "\n\n\n\t\t\t\tInvalid email or password Please try again !" << endl;
            Sleep(2500); system("cls");
            goto x;
        }
    }
    case 2:
    {
        buyer();
    }
    case 3:
    {
        cout << "\n\n\n\t\t\t\tThank you ";
        exit(0);
    }
    default:
    {
        cout << "\n\n\n\n\t\t\t\tInvalid choise ! Please select the given option ! ";
        Sleep(2500); system("Cls");
    }
    }
    goto m;
}

void shoping :: list()
{
    fstream data;

    cout << "\n\t\t\t\t                      List of Product               " << endl << endl;
    cout << "\t\t\t\t--------------------------- o --------------------------" << endl;
    cout << "\t\t\t\tpcode\t\tpname\t\tprice\t\tdiscount" << endl;
    cout << "\t\t\t\t-----\t\t-----\t\t-----\t\t--------" << endl;

    data.open("database.txt", ios::in);

    if(!data)
    {
        cout << "\t\t\t\tEmpty database" << endl;
    }
    else
    {
        data >> pcode >> pname >> price >> dis;
        while(!data.eof())
        {
            cout << "\t\t\t\t" << pcode << "\t\t" << pname << "\t\t" << price << "\t\t" << dis << endl;
            data >> pcode >> pname >> price >> dis;
        }
    }
    data.close();
}
void shoping :: reciept()
{
    list();
    float total = 0, dis = 0, amount = 0;
    fstream data, data1;
    int quantity[100], code[100], j = 0;

    cout << "\n\t\t\t\t                   Place the order               " << endl;
    cout << "\t\t\t\t------------------------ o ------------------------" << endl;
a:
    cout << "\t\t\t\tEnter product code     : "; cin >> code[j];
    cout << "\t\t\t\tEnter product quantity : "; cin >> quantity[j];

    int x = 0;
    if(x == 0)
    {
        cout << "\t\t\t\tDo you want to buy another product ? if yes then press [y] else [n] : ";
    }
    char c;
    cin >> c;

    if(c == 'y')
    {
        for(int i = 0; i < j; i++)
        {
            if(code[j] == code[i])
            {
                cout << "\t\t\t\tDuplicate product code please try again !";
                Sleep(2500);
                j++;
                goto a;
            }
        }
        j++;
        goto a;
    }
    else
    {
        system("cls");
        cout << "\n\t\t\t\t                      Reciept                    " << endl;
        cout << "\t\t\t\t------------------------ o ------------------------" << endl << endl;
        cout << "\t\t\t\tpname    Quantity     price    totprice    Disprice" << endl;
        cout << "\t\t\t\t-----    --------     -----    --------    --------" << endl;

        data.open("database.txt", ios::in);
        data >> pcode >> pname >> price >> dis;

        while(!data.eof())
        {
            for(int i = 0; i <= j; i++)
            {
                if(pcode == code[i])
                {
                    amount = price * quantity[i];
                    dis = amount - (amount * dis / 100);
                    total += dis;
                    cout << "\t\t\t\t" << pname  << "\t " << quantity[i] << "\t\t" <<  price << "\t" << amount << "\t   " << dis << endl;
                }
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
    }
    cout << "\n\t\t\t\tTotal amount : ";
    cout << total << endl << endl << endl ;
    exit(0);
}
void shoping :: buyer()
{
b:
    cout << "\n\t\t\t\t                       BUYER                     " << endl;
    cout << "\t\t\t\t------------------------ o ------------------------" << endl;
    cout << "\t\t\t\t1.product list                                     " << endl;
    cout << "\t\t\t\t2.Buy product                                      " << endl;
    cout << "\t\t\t\t3.Go Back                                          " << endl;
    cout << "\t\t\t\tSelect your option : ";
    int choise;
    cin >> choise;
    system("Cls");

    switch(choise)
    {
    case 1:
        list();
        buyer();
        break;
    case 2:
        reciept();
        break;
    case 3:
        menu();
        break;
    default:
        cout << "\n\n\n\n\t\t\t\tInvalid choise ! Please select the given option " << endl;
        Sleep(2500); system("Cls");
        goto b;
    }
}

void start()
{
    cout << colour_sky << "\n\n\n\t\t\t\t       WELCOME TO OUR SUPERMARKET " << endl;
    cout << "\t\t\t\t------------------ o -------------------" << endl;
    cout << colour_sky << "\t\t\t\tLOADING : ";

    char x = 219;
    for(int i = 1; i <= 30; i++)
    {
        if(i <= 10)
        {
            cout << colour_sky << x;
            Sleep(300);
        }
        else if(i > 10 and i <= 25)
        {
            cout << colour_sky << x;
            Sleep(50);
        }
        else
        {
            cout << colour_sky << x;
            Sleep(200);
        }
    }
    system("cls");
}

int main()
{
    start();
    shoping s;
    s.menu();
    return 0;
}

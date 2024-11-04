Sure! Below is the equivalent Python code for the provided C++ shopping management system. I've made some adjustments to adapt the C++ features to Python, such as file handling, class methods, and input/output:

```python
import os
import time

class Shopping:
    def __init__(self):
        self.pcode = 0
        self.price = 0.0
        self.dis = 0.0
        self.pname = ""

    def menu(self):
        while True:
            print("\033[96m")
            print("\n\t\t\t\t               SUPERMARKET MAIN MENU               ")
            print("\t\t\t\t------------------------ o ------------------------")
            print("\t\t\t\t1.Administrator                                    ")
            print("\t\t\t\t2.Buyer                                            ")
            print("\t\t\t\t3.Exit                                             ")
            print("\t\t\t\tPlease select your choice: ", end="")
            choice = int(input())
            os.system('cls' if os.name == 'nt' else 'clear')

            if choice == 1:
                self.login()
            elif choice == 2:
                self.buyer()
            elif choice == 3:
                print("\n\n\n\t\t\t\tThank you ")
                break
            else:
                print("\n\n\n\t\t\t\tInvalid choice! Please select the given option.")

    def login(self):
        while True:
            print("\n\t\t\t\t                   Please Log in                  ")
            print("\t\t\t\t------------------------ o ------------------------")
            print("\t\t\t\tEnter your email: ", end="")
            email = input()
            print("\t\t\t\tEnter password: ", end="")
            password = input()

            if email == "p" and password == "s":
                print("\n\n\n\t\t\t\t\tLogin successful")
                time.sleep(2)
                os.system('cls' if os.name == 'nt' else 'clear')
                self.administrator()
                break
            else:
                print("\n\n\n\t\t\t\tInvalid email or password! Please try again.")

    def administrator(self):
        while True:
            print("\n\t\t\t\t                 Select your option              ")
            print("\t\t\t\t------------------------ o ------------------------")
            print("\t\t\t\t1.Add new product                                  ")
            print("\t\t\t\t2.Modify product                                   ")
            print("\t\t\t\t3.Delete product                                   ")
            print("\t\t\t\t4.Go Back menu                                     ")
            print("\t\t\t\tPlease select your option: ", end="")
            choice = int(input())
            os.system('cls' if os.name == 'nt' else 'clear')

            if choice == 1:
                self.add()
            elif choice == 2:
                self.modify()
            elif choice == 3:
                self.remove()
            elif choice == 4:
                break
            else:
                print("\n\n\n\t\t\t\tInvalid choice! Please select the given option.")

    def add(self):
        while True:
            print("\n\t\t\t\t                   Add new product               ")
            print("\t\t\t\t------------------------ o ------------------------")
            print("\t\t\t\t1.Product code: ", end="")
            self.pcode = int(input())
            print("\t\t\t\t2.Product name: ", end="")
            self.pname = input()
            print("\t\t\t\t3.Product price: ", end="")
            self.price = float(input())
            print("\t\t\t\t4.Product discount: ", end="")
            self.dis = float(input())
            os.system('cls' if os.name == 'nt' else 'clear')

            try:
                with open("database.txt", "r") as data:
                    for line in data:
                        c, n, p, d = line.strip().split()
                        if self.pcode == int(c):
                            print("\n\n\n\t\t\t\tThis product already exists, please try again!")
                            time.sleep(2)
                            os.system('cls' if os.name == 'nt' else 'clear')
                            continue

                with open("database.txt", "a") as data:
                    data.write(f"{self.pcode} {self.pname} {self.price} {self.dis}\n")
                print("\n\n\n\t\t\t\t\tRecord Inserted")
                time.sleep(2)
                os.system('cls' if os.name == 'nt' else 'clear')
                break

            except FileNotFoundError:
                with open("database.txt", "w") as data:
                    data.write(f"{self.pcode} {self.pname} {self.price} {self.dis}\n")
                print("\n\n\n\t\t\t\t\tRecord Inserted")
                time.sleep(2)
                os.system('cls' if os.name == 'nt' else 'clear')
                break

    def modify(self):
        pkey = int(input("\t\t\t\tProduct code to modify: "))
        found = False

        lines = []
        with open("database.txt", "r") as data:
            for line in data:
                c, n, p, d = line.strip().split()
                if pkey == int(c):
                    found = True
                    print("\t\t\t\t\tNew Product code: ", end="")
                    self.pcode = int(input())
                    print("\t\t\t\t\tProduct name: ", end="")
                    self.pname = input()
                    print("\t\t\t\t\tProduct price: ", end="")
                    self.price = float(input())
                    print("\t\t\t\t\tProduct discount: ", end="")
                    self.dis = float(input())
                    lines.append(f"{self.pcode} {self.pname} {self.price} {self.dis}\n")
                else:
                    lines.append(line)

        if found:
            with open("database.txt", "w") as data:
                data.writelines(lines)
            print("\n\n\n\t\t\t\t\tRecord Modified")
        else:
            print("\n\n\n\t\t\t\t\tRecord not found, sorry!")

        time.sleep(2)
        os.system('cls' if os.name == 'nt' else 'clear')

    def remove(self):
        pkey = int(input("\t\t\t\tEnter the product code to delete: "))
        found = False
        lines = []

        with open("database.txt", "r") as data:
            for line in data:
                c, n, p, d = line.strip().split()
                if pkey == int(c):
                    found = True
                    continue
                lines.append(line)

        if found:
            with open("database.txt", "w") as data:
                data.writelines(lines)
            print("\n\n\n\t\t\t\t\tRecord Deleted successfully")
        else:
            print("\n\n\n\t\t\t\t\tRecord not found, sorry!")

        time.sleep(2)
        os.system('cls' if os.name == 'nt' else 'clear')

    def buyer(self):
        while True:
            print("\n\t\t\t\t                       BUYER                     ")
            print("\t\t\t\t------------------------ o ------------------------")
            print("\t\t\t\t1.Product list                                     ")
            print("\t\t\t\t2.Buy product                                      ")
            print("\t\t\t\t3.Go Back                                          ")
            print("\t\t\t\tSelect your option: ", end="")
            choice = int(input())
            os.system('cls' if os.name == 'nt' else 'clear')

            if choice == 1:
                self.list()
            elif choice == 2:
                self.receipt()
            elif choice == 3:
                break
            else:
                print("\n\n\n\t\t\t\tInvalid choice! Please select the given option.")

    def list(self):
        print("\n\t\t\t\t                      List of Product               ")
        print("\t\t\t\t--------------------------- o --------------------------")
        print("\t\t\t\tpcode\t\tpname\t\tprice\t\tdiscount")
        print("\t\t\t\t-----\t\t-----\t\t-----\t\t--------")

        try:
            with open("database.txt", "r") as data:
                for line in data:
                    c, n, p, d = line.strip().split()
                    print(f"\t\t\t\t{c}\t\t{n}\t\t{p}\t\t{d}")
        except FileNotFoundError:
            print("\t\t\t\tEmpty database")

    def receipt(self):
        self.list()
        total = 0
        quantity = []
        code = []
        j = 0

        print("\n\t\t\t\t                   Place the order               ")
        print("\t\t\t\t------------------------ o ------------------------")

        while True:
            code_input = int(input("\t\t\t\tEnter product code: "))
            quantity_input = int(input("\t\t\t\tEnter product quantity: "))
            code.append(code_input)
            quantity.append(quantity_input)

            another = input("\t\t\t\tDo you want to buy another product? if yes then press [y] else [n]: ").lower()
            if another == 'n':
                break

        os.system('cls' if os.name == 'nt' else 'clear')
        print("\n\t\t\t\t                      Receipt                    ")
        print("\t\t\t\t------------------------ o ------------------------")
        print("\t\t\t\tpname    Quantity     price    totprice    Disprice")

        with open("database.txt", "r") as data:
            for line in data:
                pcode, pname, price, dis = line.strip().split()
                for i in range(len(code)):
                    if int(pcode) == code[i]:
                        amount = float(price) * quantity[i]

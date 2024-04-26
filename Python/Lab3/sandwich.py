class Sandwich:
    def __init__(self, order_number: int, bread_type: str, meat_type: str):
        self.__order_number = order_number
        self.__bread_type = bread_type
        self.__meat_type = meat_type
        self.__toppings = []

    @property
    def order_number(self) -> int:
        return self.__order_number

    @order_number.setter
    def order_number(self, order_number: int):
        self.__order_number = order_number

    @property
    def bread_type(self) -> str:
        return self.__bread_type

    @bread_type.setter
    def bread_type(self, bread_type: str):
        self.__bread_type = bread_type

    @property
    def meat_type(self) -> str:
        return self.__meat_type

    @meat_type.setter
    def meat_type(self, meat_type: str):
        self.__meat_type = meat_type

    @property
    def toppings(self) -> list:
        return self.__toppings

    @toppings.setter
    def toppings(self, toppings: list):
        self.__toppings = toppings

    def add_topping(self, topping: str):
        self.__toppings.append(topping)

    def remove_topping(self, topping: str):
        if topping in self.__toppings:
            self.__toppings.remove(topping)

    def price(self) -> float:
        price = 3.75
        price += len(self.__toppings) * 0.50
        return price

    def info(self) -> str:
        return (f"Order Number: {self.__order_number:.>50}\nBread Type: {self.__bread_type:.>50}\n"
                f"Meat Type: {self.__meat_type:.>50}\nToppings: {', '.join(self.__toppings):.>50}\n"
                f"Price: ${self.price():.>50.2f}")


class Meal(Sandwich):
    def __init__(self, order_number: int, bread_type: str, meat_type: str, drink: str, side: str):
        super().__init__(order_number, bread_type, meat_type)
        self.__drink = drink
        self.__side = side

    @property
    def drink(self) -> str:
        return self.__drink

    @drink.setter
    def drink(self, drink: str):
        self.__drink = drink

    @property
    def side(self) -> str:
        return self.__side

    @side.setter
    def side(self, side: str):
        self.__side = side

    def price(self) -> float:
        price = super().price() + 3.00
        return price

    def info(self) -> str:
        return (f"Order Number: {self.order_number:.>50}\nBread Type: {self.bread_type:.>50}\n"
                f"Meat Type: {self.meat_type:.>50}\nToppings: {', '.join(self.toppings):.>50}\n"
                f"Drink: {self.__drink:.>50}\nSide: {self.__side:.>50}\nPrice: ${self.price():.>50.2f}")


class KidsMeal(Meal):
    def __init__(self, order_number: int, bread_type: str, meat_type: str, drink: str, side: str, toy: str):
        super().__init__(order_number, bread_type, meat_type, drink, side)
        self.__toy = toy

    @property
    def toy(self) -> str:
        return self.__toy

    @toy.setter
    def toy(self, toy: str):
        self.__toy = toy

    def price(self) -> float:
        price_adjustment = len(self.toppings) * 0.20
        price = (super().price() - price_adjustment) - 2.00
        return price

    def info(self) -> str:
        return (f"{'Welcome to The Python Cafe!':^65}\n{f'Order Number: {self.order_number}':^65}\n\n{'Recept':*^65}\n"
                f"{f'Kids Meal':.^35}\n{f'Sandwich':.<35}\nBread: {self.bread_type}\nMeat: {self.meat_type}\n"
                f"Toppings: {', '.join(self.toppings)}\n{f'Drink':.<35}\n{self.drink}\n{f'Side':.<35}\n{self.side}\n"
                f"{f'Toy':.<35}\n{self.__toy}\n{f'Price':.<35}\n${self.price():.2f}\n"
                f"{'Thank you!':^65}\n{'Come again!':^65}")


# Test Sandwich

S1 = Sandwich(1, "Wheat", "Turkey")
S1.add_topping("Lettuce")
S1.add_topping("Tomato")
S1.add_topping("Mayo")
S1.add_topping("Cheese")
S1.add_topping("Pickles")

print(S1.info())
print('\n')

M1 = Meal(45, "White", "Turkey", "Coke", "Chips")
M1.add_topping("Lettuce")
M1.add_topping("Tomato")
M1.add_topping("Mayo")
M1.add_topping("Cheese")
M1.add_topping("Pickles")

print(M1.info())
print('\n')

K1 = KidsMeal(100, "White", "Turkey", "Sprite", "Fries", "Bennie Baby")
K1.add_topping("Lettuce")
K1.add_topping("Tomato")
K1.add_topping("Mayo")
K1.add_topping("Cheese")
K1.add_topping("Pickles")

print(K1.info())

import random


class Potion:
    def __init__(self, ingredient_1: str, ingredient_2: str):
        # The constructor (__init__) is called when a new instance of Potion is created.
        # It initializes each potion with two ingredients, which are passed as string arguments.
        # These ingredients are stored in instance variables for use in other methods.

        self.ingredient_1 = ingredient_1
        self.ingredient_2 = ingredient_2

    def get_name(self):
        # This method determines the name of the potion based on the combination of ingredients.
        # potion_names: A dictionary mapping frozensets of ingredients to potion names.
        # The use of frozenset allows for the order of ingredients to be ignored, ensuring
        # that the potion can be identified regardless of the order the ingredients are provided.
        # For example, both combinations ("Vampire's Breath", "Witch's Tongue") and
        # ("Witch's Tongue", "Vampire's Breath") map to the same potion name because the
        # frozenset of these ingredients is the same.

        potion_names = {
            frozenset(["Vampire's Breath", "Witch's Tongue"]): "Elixir of Halitosis",
            frozenset(["Toe of Frog", "Eye of Newt"]): "Philter of Amphibiosity",
            frozenset(["Adder's Fork", "Elephant's Proboscis"]): "Draught of Eavesdropping",
            frozenset(["Milk", "Marinara Sauce"]): "Potion of Regret"
        }

        # Check if the frozenset of the provided ingredients exists as a key in the potion_names dictionary.
        # If it does, return the corresponding potion name; otherwise, return "Failed Decoction".
        key = frozenset([self.ingredient_1, self.ingredient_2])
        if key in potion_names:
            return potion_names[key]
        else:
            return "Failed Decoction"

    def get_value(self):
        # This method determines the value of the potion based on its name.
        # potion_values: A dictionary mapping potion names to their values.
        # The values are generated dynamically for some potions using the random.randint function
        # to introduce variability in the potion's value. The value for "Failed Decoction" is
        # statically set to 1, reflecting its minimal worth.

        potion_values = {
            "Elixir of Halitosis": random.randint(10, 50),
            "Philter of Amphibiosity": random.randint(750, 1000),
            "Draught of Eavesdropping": random.randint(500, 750),
            "Potion of Regret": random.randint(2, 40),
            "Failed Decoction": 1
        }

        # Return the value of the potion based on its name. The name is obtained by calling
        # the get_name method. This demonstrates method chaining and the use of a method's
        # return value within another method of the same class.

        return potion_values[self.get_name()]

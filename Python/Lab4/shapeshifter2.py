
class Shapeshifter:
    def __init__(self, form: str):
        if form in ['Human' , 'Wolf', 'Crow']:
            self.__form = form
        else:
            raise Exception("Invalid input. Form must be 'Human' , 'Wolf' , or 'Crow'")

    @property
    def form(self):
        if self.__form in ['Human', 'Wolf', 'Crow']:
            return self.__form
        else:
            raise Exception("Invalid form detected. Please ensure form is 'Human' , 'Wolf' , or 'Crow' ")

    @form.setter
    def form(self, form: str):
        if form in ['Human', 'Wolf', 'Crow']:
            self.__form = form
        else:
            raise Exception("Invalid input. Form must be 'Human' , 'Wolf' , or 'Crow'")

    @property
    def speak(self):
        if self.__form == 'Human':
            return 'Hello'
        elif self.__form == 'Wolf':
            return 'Howl'
        elif self.__form == 'Crow':
            return 'Caw'
        else:
            raise Exception ("Invalid form detected. Please ensure form is 'Human' , 'Wolf' , or 'Crow' ")

    @property
    def arms(self):
        if self.__form == 'Human':
            return 2
        elif self.__form == 'Wolf':
            return 0
        elif self.__form == 'Crow':
            return 0
        else:
            raise Exception ("Invalid form detected. Please ensure form is 'Human' , 'Wolf' , or 'Crow' ")

    @property
    def legs(self):
        if self.__form == 'Human':
            return 2
        elif self.__form == 'Wolf':
            return 4
        elif self.__form == 'Crow':
            return 2
        else:
            raise Exception ("Invalid form detected. Please ensure form is 'Human' , 'Wolf' , or 'Crow' ")

    @property
    def wings(self):
        if self.__form == 'Human':
            return 0
        elif self.__form == 'Wolf':
            return 0
        elif self.__form == 'Crow':
            return 2
        else:
            raise Exception ("Invalid form detected. Please ensure form is 'Human' , 'Wolf' , or 'Crow' ")

    @property
    def tail(self):
        if self.__form == 'Human':
            return False
        elif self.__form == 'Wolf':
            return True
        elif self.__form == 'Crow':
            return True
        else:
            raise Exception ("Invalid form detected. Please ensure form is 'Human' , 'Wolf' , or 'Crow' ")

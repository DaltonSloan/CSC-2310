class Shapeshifter:
    def __init__(self, form: str):
        if form in {'Human', 'Wolf', 'Crow'}:
            self.__form = form
        else:
            raise Exception("Invalid input. Form must be 'Human', 'Wolf', or 'Crow'.")

    @property
    def speak(self):
        if self.form == 'Human':
            return 'Hello'
        elif self.form == 'Wolf':
            return 'Howl'
        elif self.form == 'Crow':
            return 'Caw'
        else:
            raise Exception('Error. Invalid form.')

    def arms(self):
        if self.form == 'Human':
            return 2
        elif self.form == 'Wolf':
            return 0
        elif self.form == 'Crow':
            return 0
        else:
            raise Exception('Error. Invalid form.')

    def legs(self):
        if self.form == 'Human':
            return 2
        elif self.form == 'Wolf':
            return 4
        elif self.form == 'Crow':
            return 2
        else:
            raise Exception('Error. Invalid form.')

    def wings(self):
        if self.form == 'Human':
            return 0
        elif self.form == 'Wolf':
            return 0
        elif self.form == 'Crow':
            return 2
        else:
            raise Exception('Error. Invalid form.')

    def tail(self):
        if self.form == 'Human':
            return False
        elif self.form == 'Wolf':
            return True
        elif self.form == 'Crow':
            return True
        else:
            raise Exception('Error. Invalid form.')

    @property
    def form(self):
        if self.__form == ['Human', 'Wolf', 'Crow']:
            return self.__form
        else:
            raise Exception('Error. Invalid form.')

    @form.setter
    def form(self, form):
        if form in ['Human', 'Wolf', 'Crow']:
            self.__form = form
        else:
            raise Exception('Error. Invalid form.')

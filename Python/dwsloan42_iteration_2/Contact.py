class Contact:
    def __init__(self, contact_list: dict):
        self.__uid = contact_list.get('UID', -1)

        self.__firstname = contact_list.get('FirstName', 'N/A')

        self.__lastname = contact_list.get('LastName', 'N/A')

        self.__email = contact_list.get('Email', 'N/A')

        self.__department = contact_list.get('Dept', 'N/A')

        self.__title = contact_list.get('Title', 'N/A')

        self.__phone = contact_list.get('Phone', 'N/A')

        self.__building = contact_list.get('Building', 'N/A')

        self.__mail_code = contact_list.get('MailCode', 'N/A')

        self.__last_contact = ""

    @property
    def uid(self) -> int:
        return self.__uid

    @property
    def firstname(self) -> str:
        return self.__firstname

    @property
    def lastname(self) -> str:
        return self.__lastname

    @property
    def email(self) -> str:
        return self.__email

    @property
    def department(self) -> str:
        return self.__department

    @property
    def title(self) -> str:
        return self.__title

    @property
    def phone(self) -> str:
        return self.__phone

    @property
    def building(self) -> str:
        return self.__building

    @property
    def mail_code(self) -> str:
        return self.__mail_code

    @property
    def last_contact(self) -> str:
        return self.__last_contact

    @last_contact.setter
    def last_contact(self, last_contact: str):
        self.__last_contact = last_contact

    def __str__(self) -> str:
        """
        Dunder method that defines what happens when you print a Contact object.
        :return: String defining the object
        """
        return f"{self.__firstname} {self.__lastname}\nTitle: {self.__title}\nEmail: {self.__email}\nDepartment: " \
               f"{self.__department}\nPhone: {self.__phone}\nBuilding: {self.__building}\nLDC: {self.__last_contact}"

    def __eq__(self, other: 'Contact') -> bool:  # Using quotes around the type allows for typing of this class here
        """
        Dunder method that defines whether two Contact objects are equal based on their attributes.
        :param other: Another contact object.
        :return: Equality evaluation.
        """
        return self.__uid == other.uid and \
            self.__firstname == other.firstname and \
            self.__lastname == other.lastname and \
            self.__email == other.email and \
            self.__department == other.department and \
            self.__title == other.title and \
            self.__phone == other.phone and \
            self.__building == other.building and \
            self.__mail_code == other.mail_code and \
            self.__last_contact == other.last_contact

import 'dart:io';

class Contact {
  String _mFirstName = "";
  String _mLastName = "";
  String _mNumber = "";
  int _mAge = 0;

  void SetAge(int age) {
    _mAge = age;
  }

  int GetAge() {
    return _mAge;
  }

  void SetLastName(String firstName) {
    _mFirstName = firstName;
  }

  String GetLastName() {
    return _mFirstName;
  }

  void SetFirstName(String lastName) {
    _mLastName = lastName;
  }

  String GetFirstName() {
    return _mLastName;
  }

  String GetFullName() {
    return _mFirstName + " " + _mLastName;
  }

  void SetNumber(String number) {
    _mNumber = number;
  }

  String GetNumber() {
    return _mNumber;
  }

  void PrintContact() {
    print("Name: ${GetFullName()}");
    print("Contact No: ${GetNumber()}");
    print("Age: ${GetAge()}");
  }

  Contact(String firstName, String lastName, String number, int age) {
    _mFirstName = firstName;
    _mLastName = lastName;
    _mNumber = number;
    _mAge = age;
  }
}

void main() {
  List<Contact> contacts = [
    Contact("Kasun", "Dodanwala", "0779287377", 20),
    Contact("Imeth", "Vidunaka", "0769119965", 21),
    Contact("Lakindu", "Godapala", "0773348881", 20)
  ];
  for (int i = 0; i < contacts.length; i++) {
    contacts[i].PrintContact();
    if (i < contacts.length - 1) {
      stdout.write("\n");
    }
  }
}

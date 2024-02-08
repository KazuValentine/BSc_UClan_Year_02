import 'dart:io';

void main() {
  List<int> array = [];
  for (int i = 0; i < 100; i++) {
    array.add(i);
  }
  print("Size: ${array.length}");
  for (int i = 0; i < 100; i++) {
    if (array[i] >= 20 && array[i] <= 80) {
      stdout.write(array[i]);
      stdout.write(", ");
    }
  }
}

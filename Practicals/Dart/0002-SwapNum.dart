void main() {
  int x = 7;
  int y = 3;
  y += x;
  x += y;
  y = x - y;
  x = x - 2 * y;
  print('$x, $y');
}

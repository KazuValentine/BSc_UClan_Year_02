import 'package:flutter/material.dart';
import 'package:project_002/Pages/first_page.dart';
import 'package:project_002/Pages/home_page.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: FirstPage(),
      routes: {
        '/homepage': (context) => const HomePage(),
        // '/secondpage': (context) => const SecondPage(),
        // '/thirdpage': (context) => const ThirdPage(),
        // '/fourthpage': (context) => const FourthPage(),
        // '/fifthpage': (context) => const FifthPage()
      },
    );
  }
}

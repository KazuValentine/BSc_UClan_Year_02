import 'package:flutter/material.dart';
import 'package:project_001/pages/fifth_page.dart';
import 'package:project_001/pages/first_page.dart';
import 'package:project_001/pages/fourth_page.dart';
import 'package:project_001/pages/second_page.dart';
import 'package:project_001/pages/third_page.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: const FirstPage(),
      routes: {
        '/firstpage': (context) => const FirstPage(),
        '/secondpage': (context) => const SecondPage(),
        '/thirdpage': (context) => const ThirdPage(),
        '/fourthpage': (context) => const FourthPage(),
        '/fifthpage': (context) => const FifthPage()
      },
    );
  }
}

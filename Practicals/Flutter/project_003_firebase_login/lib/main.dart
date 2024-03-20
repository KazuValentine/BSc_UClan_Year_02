import 'package:firebase_core/firebase_core.dart';
import 'package:flutter/material.dart';
import 'package:project_003_firebase_login/screens/login_screen.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await Firebase.initializeApp();
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: const LoginScreen(),
      routes: {
        '/loginscreen': (context) => const LoginScreen(),
        // '/secondpage': (context) => const SecondPage(),
        // '/thirdpage': (context) => const ThirdPage(),
        // '/fourthpage': (context) => const FourthPage(),
        // '/fifthpage': (context) => const FifthPage()
      },
    );
  }
}

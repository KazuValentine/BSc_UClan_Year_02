import 'package:flutter/material.dart';
import 'package:project_002/Pages/home_page.dart';
import 'package:project_002/Pages/profile_page.dart';
import 'package:project_002/Pages/setting_page.dart';

class FirstPage extends StatefulWidget {
  const FirstPage({super.key});

  @override
  State<FirstPage> createState() => _FirstPageState();
}

class _FirstPageState extends State<FirstPage> {
  int _selectedIndex = 0;
  void _navigateBottomBar(int index) {
    setState(() {
      _selectedIndex = index;
    });
  }

  final List _pages = [
    const HomePage(),
    const ProfilePage(),
    const SettingsPage()
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Seggs"),
      ),
      body: _pages[_selectedIndex],
      bottomNavigationBar: BottomNavigationBar(
        currentIndex: _selectedIndex,
        onTap: _navigateBottomBar,
        items: const [
          //home
          BottomNavigationBarItem(icon: Icon(Icons.home), label: "HOME"),

          //profile
          BottomNavigationBarItem(icon: Icon(Icons.person), label: "PROFILE"),

          //settings
          BottomNavigationBarItem(icon: Icon(Icons.settings), label: "SETTINGS")
        ],
      ),
    );
  }
}

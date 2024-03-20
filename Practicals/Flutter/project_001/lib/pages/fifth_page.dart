import 'package:flutter/material.dart';

class FifthPage extends StatelessWidget {
  const FifthPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: const Color.fromARGB(255, 33, 229, 243),
        title: const Text("5th page"),
        centerTitle: true,
      ),
      drawer: Drawer(
        child: ListView(
          padding: EdgeInsets.zero,
          children: [
            const DrawerHeader(
              decoration: BoxDecoration(
                color: Colors.blue,
              ),
              child: Center(
                child: Text(
                  'Menu',
                  style: TextStyle(
                    color: Colors.white,
                    fontSize: 24,
                  ),
                ),
              ),
            ),
            ListTile(
              title: const Text('First Page'),
              onTap: () {
                Navigator.pop(context);
                Navigator.pushNamed(context, '/firstpage');
              },
            ),
            ListTile(
              title: const Text('Second Page'),
              onTap: () {
                Navigator.pop(context);
                Navigator.pushNamed(context, '/secondpage');
              },
            ),
            ListTile(
              title: const Text('Third Page'),
              onTap: () {
                Navigator.pop(context);
                Navigator.pushNamed(context, '/thirdpage');
              },
            ),
            ListTile(
              title: const Text('Fourth Page'),
              onTap: () {
                Navigator.pop(context);
                Navigator.pushNamed(context, '/fourthpage');
              },
            ),
          ],
        ),
      ),
      body: Center(
        child: ElevatedButton(
          style: ElevatedButton.styleFrom(
            backgroundColor: Colors.green,
            minimumSize: const Size(150, 50),
          ),
          onPressed: () {
            Navigator.pushNamed(context, '/firstpage');
          },
          child: const Text("Go to first page"),
        ),
      ),
    );
  }
}

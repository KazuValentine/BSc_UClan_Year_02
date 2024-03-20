import 'package:flutter/material.dart';

class FirstPage extends StatelessWidget {
  const FirstPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: const Color.fromARGB(255, 33, 229, 243),
        title: const Text("1st page"),
        centerTitle: true,
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            _buildSquare(const Color.fromARGB(255, 252, 38, 38)),
            ElevatedButton(
              style: ElevatedButton.styleFrom(
                backgroundColor: const Color.fromARGB(255, 247, 243, 18),
                minimumSize: const Size(150, 50),
              ),
              onPressed: () {
                Navigator.pushNamed(context, '/secondpage');
              },
              child: const Text("Go to next page"),
            ),
            _buildSquare(const Color.fromARGB(255, 218, 243, 31)),
            Expanded(
              flex: 2,
              child: _buildSquare(const Color.fromARGB(255, 64, 220, 16)),
            )
          ],
        ),
      ),
    );
  }

  Widget _buildSquare(Color deColor) {
    return Container(
      width: 100,
      height: 100,
      color: deColor,
    );
  }
}

import 'package:flutter/material.dart';

class SecondPage extends StatelessWidget {
  const SecondPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: const Color.fromARGB(255, 33, 229, 243),
        title: const Text("2nd page"),
        centerTitle: true,
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            ElevatedButton(
              style: ElevatedButton.styleFrom(
                backgroundColor: const Color.fromARGB(255, 18, 247, 26),
                minimumSize: const Size(150, 50),
              ),
              onPressed: () {
                Navigator.pushNamed(context, '/thirdpage');
              },
              child: const Text("Go to next page"),
            ),
            const SizedBox(
                height: 20), // Add spacing between button and squares
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                _buildSquare(Colors.red),
                _buildSquare(Colors.green),
                _buildSquare(Colors.blue),
              ],
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                _buildSquare(Colors.yellow),
                _buildSquare(Colors.orange),
                _buildSquare(Colors.purple),
              ],
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                _buildSquare(Colors.teal),
                _buildSquare(Colors.pink),
                _buildSquare(Colors.indigo),
              ],
            ),
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

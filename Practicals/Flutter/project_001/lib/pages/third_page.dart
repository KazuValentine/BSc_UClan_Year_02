import 'package:flutter/material.dart';

class ThirdPage extends StatelessWidget {
  const ThirdPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: const Color.fromARGB(255, 33, 229, 243),
        title: const Text("3rd page"),
        centerTitle: true,
      ),
      body: Column(
        children: [
          Expanded(
            child: ListView.builder(
              itemCount: 10, // Number of rows
              itemBuilder: (context, index) {
                return _buildRow();
              },
            ),
          ),
          ElevatedButton(
            style: ElevatedButton.styleFrom(
              backgroundColor: const Color.fromARGB(255, 247, 18, 18),
              minimumSize: const Size(150, 50),
            ),
            onPressed: () {
              Navigator.pushNamed(context, '/fourthpage');
            },
            child: const Text("Go to next page"),
          ),
        ],
      ),
    );
  }

  Widget _buildRow() {
    return SizedBox(
      height: 120,
      child: ListView.builder(
        scrollDirection: Axis.horizontal,
        itemCount: 7, // Number of squares in each row
        itemBuilder: (context, index) {
          return Container(
            width: 120,
            height: 120,
            margin: const EdgeInsets.all(5),
            color: _getSquareColor(index),
          );
        },
      ),
    );
  }

  Color _getSquareColor(int index) {
    // Example function to return different colors based on index
    // You can customize this function as needed
    switch (index % 3) {
      case 0:
        return Colors.blue;
      case 1:
        return Colors.green;
      case 2:
        return Colors.red;
      default:
        return Colors.blue;
    }
  }
}

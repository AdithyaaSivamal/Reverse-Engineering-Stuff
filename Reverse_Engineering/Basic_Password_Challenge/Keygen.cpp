/*

Properly functioning keygen for 'Basic.exe'
*/


#pragma encoding "UTF-8"
#include <iostream>
#include <string>
#include <cstdint>

void generatePassword(const std::string& username) {
  uint64_t checksum = 0;

  // Loop through each 8-character block
  for (size_t i = 0; i < username.length(); i += 8) {
    uint64_t blockSum = 0;
    std::string block = username.substr(i, 8);

    // Process the block (8 characters or less)
    for (char c : block) {
      blockSum += static_cast<uint64_t>(c);
    }

    // Include the newline character (similar to Python)
    blockSum += '\n';

    // Update checksum (considering potential partial blocks)
    checksum ^= blockSum; // Bitwise XOR for a more even distribution
  }

  std::cout << "Generated Password: " << checksum << std::endl;
}


int main() {
    std::string username;
    std::cout << "Enter username: ";
    std::getline(std::cin, username);

    generatePassword(username);

    return 0;
}

/*
The code below was the first attempt to recreating the challenge's keygen, which I did through transcribing the c code line by line.
Although it doesn't generate correct keygens, sifting through the code helped uncover what the keygen is actually doing.

A simplified, functional keygen is provided: 'Keygen.cpp'.
*/

#include <iostream>
#include <cstdint>
#include <string>
using namespace std;

/**
 * @brief Process user inputs and generate a checksum.
 *
 * This function takes a username as input, processes it to generate a checksum,
 * and updates the checksum parameter accordingly.
 *
 * @param username The username provided by the user.
 * @param checksum A reference to the checksum value that will be updated.
 */
void process_user_inputs(const std::string& username, uint64_t& checksum) {
    // Initialize variables
    uint64_t index = 0; // Index for iterating over the username
    uint64_t length = username.length(); // Length of the username
    uint8_t* username_ptr = reinterpret_cast<uint8_t*>(const_cast<char*>(username.c_str())); // Pointer to the username string
    uint64_t buffer_address = reinterpret_cast<uint64_t>(username_ptr); // Address of the username buffer
    uint64_t buffer_length = length; // Length of the username buffer
    uint64_t sum_ascii[4] = {0}; // Array to store intermediate sums
    uint64_t ascii_sum = 0; // Final checksum value

    // Display initial values
    cout << endl;
    std::cout << "\033[1;34m" << "---Processing Values---" << "\033[0m" << std::endl;
    cout << "Username: " << username << endl;
    cout << "Checksum: " << checksum << endl;
    cout << "Length: " << length << endl;
    cout << "Username pointer: " << username_ptr << endl;

    // Loop for transformation
    if ((length != 0) && (7 < length)) {
        // Iterating over 8-character blocks in the username
        do {
            uint64_t current_username = *reinterpret_cast<uint64_t*>(username_ptr); // Current 8-character block
            index = index + 8; // Move index to the next block
            // Extracting bytes from the current block and performing transformations
            uint64_t sum1 = static_cast<int>((current_username & 0xFF) >> 8);
            uint64_t sum2 = static_cast<int>(((current_username >> 0x18) & 0xFF) << 8);
            uint64_t sum3 = static_cast<int>((current_username >> 0x18) & 0xFF);
            uint64_t sum4 = static_cast<int>((current_username >> 0x18) & 0xFF);
            // Accumulating sums
            ascii_sum += sum1 + sum2 + sum3 + sum4;
        } while (index != (length & 0xFFFFFFFFFFFFFFF8)); // Loop until the end of the username

        // Calculate the final checksum
        ascii_sum = static_cast<uint64_t>(static_cast<uint32_t>(ascii_sum));
    }

    // Perform additional transformations on each character of the username
    for (; *username_ptr != '\0'; ++username_ptr) {
        checksum = static_cast<uint64_t>(static_cast<int>(ascii_sum) + static_cast<int>(*username_ptr));
        ascii_sum = static_cast<uint64_t>(checksum);
    }

    // Display final values
    cout << endl;
    std::cout << "\033[1;34m" << "---Final Values---" << "\033[0m" << std::endl;
    cout << "Checksum: " << checksum << endl;
    cout << "Buffer Address: " << buffer_address << endl;
    cout << "Buffer Length: " << buffer_length << endl;
    cout << "Sum ASCII: " << sum_ascii << endl;
    cout << "ASCII Sum: " << ascii_sum << endl;

    cout << endl;
}

/**
 * @brief Main function to input username and password, and verify the password.
 *
 * This function prompts the user to input a username and a password. It then
 * processes the username to generate a checksum and compares it with the password
 * to determine if it's correct or not.
 *
 * @return Returns 0 upon successful completion.
 */
int main() {
    // Input username and password
    std::string username;
    std::cout << "Enter username: ";
    std::getline(std::cin, username);

    std::string password_str;
    std::cout << "Enter password: ";
    std::getline(std::cin, password_str); // Read the password as a string

    // Calculate checksum for the username
    uint64_t checksum = 0;
    process_user_inputs(username, checksum);

    // Compare the checksum with the password and print the outcome
    std::string outcome = (std::to_string(checksum) == password_str) ? "Correct Password!\n" : "Bad\n";
    std::cout << outcome;

    return 0;
}

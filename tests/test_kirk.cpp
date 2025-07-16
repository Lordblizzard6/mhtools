#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "kirk_cypher.h"
#include <fstream>
#include <vector>

TEST_CASE("Kirk Cypher Encryption/Decryption", "[kirk]") {
    // Create a dummy file with some data
    std::ofstream outfile("test.bin", std::ios::binary);
    std::vector<char> data(1024, 'A');
    outfile.write(data.data(), data.size());
    outfile.close();

    KirkCypher cypher;

    // Encrypt the file
    cypher.encrypt("test.bin");

    // Decrypt the file
    cypher.decrypt("test.bin");

    // Verify the decrypted content
    std::ifstream infile("test.bin", std::ios::binary);
    std::vector<char> decrypted_data((std::istreambuf_iterator<char>(infile)),
                                     std::istreambuf_iterator<char>());
    infile.close();

    REQUIRE(data == decrypted_data);
}

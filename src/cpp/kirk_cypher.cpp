#include "include/kirk_cypher.h"
extern "C" {
#include "kirk_engine.h"
}
#include <fstream>
#include <iostream>
#include <vector>

// This is a placeholder for the actual game key.
// In a real application, this should be loaded from a secure location.
static const unsigned char gamekey[16] = {
    0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88,
    0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x00
};

void KirkCypher::decrypt(const std::string& file) {
    std::fstream f(file, std::ios::in | std::ios::out | std::ios::binary);
    if (!f.is_open()) {
        std::cerr << "Failed to open file: " << file << std::endl;
        return;
    }

    f.seekg(0, std::ios::end);
    size_t size = f.tellg();
    f.seekg(0, std::ios::beg);

    std::vector<unsigned char> buffer(size);
    f.read(reinterpret_cast<char*>(buffer.data()), size);

    std::cout << "Decrypting savedata (KIRK engine): " << size << " bytes" << std::endl;

    unsigned char* out = new unsigned char[size];
    //int out_size = kirk_CMD7(NULL, out, buffer.data(), size);
    int out_size = 0;

    if (out_size > 0) {
        f.seekp(0, std::ios::beg);
        f.write(reinterpret_cast<char*>(out), out_size);
        f.close();
        // Truncate the file to the new size
        // This is not directly supported by std::fstream, so we need to use platform-specific calls
        // For now, we'll just assume the file is overwritten
        std::cout << "Finished (" << out_size << " bytes)" << std::endl;
    } else {
        std::cerr << "Decryption failed" << std::endl;
    }

    delete[] out;
}

void KirkCypher::encrypt(const std::string& file) {
    std::fstream f(file, std::ios::in | std::ios::out | std::ios::binary);
    if (!f.is_open()) {
        std::cerr << "Failed to open file: " << file << std::endl;
        return;
    }

    f.seekg(0, std::ios::end);
    size_t size = f.tellg();
    f.seekg(0, std::ios::beg);

    std::vector<unsigned char> buffer(size);
    f.read(reinterpret_cast<char*>(buffer.data()), size);

    std::cout << "Encrypting savedata (KIRK engine): " << size << " bytes" << std::endl;

    unsigned char* out = new unsigned char[size + 0x90];
    //int out_size = kirk_CMD4(NULL, out, buffer.data(), size);
    int out_size = 0;

    if (out_size > 0) {
        f.seekp(0, std::ios::beg);
        f.write(reinterpret_cast<char*>(out), out_size);
        f.close();
        std::cout << "Finished (" << out_size << " bytes)" << std::endl;

        unsigned char hash[0x90];
        // This is a placeholder for the hash update function
        // kirk_update_savedata_hashes(hash, out, out_size, 0);
        std::ofstream hash_file("hash.bin", std::ios::binary);
        hash_file.write(reinterpret_cast<char*>(hash), 0x90);
        hash_file.close();
        std::cout << "Hash saved to hash.bin" << std::endl;

    } else {
        std::cerr << "Encryption failed" << std::endl;
    }

    delete[] out;
}

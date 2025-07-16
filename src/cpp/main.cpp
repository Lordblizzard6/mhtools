#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sys/stat.h>

void extract(const std::string& filename, const std::string& decoder) {
    // TODO: Implement extraction logic
}

void rebuild(const std::string& filename, const std::string& encoder) {
    // TODO: Implement rebuild logic
}

void createPatch(const std::vector<std::string>& args) {
    // TODO: Implement patch creation logic
}

std::string checkFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return "";
    }
    std::string line;
    std::getline(file, line);
    return line.substr(0, line.find(' '));
}

int main(int argc, char* argv[]) {
    std::cout << "mhtools v2.0 - MHP2G/MHFU/MHP3 utils" << std::endl << std::endl;

    if (argc < 2) {
        std::cerr << "Usage: mhtools --extract <path to xxxx.bin> <decoder number>" << std::endl;
        std::cerr << "       mhtools --rebuild <path to project folder> <encoder number>" << std::endl;
        std::cerr << "       mhtools --decrypt <path to xxxx.bin>" << std::endl;
        std::cerr << "       mhtools --encrypt <path to xxxx.bin>" << std::endl;
        std::cerr << "       mhtools --dec-ext <path to xxxx.bin> <decoder number>" << std::endl;
        std::cerr << "       mhtools --reb-enc <path to project folder> <encoder number>" << std::endl;
        std::cerr << "       mhtools --gen-index <data.bin>" << std::endl;
        std::cerr << "       mhtools --dec-all <data.bin> <path to output folder>" << std::endl;
        std::cerr << "       mhtools --create-patch <xxxx.bin.enc> [ ... <xxxx.bin.enc>] <output_file>" << std::endl;
        std::cerr << "       mhtools --decrypt-quest <mxxxxx.mib>" << std::endl;
        std::cerr << "       mhtools --encrypt-quest <mxxxxx.mib>" << std::endl;
        std::cerr << "       mhtools --extract-quests <xxxxxx.bin>" << std::endl;
        std::cerr << "       mhtools --update-sha1 <mxxxxx.mib>" << std::endl;
        std::cerr << "       mhtools --decrypt-save <xxxxx.bin>" << std::endl;
        std::cerr << "       mhtools --encrypt-save <xxxxx.bin>" << std::endl;
        std::cerr << "       mhtools --decrypt-kirk <xxxxx.bin>" << std::endl;
        std::cerr << "       mhtools --encrypt-kirk <xxxxx.bin>" << std::endl;
        return 1;
    }

    std::string option = argv[1];
    if (option == "--extract") {
        if (argc < 4) {
            std::cerr << "Decoder number missing. Aborting" << std::endl;
            return 1;
        }
        extract(argv[2], argv[3]);
    } else if (option == "--rebuild") {
        if (argc < 4) {
            std::cerr << "Encoder number missing. Aborting" << std::endl;
            return 1;
        }
        rebuild(argv[2], argv[3]);
    } else if (option == "--decrypt") {
        // TODO: Implement decrypt
    } else if (option == "--encrypt") {
        // TODO: Implement encrypt
    } else if (option == "--dec-ext") {
        if (argc < 4) {
            std::cerr << "Decoder number missing. Aborting" << std::endl;
            return 1;
        }
        // TODO: Implement dec-ext
    } else if (option == "--reb-enc") {
        if (argc < 4) {
            std::cerr << "Encoder number missing. Aborting" << std::endl;
            return 1;
        }
        // TODO: Implement reb-enc
    } else if (option == "--gen-index") {
        // TODO: Implement gen-index
    } else if (option == "--dec-all") {
        if (argc < 4) {
            std::cerr << "Output folder missing. Aborting" << std::endl;
            return 1;
        }
        // TODO: Implement dec-all
    } else if (option == "--create-patch") {
        // TODO: Implement create-patch
    } else if (option == "--encrypt-quest") {
        // TODO: Implement encrypt-quest
    } else if (option == "--decrypt-quest") {
        // TODO: Implement decrypt-quest
    } else if (option == "--extract-quests") {
        // TODO: Implement extract-quests
    } else if (option == "--update-sha1") {
        // TODO: Implement update-sha1
    } else if (option == "--encrypt-save") {
        // TODO: Implement encrypt-save
    } else if (option == "--decrypt-save") {
        // TODO: Implement decrypt-save
    } else if (option == "--encrypt-kirk") {
        // TODO: Implement encrypt-kirk
    } else if (option == "--decrypt-kirk") {
        // TODO: Implement decrypt-kirk
    } else {
        std::cerr << "Unknown parameter: " << option << std::endl;
        return 1;
    }

    return 0;
}

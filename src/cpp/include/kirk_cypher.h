#ifndef KIRK_CYPHER_H
#define KIRK_CYPHER_H

#include <string>
#include <vector>

class KirkCypher {
public:
    void decrypt(const std::string& file);
    void encrypt(const std::string& file);
};

#endif // KIRK_CYPHER_H

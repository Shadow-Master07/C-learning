#include <iostream>
#include <string>
#include <fstream>

void readBinary(const std::string &fileName)
{
    std::ifstream var(fileName, std::ios::binary);

    if (!var.is_open())
    {
        std::cerr << "File did not open correctly" << std::endl;
        return;
    }

    // Read the size of the string
    size_t data;
    var.read(reinterpret_cast<char *>(&data), sizeof(data));

    // Allocate memory for the string and read it
    std::string dataToRead(data, '\0');
    var.read(&dataToRead[0], data);

    std::cout << "Read from binary file: " << std::endl
              << dataToRead << std::endl;
    var.close();
}

void writeBinary(const std::string &fileName, const std::string &data)
{
    std::ofstream var(fileName, std::ios::binary);

    if (!var.is_open())
    {
        std::cerr << "File did not open correctly" << std::endl;
        return;
    }

    // Write the size of the string first
    size_t size = data.size();
    var.write(reinterpret_cast<const char *>(&size), sizeof(size));

    // Write the string data
    var.write(data.data(), size);
    var.close();
}

void readFile(const std::string &fileName)
{
    std::ifstream var(fileName);

    if (!var.is_open())
    {
        std::cerr << "File did not open correctly" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(var, line))
    {
        std::cout << line << std::endl;
    }
}

void writeFile(const std::string &fileName, const std::string &data)
{
    std::ofstream var(fileName);

    if (!var.is_open())
    {
        std::cerr << "File did not open correctly" << std::endl;
        return;
    }

    var << data;
}

int main()
{
    std::string bin = ".bin", txt = ".txt";
    std::string location = "./poem/newPoem";
    std::string data = "Kyu darte ho mujhse\nMain to tum hi hun\n";

    writeBinary(location + bin, data);
    readBinary(location + bin);

    std::cout << "This is now txt file" << std::endl;
    writeFile(location + txt, data);
    readFile(location + txt);

    return 0;
}

#ifndef ENCODE_H_
#define ENCODE_H_

#include <string>
#include <regex>

inline std::string decodeURIComponent(const std::string& encoded) {

    std::string decoded = encoded;
    std::smatch sm;

    int dynamicLength = decoded.size() - 2;

    if (decoded.size() < 3) return decoded;

    for (int i = 0; i < dynamicLength; i++)
    {

        std::string haystack = decoded.substr(i, 3);

        if (std::regex_match(haystack, sm, std::regex("%[0-9A-F]{2}")))
        {
            haystack = haystack.replace(0, 1, "0x");
            std::string rc = {(char)std::stoi(haystack, nullptr, 16)};
            decoded = decoded.replace(decoded.begin() + i, decoded.begin() + i + 3, rc);
        }

        dynamicLength = decoded.size() - 2;

    }

    return decoded;
}

inline std::string encodeURIComponent(const std::string& decoded)
{

    std::ostringstream oss;
    const std::regex r(R"([!'\(\)*\-.0-9A-Za-z_~])");

    for (const char c : decoded)
    {
        if (std::regex_match((std::string){c}, r))
        {
            oss << c;
        }
        else
        {
            oss << "%" << std::uppercase << std::hex << (0xff & c);
        }
    }
    return oss.str();
}

#endif
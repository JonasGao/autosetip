#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <openssl/hmac.h>
#include "encode.h"

struct param {
    std::string name;
    std::string value;
    std::string to_string() const {
        return name + "=" + value;
    }
};

int main() {
    std::vector<param> params = {
        {"Action", "TestApi"},
        {"Version", "v1.0"}
    };
    for (const param& item : params) {
        std::cout << item.to_string() << std::endl;
    }

//   std::sort(params.begin(), params.end());
//
//    std::stringstream ss1;
//    std::stringstream ss2;
//    for (const auto &param: sortedParams) {
//        ss1 << encodeURIComponent(param.first) << "=" << encodeURIComponent(param.second) << "&";
//    }
//    std::string paramStr = ss1.str();
//    paramStr.pop_back(); // 去掉最后一个"&"
//
//    ss2 << "GET&%2F&" << encodeURIComponent(paramStr);
//
//    return ss2.str();
//    std::cout << "Signature: " << signature << std::endl;

    return 0;
}

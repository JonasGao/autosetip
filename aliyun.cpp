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

bool compareParam(const param &a, const param &b) {
    return a.name < b.name;
}

int main() {
    std::vector<param> params = {
        {"Version", "v12.0"},
        {"Action", "Test+Api-Test.Api"},
    };
    std::sort(params.begin(), params.end(), compareParam);
    std::stringstream ss1;
    std::stringstream ss2;
    for (const param &item: params) {
        ss1 << encodeURIComponent(item.name) << "=" << encodeURIComponent(item.value) << "&";
    }
    std::string paramStr = ss1.str();
    // debug log
    std::cout << paramStr << std::endl;
    paramStr.pop_back();
    // debug log
    std::cout << paramStr << std::endl;
    ss2 << "GET&%2F&" << encodeURIComponent(paramStr);
    // debug log
    std::cout << ss2.str() << std::endl;

    //
    //
    //
    //
    //
    //
    //     // 去掉最后一个"&"
    //
    //
    //
    //    return ss2.str();
    //    std::cout << "Signature: " << signature << std::endl;

    return 0;
}

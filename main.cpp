#include <iostream>
#include <curl/curl.h>

size_t writer(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string *) userp)->append((char *) contents, size * nmemb);
    return size * nmemb;
}

bool fetchIp(bool verbose, std::string &readBuffer) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        if (verbose) {
            curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        }
        // https://api.ipify.org cant frequently access.
        curl_easy_setopt(curl, CURLOPT_URL, "https://ips.im/api");
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return false;
        }
        curl_easy_cleanup(curl);
        return true;
    } else {
        fprintf(stderr, "curl_easy_init() failed.");
        return false;
    }
}

int main(int argc, char *argv[]) {
    bool verbose = false;
    std::string buffer;

    if (argc > 1) {
        char *flag = argv[1];
        if (strcmp(flag, "v") == 0 || strcmp(flag, "verbose") == 0) {
            verbose = true;
        }
    }

    curl_global_init(CURL_GLOBAL_DEFAULT);
    if (fetchIp(verbose, buffer)) {
        std::cout << "IP: " << buffer << std::endl;
    }
    curl_global_cleanup();
    return 0;
}

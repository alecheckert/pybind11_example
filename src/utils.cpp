#include <string>
#include <cstdio>
#include <softmax.h>

#define BUFFER_SIZE 200

template <typename T>
int get_json_item(std::string json, std::string key, T* value) {
    char buffer [BUFFER_SIZE];

    // Pointer to end of string
    const char *end = json.c_str() + json.size();

    // Find the substring
    std::size_t found = json.find(key);
    if (found == std::string::npos)
        return 1;

    // Get a pointer to the part immediately after the substring    
    const char *ptr = json.c_str();
    ptr = ptr + found + key.length();

    // Scan to the first digit
    while ((!isdigit(*ptr)) and (ptr != end))
        ptr++;
    if (ptr == end)
        return 1;

    // Scan to the first nondigit or non-decimal place
    int i = 0;
    while ((isdigit(*ptr) or *ptr == '.') and (ptr != end)) {
        buffer[i] = *ptr;
        i++;
        ptr++;
    }
    buffer[i] = '\0';

    if (ptr == end)
        return 1;

    // Convert to desired type
    *value = (T) std::stof(buffer);
    return 0;
}
template int get_json_item<int>(std::string json, std::string key, int* value);
template int get_json_item<float>(std::string json, std::string key, float* value);

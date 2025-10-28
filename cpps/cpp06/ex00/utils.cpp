#include "utils.hpp"

std::string toLower(const std::string& s) {
    std::string res = "";
for (size_t i = 0; i < s.length(); i++) {
    res += std::tolower(s[i]);
}
    return res;
}

bool isPseudoDouble(const std::string& s) {
    std::string str = s;
    if (!str.empty() && (str[0] == '+' || str[0] == '-'))
        str = str.substr(1);
    str = toLower(str);
    return str == "inf" || str == "nan";
}

bool isPseudoFloat(const std::string& s) {
    if (s.empty() || s[s.length() - 1] != 'f') return false;
    std::string str = s.substr(0, s.length() - 1);
    if (!str.empty() && (str[0] == '+' || str[0] == '-'))
        str = str.substr(1);
    str = toLower(str);
    return str == "inf" || str == "nan";
}
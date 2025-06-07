#include <iostream>
#include <string>
#include <algorithm>

class String {
protected:
    std::string data;

public:
    String() = default;

    explicit String(const std::string& str) : data(str) {}

    String(const String& other) : data(other.data) {}

    String& operator=(const String& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    virtual ~String() = default;

    friend std::ostream& operator<<(std::ostream& os, const String& str) {
        os << str.data;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, String& str) {
        is >> str.data;
        return is;
    }
};

class UpperString : public String {
private:
    static std::string toUpper(const std::string& str) {
        std::string upperStr = str;
        std::transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper);
        return upperStr;
    }

public:
    UpperString() = default;

    explicit UpperString(const std::string& str) : String(toUpper(str)) {}

    UpperString(const UpperString& other) : String(other) {}

    UpperString& operator=(const UpperString& other) {
        if (this != &other) {
            String::operator=(other);
        }
        return *this;
    }

    friend std::istream& operator>>(std::istream& is, UpperString& str) {
        std::string temp;
        is >> temp;
        str.data = toUpper(temp);
        return is;
    }
};

int main() {
    String normalStr;
    UpperString upperStr;

    std::cout << "Enter normal string: ";
    std::cin >> normalStr;

    std::cout << "Enter uppercase string: ";
    std::cin >> upperStr;

    std::cout << "\nNormal String: " << normalStr << std::endl;
    std::cout << "Uppercase String: " << upperStr << std::endl;

    String copyStr = normalStr;
    UpperString copyUpperStr = upperStr;

    std::cout << "\nCopied Normal String: " << copyStr << std::endl;
    std::cout << "Copied Uppercase String: " << copyUpperStr << std::endl;

    return 0;
}

#include <iostream>

class String {
    char *str_ = nullptr;
    size_t size_ = 0;
public:
    String(const char *str = "");

    String &operator=(const String &str_obj);

    String &operator=(String &&str_obj) noexcept;

    String(const String &);

    String(String &&) noexcept;

    String(size_t n, char c);

    void append(const String &other);

    ~String();

    friend std::ostream &operator<<(std::ostream &out, const String &str_obj);

};

String::String(const char *str) {
    size_t i = 0;
    while (str[i] != '\0') ++i;
    size_ = i;
    str_ = new char[size_ + 1];
    str_[size_] = '\0';
    memcpy(str_, str, size_);
}

String::~String()
    delete[] str_;
}

String::String(size_t n, char c) {
    size_ = n;
    str_ = new char[size_ + 1];
    str_[size_] = '\0';
    for (auto i = 0; i < size_; ++i) str_[i] = c;
}

std::ostream &operator<<(std::ostream &out, const String &str_obj) {
    out << str_obj.str_;
    return out;
}

String::String(const String &str_obj) {
    size_ = str_obj.size_;
    str_ = new char[size_ + 1];
    memcpy(str_, str_obj.str_, size_);
    str_[size_] = '\0';
}

String &String::operator=(const String &str_obj) {
    if (this != &str_obj) {
        delete[] str_;
        size_ = str_obj.size_;
        str_ = new char[size_ + 1];
        str_[size_] = '\0';
        memcpy(str_, str_obj.str_, size_);
    }
    return *this;
}

void String::append(const String &other) {
    size_t new_size = size_ + other.size_;
    char *new_str = new char[new_size + 1];
    new_str[new_size] = '\0';
    memcpy(new_str, str_, size_);
    memcpy(new_str + size_, other.str_, other.size_);
    delete str_;
    size_ = new_size;
    str_ = new_str;
    new_str = nullptr;
}

String::String(String &&str_obj) noexcept {
    str_ = str_obj.str_;
    size_ = str_obj.size_;
    str_obj.str_ = nullptr;
}


String &String::operator=(String &&str_obj) noexcept {
    if (this != &str_obj) {
        delete[] str_;
        str_ = str_obj.str_;
        size_ = str_obj.size_;
        str_obj.str_ = nullptr;
    }

    return *this;
}
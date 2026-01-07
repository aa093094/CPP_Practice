#include <iostream>

class string {
    char* str;
    int len;
    int memory_capacity;

    public:
        explicit string(int capacity);
        string(char c);
        string (const char* s);
        string (const string& s);
        ~string();

        int strlen() const;
        string& assign(const string& s);
        string& assign(const char* s);
        int capacity() const;
        void reserve(int size);
        char at(int i) const;
        string& insert(int loc, const string& s);
        string& insert(int loc, const char* s);
        string& insert(int loc, char c);
        string& erase(int loc, int num);
        int find(int find_from, const string& s) const;
        int find(int find_from, const char* s) const;
        int find(int find_from, char c) const;
        void add_string(const string s);
        void copy_string(const string &s);
        void include_string(const string s);
        void equal_string(const string s);
        int compare_string(const string s);
        void print() const;
        void println() const;
};

string::string(char c) {
    str = new char[1];
    len = 1;
    memory_capacity = 1;
    str[0] = c;
}

string::string(int capacity) {
    str = new char[capacity];
    len = 0;
    memory_capacity = capacity;
    std::cout << "Capacity : " << capacity << std::endl;
}

string::string(const char* s) {
    int cnt = 0;

    while (s[cnt] != '\0') {
        cnt++;
    }

    str = new char[cnt];
    for (int i = 0; i < cnt ; i++) {
        str[i] = s[i];
    }

    len = cnt;
    memory_capacity = len;
}

string::string(const string& s) {
    len = s.len;
    str = new char[len];
    for (int i = 0; i < len; i++) {
        str[i] = s.str[i];
    }
    memory_capacity = len;
}

int string::strlen() const{
    return len;
}

string& string::assign(const string& s) {
    if (s.len > memory_capacity) {
        delete[] str;

        str = new char[s.len];
        memory_capacity = s.len;
    }

    for (int i = 0; i < s.len; i++) {
        str[i] = s.str[i];
    }

    len = s.len;

    return *this;
}

string& string::assign(const char* s) {
    int cnt = 0;

    while (s[cnt] != '\0') {
        cnt++;
    }

    if (cnt > memory_capacity) {
        delete[] str;

        str = new char[cnt];
        memory_capacity = cnt;
    }

    for (int i = 0; i < cnt ; i++) {
        str[i] = s[i];
    }

    len = cnt;

    return *this;
}

int string::capacity() const{ return memory_capacity; };

void string::reserve(int size) {
    if (size > memory_capacity) {
        char* prev_str = str;

        str = new char[size];
        memory_capacity = size;

        for (int i = 0; i < len; i++) {
            str[i] = prev_str[i];
        }

        delete[] prev_str;
    }
}

char string::at(int i) const {
    if (i >= len || i < 0) return 0;
    else return str[i];
}

string& string::insert(int loc, const string& s) {
    if (loc < 0 || loc > len) return *this;

    if (len + s.len > memory_capacity) {
        if (memory_capacity * 2 > len + s.len) memory_capacity *= 2;
        else memory_capacity = len + s.len;

        char* prev_str = str;
        str = new char[memory_capacity];

        int i;
        for (i = 0; i < loc; i++) {
            str[i] = prev_str[i];
        }

        for (int j = 0; j < s.len; j++) {
            str[i+j] = s.str[j];
        }

        for (; i < len; i++) {
            str[s.len + i] = prev_str[i];
        }

        delete[] prev_str;

        len = len + s.len;
        return *this;
    }

    for (int i = len - 1; i >= loc; i--) {
        str[i+s.len] = str[i];
    }

    for (int i = 0; i < s.len; i++) {
        str[i+loc] = s.str[i];
    }

    len = len + s.len;
    return *this;
}

string& string::insert(int loc, const char* s) {
    string temp(s);
    return insert(loc, temp);
}

string& string::insert(int loc, char c) {
    string temp(c);
    return insert(loc, temp);
}

string& string::erase(int loc, int num) {
    if (num < 0 || loc < 0 || loc > len) return *this;

    if (loc + num > len) {
        len = loc;
        return *this;
    }
    for (int i = loc + num; i < len; i++) {
        str[i-num] = str[i];
    }

    len -= num;
    return *this;
}

int string::find(int find_from, const string& s) const {
    int i, j;
    if (s.len == 0) return -1;
    for (i = find_from; i <= len - s.len; i++) {
        for (j = 0; j < s.len; j++) {
            if (str[i+j] != s.str[j]) break;
        }

        if (j == s.len) return i;
    }

    return -1;
}

int string::find(int find_from, const char* s) const {
    string temp(s);
    return find(find_from, temp);
}

int string::find(int find_from, char c) const {
    string temp(c);
    return find(find_from, temp);
}

void string::add_string(const string s) {
    char* big_str = new char[len + s.len + 1];

    for (int i = 0; i < len; i++) {
        big_str[i] = str[i];
    }

    for (int j = 0; j < s.len; j++) {
        big_str[j + len] = s.str[j];
    } 

    big_str[len + s.len] = '\0';

    copy_string(big_str);

    delete[] big_str;
}

void string::copy_string(const string &s) {
    if (str) delete[] str;

    str = new char[s.len];
    for (int i = 0; i < s.len; i++) {
        str[i] = s.str[i];
    }
    len = s.len;
}

void string::include_string(const string s) {
    int bp = 1;

    if (len < s.len) {
        for (int i = 0; i < s.len; i++) {
            if (s.str[i] == str[0]) {
                for (int j = 1; j < len; j++) {
                    if (s.str[i + j] != str[j] || s.len <= i + j) {
                        bp = 0;
                        break;
                    }
                    bp = 1;
                }
                if (bp == 1) break;
            }
        }
    } else if (len == s.len) {
        for (int i = 0; i < len; i++) {
            if (str[i] != s.str[i]) {
                bp = 0;
                break;
            }
        }
    } else {
        for (int i = 0; i < len; i++) {
            if (str[i] == s.str[0]) {
                for (int j = 1; j < s.len; j++) {
                    if (str[i + j] != s.str[j] || len <= i + j) {
                        bp = 0;
                        break;
                    }
                    bp = 1;
                }
                if (bp == 1) break;
            }
        }
    }

    if (bp == 1 && len < s.len) {
        std::cout << "s includes string" << std::endl;
    } else if(bp == 1) {
        std::cout << "string includes s" << std::endl;
    } else {
        std::cout << "string not includes s" << std::endl;
    }
}

void string::equal_string (const string s) {
    int bp = 1;

    for (int i = 0; i < len; i++) {
        if (str[i] != s.str[i]) {
            bp = 0;
            break;
        }
    }

    if (bp == 1) {
        std::cout << "s equals string" << std::endl;
    } else {
        std::cout << "s not equals string" << std::endl;
    }
}

int string::compare_string (const string s) {
    int bigger = 0;

    if (len < s.len) {
        for (int i = 0; i < len; i++) {
            if (str[i] != s.str[i]) {
                if (str[i] < s.str[i]) {
                    bigger = -1;
                    break;
                }
                else {
                    bigger = 1;
                    break;
                }
            }
        }
        if (bigger == 0) bigger = -1;
    } else if (len > s.len) {
        for (int i = 0; i < s.len; i++) {
            if (str[i] != s.str[i]) {
                if (str[i] < s.str[i]) {
                    bigger = -1;
                    break;
                }
                else {
                    bigger = 1;
                    break;
                }
            }
        }
        if (bigger == 0) bigger = 1;
    }

    return bigger;
}

void string::print() const {
	for (int i = 0; i != len; i++) {
        std::cout << str[i];
    }
}

void string::println() const {
    for (int i = 0; i != len; i++) {
        std::cout << str[i];
    }
    std::cout << std::endl;
}

string::~string() {
    if (str) delete[] str;
}

int main()
{
    string s1(5);
}

#include <iostream>
#include <string>

//using namespace std;

// iteration over string with auto
void print_string_element_with_auto(std::string& s){

    std::cout << "Iterate like arrays." << std::endl;
    for(size_t i=0; i<s.size(); ++i){
        std::cout << s[i] << "\t";
    }
    std::cout << std::endl;

    std::cout << "Iterate with const auto (after c++11)." << std::endl;
    for(const auto& c:s){
        std::cout << c << "\t";
    }
    std::cout << std::endl;

    std::cout << "Iterate with iterator class." << std::endl;
    for(auto itr = s.begin(); itr != s.end(); ++itr){
        std::cout << *itr << "\t";
    }
    std::cout << std::endl;

    std::cout << "Iterate with const_iterator class." << std::endl;
    for(auto c_itr = s.cbegin(); c_itr != s.cend(); ++c_itr){
        std::cout << *c_itr << "\t";
    }
    std::cout << std::endl;

    std::cout << "Iterate with reverse iterator class." << std::endl;
    for(auto r_itr = s.rbegin(); r_itr != s.rend(); ++r_itr){
        std::cout << *r_itr << "\t";
    }
    std::cout << std::endl;

    std::cout << "Iterate with const reverse iterator class." << std::endl;
    for(auto cr_itr = s.crbegin(); cr_itr != s.crend(); ++cr_itr){
        std::cout << *cr_itr << "\t";
    }
    std::cout << std::endl;
}

// iteration over string without auto
void print_string_element_without_auto(std::string& s){

    std::cout << "Iterate like arrays." << std::endl;
    for(size_t i=0; i<s.size(); ++i){
        std::cout << s[i] << "\t";
    }
    std::cout << std::endl;

    std::cout << "Iterate with const auto (after c++11)." << std::endl;
    for(const auto& c:s){
        std::cout << c << "\t";
    }
    std::cout << std::endl;

    std::cout << "Iterate with iterator class." << std::endl;
    for(std::string::iterator itr = s.begin(); itr != s.end(); ++itr){
        std::cout << *itr << "\t";
    }
    std::cout << std::endl;

    std::cout << "Iterate with const_iterator class." << std::endl;
    for(std::string::const_iterator c_itr = s.cbegin(); c_itr != s.cend(); ++c_itr){
        std::cout << *c_itr << "\t";
    }
    std::cout << std::endl;

    std::cout << "Iterate with reverse iterator class." << std::endl;
    for(std::string::reverse_iterator r_itr = s.rbegin(); r_itr != s.rend(); ++r_itr){
        std::cout << *r_itr << "\t";
    }
    std::cout << std::endl;

    std::cout << "Iterate with const reverse iterator class." << std::endl;
    for(std::string::const_reverse_iterator cr_itr = s.crbegin(); cr_itr != s.crend(); ++cr_itr){
        std::cout << *cr_itr << "\t";
    }
    std::cout << std::endl;
}

//EPI 7.0 checking whether a sting is palindromic or not. Assuming empty string is palindromic.
bool is_palindromic(const std::string& s){
    if(s.size() <= 0) return true; // can be removed, but then j can be negative.

    size_t i=0, j=s.size()-1;
    while(j>=i){
        if(s[i] != s[j]) return false;
        ++i;
        --j;
    }
    return true;
}

//EPI 7.1.1 converting string to int. Assuming string can not be empty and all characters are digits.
int string_to_int(const std::string&s){
    int result = 0, multipy_factor = 1, end_index = 0, start_index = s.size()-1, is_negative = false;
    if(s[0] == '-') {
        end_index = 1;
        is_negative = true;
    }
    while(start_index >= end_index){
        result += (s[start_index]-'0')*multipy_factor;
        multipy_factor *= 10;
        --start_index;
    }
    if(is_negative){
        return (-1)*result;
    }else{
        return result;
    }
}
int main()
{

    //1. string constructors
    std::string s = "hello world!";
    std::cout << s << std::endl;

    std::cout << string_to_int("-3466734") << std::endl;

    return 0;

}

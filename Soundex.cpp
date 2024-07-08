#include "Soundex.h"
#include <string>
#include <cctype>
#include <unordered_map>
 
char Codesget(char c) {
    static const char Codes[] = {
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
    };
 
    c = toupper(c);
    if (c >= 'A' && c <= 'Z') {
        return Codes[c - 'A'];
    }
    return '0';
}
 
char get_firstchar(const std::string& name) {
    if (name.empty()) return '\0';
    return toupper(name[0]);
}
 
void appendSoundexCode(std::string& soundex, char code, char& prevCode) {
    if (code != '0' && code != prevCode) {
        soundex += code;
        prevCode = code;
    }
}
 
std::string SoundexCode_initialize(const std::string& name, char firstChar) {
    std::string soundex(1, firstChar);
    char secondex = Codesget(name[1]);
    if (secondex != '0') {
        soundex += secondex;
    }
    return soundex;
}
 
std::string Soundexcode_process(const std::string& name, char firstChar) {
   std::string soundex = SoundexCode_initialize(name, firstChar);
    char prevCode = soundex[1];
    for (size_t i = 2; i < name.length() && soundex.length() < 4; ++i) 
    {
        char code = Codesget(name[i]);
        appendSoundexCode(soundex, code, prevCode);
    }
 
    return soundex;
}
 
std::string Soundex_padding(const std::string& soundex) {
    std::string padded_Soundex = soundex;
    padded_Soundex.resize(4, '0');
    return padded_Soundex;
}
 
std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";
 
    char firstChar = get_firstchar(name);
    std::string processed_Name = Soundexcode_process(name, firstChar);
    std::string padded_Soundex = Soundex_padding(processed_Name);
 
    return padded_Soundex;
}

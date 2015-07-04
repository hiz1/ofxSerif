//
//  utf8helper.cpp
//  example
//
//  Created by hiz on 2015/07/04.
//
//

#include "utf8helper.h"

unsigned int cntByte(unsigned char cChar)
{
    unsigned int iByte;
    
    if ((cChar >= 0x00) && (cChar <= 0x7f)) {
        iByte = 1;
    } else if ((cChar >= 0xc2) && (cChar <= 0xdf)) {
        iByte = 2;
    } else if ((cChar >= 0xe0) && (cChar <= 0xef)) {
        iByte = 3;
    } else if ((cChar >= 0xf0) && (cChar <= 0xf7)) {
        iByte = 4;
    } else if ((cChar >= 0xf8) && (cChar <= 0xfb)) {
        iByte = 5;
    } else if ((cChar >= 0xfc) && (cChar <= 0xfd)) {
        iByte = 6;
    } else {
        iByte = 0;
    }
    
    return iByte;
}

std::string utf8_substr(const std::string &str, int iStart, int iLength)
{
    const char *cStr = str.c_str();
    
    static char cRes[1024];
    char* pRes = cRes;
    int i = 0, iPos = 0;
    int iByte;
    
    while (cStr[i] != '\0') {
        iByte = cntByte(cStr[i]);
        if (iStart <= iPos && iPos < iStart + iLength) {
            memcpy(pRes, (cStr + i), iByte);
            pRes += iByte;
        }
        i += iByte;
        iPos++;
    }
    *pRes = '\0';
    
    return cRes;
}

unsigned int utf8_strlen(std::string str)
{
    using namespace std;
    
    unsigned int len = 0;
    unsigned char lead;
    int char_size = 0;
    
    for (string::iterator it = str.begin(); it != str.end(); it += char_size) {
        
        lead = *it;
        
        if (lead < 0x80) {
            char_size = 1;
        } else if (lead < 0xE0) {
            char_size = 2;
        } else if (lead < 0xF0) {
            char_size = 3;
        } else {
            char_size = 4;
        }
        
        len += 1;
    }
    
    return len;
}
#include "utf8_handling.hpp"
// Decode one UTF-8 character, pos should point to start of next char after
uint32_t decode_utf8_char(const std::string& str, size_t& pos)
{
    unsigned char c = str[pos];
    
    if ((c & 0x80) == 0)
    {
        pos += 1;
        return c;
    }
    else if ((c & 0xE0) == 0xC0)
    {
        uint32_t result = ((c & 0x1F) << 6) | (str[pos+1] & 0x3F);
        pos += 2;
        return result;
    }
    else if ((c & 0xF0) == 0xE0)
    {
        uint32_t result = ((c & 0x0F) << 12) | 
                         ((str[pos+1] & 0x3F) << 6) | 
                         (str[pos+2] & 0x3F);
        pos += 3;
        return result;
    }
    else if ((c & 0xF8) == 0xF0)
    {
        uint32_t result = ((c & 0x07) << 18) | 
                         ((str[pos+1] & 0x3F) << 12) |
                         ((str[pos+2] & 0x3F) << 6) | 
                         (str[pos+3] & 0x3F);
        pos += 4;
        return result;
    }
    pos += 1;
    return 0;
}

bool is_wide_character(uint32_t c)
{
    // Hiragana
    if (c >= 0x3040 && c <= 0x309F)
    	return true;
    // Katakana
    if (c >= 0x30A0 && c <= 0x30FF)
    	return true;
    // CJK Extension A
    if (c >= 0x3400 && c <= 0x4DBF)
    	return true;
    // CJK Unified Ideographs
    if (c >= 0x4E00 && c <= 0x9FFF)
    	return true;
    // Hangul Syllables
    if (c >= 0xAC00 && c <= 0xD7AF)
    	return true;
    // Fullwidth forms (includes fullwidth ASCII)
    if (c >= 0xFF00 && c <= 0xFFEF)
    	return true;
    // Emoji ranges
    if (c >= 0x1F300 && c <= 0x1F9FF)
    	return true;
    if (c >= 0x1F600 && c <= 0x1F64F)
    	return true;  // Emoticons
    if (c >= 0x1F680 && c <= 0x1F6FF) 
    	return true;  // Transport
    if (c >= 0x2600 && c <= 0x26FF)
    	return true;    // Misc symbols
    if (c >= 0x2700 && c <= 0x27BF)
    	return true;    // Dingbats
    
    return false;
}

int char_display_width(uint32_t c)
{
    return is_wide_character(c) ? 2 : 1;
}

// Calculate total display width
int utf8_display_width(const std::string& str)
{
    int width = 0;
    size_t pos = 0;
    while (pos < str.size())
    {
        uint32_t c = decode_utf8_char(str, pos);
        width += char_display_width(c);
    }
    return width;
}

// Extract substring that fits within max_width display columns
std::string truncate_to_width(const std::string& str, int max_width)
{
    int current_width = 0;
    size_t byte_pos = 0;
    
    while (byte_pos < str.size())
    {
        size_t char_start = byte_pos;
        uint32_t c = decode_utf8_char(str, byte_pos);
        int char_width = char_display_width(c);
        
        // If adding this character would exceed limit, stop
        if (current_width + char_width > max_width)
        {
            // Return substring up to (but not including) this character
            return str.substr(0, char_start);
        }
        
        current_width += char_width;
    }
    
    // Entire string fits
    return str;
}

// Truncate with ellipsis if needed
std::string truncate_with_ellipsis(const std::string& str, int max_width)
{
    int total_width = utf8_display_width(str);
    
    // If it fits, return as-is
    if (total_width <= max_width)
    {
        return str;
    }
    
    // Otherwise, truncate to (max_width - 1) and add dot
    std::string truncated = truncate_to_width(str, max_width - 1);
    return truncated + ".";
}

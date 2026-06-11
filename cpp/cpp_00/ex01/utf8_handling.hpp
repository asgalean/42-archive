#ifndef UTF8_HANDLING_HPP
#define UTF8_HANDLING_HPP

#include <string>
#include <iostream>
#include <stdint.h>
#include <cstdlib>


uint32_t decode_utf8_char(const std::string& str, size_t& pos);
bool is_wide_character(uint32_t c);
int char_display_width(uint32_t c);
int utf8_display_width(const std::string& str);
std::string truncate_to_width(const std::string& str, int max_width);
std::string truncate_with_ellipsis(const std::string& str, int max_width);

#endif

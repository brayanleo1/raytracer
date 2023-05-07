#ifndef COMMONS_H
#define COMMONS_H

#include <cstdint>

struct RGBColor
{
	std::uint8_t r;
	std::uint8_t g;
	std::uint8_t b;
};

constexpr RGBColor red{255,0,0};
constexpr RGBColor green{0,255,0};
constexpr RGBColor blue{0,0,255};
constexpr RGBColor yeallow{255,255,0};
constexpr RGBColor white{255,255,255};
constexpr RGBColor black{0,0,0};

#endif
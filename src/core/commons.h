#ifndef COMMONS_H
#define COMMONS_H

#include <cstdint>

struct RGBAColor
{
	std::uint32_t r;
	std::uint32_t g;
	std::uint32_t b;
	std::uint32_t a;
};

constexpr RGBAColor red{255,0,0,255};
constexpr RGBAColor green{0,255,0,255};
constexpr RGBAColor blue{0,0,255,255};
constexpr RGBAColor yeallow{255,255,0,255};
constexpr RGBAColor white{255,255,255,255};
constexpr RGBAColor black{0,0,0,255};

#endif
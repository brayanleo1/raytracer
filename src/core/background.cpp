#include "background.h"
#include <vector>

namespace rt3 {
/*!
 * Samples a color base on spherical interpolation of an image ou colored
 * background.
 *
 * @param pixel_ndc Pixel position in NDC space,  in \f$[0:1]\f$.
 * \return The interpolated color.
 */
Spectrum Background::sampleXYZ(const Point2f &pixel_ndc) const {
  // TODO
  return Spectrum{0, 0, 0};
}

BackgroundColor *create_color_background(const ParamSet &ps) {
  /*clog << "\tAdded attribute (" << att_key << ": \"";
  for (const auto &e : comp) {
    clog << e << " ";
  }
  clog << "\")\n";*/
  /*std::vector<std::string> colors;
  BackgroundColor b;
  if(ps.count("bl")) {
    colors.push_back(ps.find("bl")->second);
  } else {

  }
  //RGBColor colors[];
  //for(const)*/
  
  return /*&b*/new BackgroundColor();
}

RGBColor BackgroundColor::sample(const RGBColor &A, const RGBColor &B, float t) const
{
  RGBColor R;
  R.r = rt3::Lerp(t, A.r, B.r);
  R.g = rt3::Lerp(t, A.g, B.g);
	R.b = rt3::Lerp(t, A.b, B.b);
	return R;
}

RGBColor BackgroundColor::sample(const float &A, const float &B) const
{
  auto iL = sample(corners[tl], corners[bl], B);
  auto iR = sample(corners[tr], corners[br], B);
  RGBColor R = sample(iL, iR, A);
	return R;
}

BackgroundColor::BackgroundColor(const std::vector<RGBColor> &colors)
{
  corners[bl] = colors[bl];
  if(colors.size() > 1) {
    corners[tl] = colors[tl];
    corners[tr] = colors[tr];
    corners[br] = colors[br];
  } else {
    corners[tl] = colors[0];
    corners[tr] = colors[0];
    corners[br] = colors[0];
  }
}
} // namespace rt3

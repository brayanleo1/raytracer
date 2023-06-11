#include "sphere.h"

namespace rt3 {

Sphere *create_primitive(const ParamSet &ps, const std::shared_ptr<Material>& mtr) {
  Point3f center = retrieve(ps, "center", Point3f(0,0,0));
  float radius = retrieve(ps, "radius", float(0.0));
  
  return new Sphere(center, radius, mtr);
}

}
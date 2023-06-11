#ifndef SPHERE_H
#define SPHERE_H

#include "primitive.h"

namespace rt3
{
class Sphere : public Primitive {
    public: 
        Sphere(const Point3f& center, float radius, const std::shared_ptr<Material>& material)
            : center(center), radius(radius), material(material) {}
        
        /*
         * Implementation of the intersection between the ray and sphere
         * Calculate the intersection point, surface normal, and other required information
         * Assign the values to the Surfel object (sf)
         * Return true if intersection found, false otherwise
        */
        bool intersect(const Ray& r, Surfel* sf) const override {}

        /*
         * Implementation of the simplified intersection check between the ray and sphere
         * Return true if intersection found, false otherwise
        */
        bool intersect_p(const Ray& r) const override {}

        Sphere *create_primitive(const ParamSet &ps, const std::shared_ptr<Material>& mtr) const override;


    private:
        Point3f center;
        float radius;
        std::shared_ptr<Material> material;
};
//Sphere *create_primitive(const ParamSet &ps, const std::shared_ptr<Material>& mtr);

}
#endif  // SPHERE_H
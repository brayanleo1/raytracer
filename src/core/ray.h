#ifndef RAY_H
#define RAY_H

#include "rt3.h"
#include "commons.h"

namespace rt3
{
class Ray {
    public:
        Ray (const Point3i& o, const Vector3i& d,
            real_type start=0, real_type end=INFINITY) : o{o}, d{d}, 
            t_min{0.f}, t_max{INFINITY} {/*empty*/}
        Ray() : t_min{0.f}, t_max{INFINITY}{/*empty*/}
    private:
        Point3i o; //!< origin
        Vector3i d; //!< direction
        mutable real_type t_min, t_max; //!< parameters
        // ... the methods goes here
        Point3i operator()(real_type t) const { return o + d * t; }
};
//Point3i pp{0, 0, 0};
//Vector3i v{3, 2, -4};
//Ray r(const Point3i pp,const Vector3i v); // creating an infinity ray.
//float t{2.3};                            // a parameter for the ray.
//Point3i p = r( t );                       // overloading operator()(), so that it returns o + t*d.
}

#endif  // RAY_H
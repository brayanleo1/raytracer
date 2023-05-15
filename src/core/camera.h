#ifndef CAMERA_H
#define CAMERA_H

#include "rt3.h"
#include "commons.h"
#include "ray.h"
#include "film.h"

namespace rt3
{
class Camera{
    public:
    Ray generate_ray(int x, int y);
    void add_film(const Film &f);
    Point3f look_at;
    Point3f look_from;
    Point3f vup;
    int fovy;
    Film film;
    
};
class PerspectiveCamera : public Camera {
    public:
    Ray generate_ray(int x, int y);
	// ...
};
class OrthographicCamera : public Camera {
    public:
    Ray generate_ray(int x, int y);
	// ...
};
}

#endif  // CAMERA_H
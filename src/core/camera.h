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
    Camera::Camera(Point3f lk_at, Point3f lk_fr, Point3f up, int fov) : look_at{lk_at}, look_from{lk_fr}, vup{up}, fovy{fov} {/*empty*/}
    
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
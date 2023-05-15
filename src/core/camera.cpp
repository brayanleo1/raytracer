#include "camera.h"

namespace rt3 {
    /*Camera(Film f) {
        film = f;
    }*/
    /*Camera::Camera(const Film &f) {
        film = f;
    }*/

    /*void Camera::add_film(Film f) {
        film = f;
    }*/

    void Camera::add_film(const Film& f) {
    film = f;
    }


    Ray PerspectiveCamera::generate_ray(int x, int y) {
        /*
        *Vector3f gaze = look_at - look_from; Vector3 w = normalize(gaze); // left-hand orientation
        *Vector3f u = normalize( cross( vup, w ) ); // The order inside cross matters. Can you guess why?
        *Vector3f v = normalize( cross ( w, u ) );
        *Point3f e = look_from;
        */

       //Cada ^ indica que é um vetor
       /*u = l+(r−l)(i+0.5)/(n_x)
       **v​ = b+(t−b)(j+0.5)/(n_y) */
       /*
       *ray.direction ← (fd)w^+uu^+vv^
        *ray.origin ←e
       */
    }

    Ray OrthographicCamera::generate_ray(int x, int y) {
        /*
        *Vector3f gaze = look_at - look_from; Vector3 w = normalize(gaze); // left-hand orientation
        *Vector3f u = normalize( cross( vup, w ) ); // The order inside cross matters. Can you guess why?
        *Vector3f v = normalize( cross ( w, u ) );
        *Point3f e = look_from;
        */

       //Cada ^ indica que é um vetor
       /*u = l+(r−l)(i+0.5)/(n_x)
       **v​ = b+(t−b)(j+0.5)/(n_y) */
       /*
       *ray.direction ← w^
        *ray.origin ←e +uu^+vv^
       */
    }

}
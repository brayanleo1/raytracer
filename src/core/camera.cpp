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

    /*Camera::Camera(Point3f lk_at, Point3f lk_fr, Point3f up, int fov) : look_at{lk_at}, look_from{lk_fr}, vup{up}, fovy{fov}
    {
        //Empty
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
       Vector3f gaze = look_at - look_from;
       Vector3f w = gaze; w.make_unit_vector(); // left-hand orientation
       Vector3f u = cross( vup, w ); u.make_unit_vector(); // The order inside cross matters. Can you guess why?
       Vector3f v = cross( w, u ); v.make_unit_vector();
       Point3f e = look_from;
       //l, r, b, t are dimensions, like from 200 x 100: l = 0; r = 199, t = 0; b = 99 ?
       //i,j are x,y
       //fd = 1,(focal distance)
       auto a = film.get_resolution()[0]/film.get_resolution()[1];
       auto h = fovy/2;
       auto t = h;
       auto b = -h;
       auto l = -a * h;
       auto r = a * h;

       auto un = l+(r-l)*(x+0.5)/film.get_resolution()[0] /*column*/;
       auto vn = b+(t-b)*(y+0.5)/film.get_resolution()[1] /*row*/;


       //Cada ^ indica que é um vetor
       /*u = l+(r−l)(i+0.5)/(n_x)
       **v​ = b+(t−b)(j+0.5)/(n_y) */
       /*
       *ray.direction ← (fd)w^+uu^+vv^
        *ray.origin ←e
       */
       return Ray(e, w+un*u+vn*v);
    }

    Ray OrthographicCamera::generate_ray(int x, int y) {
       Vector3f gaze = look_at - look_from;
       Vector3f w = gaze; w.make_unit_vector(); // left-hand orientation
       Vector3f u = cross( vup, w ); u.make_unit_vector(); // The order inside cross matters. Can you guess why?
       Vector3f v = cross( w, u ); v.make_unit_vector();
       Point3f e = look_from;
       
       auto a = film.get_resolution()[0]/film.get_resolution()[1];
       auto h = fovy/2;
       auto t = h;
       auto b = -h;
       auto l = -a * h;
       auto r = a * h;

       auto un = l+(r-l)*(x+0.5)/film.get_resolution()[0] /*column*/;
       auto vn = b+(t-b)*(y+0.5)/film.get_resolution()[1] /*row*/;

       /*
       *ray.direction ← w^
        *ray.origin ←e +uu^+vv^
       */
       return Ray(w, e+un*u+vn*v);
    }

    Camera *create_camera(const ParamSet &ps){
        std::cout << ">>> Inside create_camera()\n";
        Point3f lk_at = retrieve(ps, "look_at", Point3f(0, 0, 0));
        Point3f lk_fr = retrieve(ps, "look_from", Point3f(0, 0, 0));
        Point3f up = retrieve(ps, "look_up", Point3f(0, 0, 0));
        int fov = retrieve(ps, "fovy", int(0));

        return new Camera(lk_at, lk_fr, up, fov);
        /*
        std::cout << ">>> Inside create_film()\n";
        std::string filename;
        // Let us check whether user has provided an output file name via
        // command line arguments in main().
        if (API::curr_run_opt.outfile != "")
        {
        // Retrieve filename defined via CLI.
        filename = API::curr_run_opt.outfile;
        // Retrieve another filename, now from the ParamSet object.
        std::string filename_from_file = retrieve(ps, "filename", std::string{""});
        if (filename_from_file != "") // We also get a filename from scene file...
            RT3_WARNING(string{"Output filename supplied on command line, \""} + API::curr_run_opt.outfile + string{"\" is overriding filename provided in scene "
                                                                                                                    "description file, \""} +
                        filename_from_file);
        }
        else
        {
        // Try yo retrieve filename from scene file.
        filename = retrieve(ps, "filename", std::string{"image.png"});
        }

        // Read resolution.
        // Aux function that retrieves info from the ParamSet.
        int xres = retrieve(ps, "x_res", int(1280));
        // Aux function that retrieves info from the ParamSet.
        int yres = retrieve(ps, "y_res", int(720));
        // Quick render?
        if (API::curr_run_opt.quick_render == true)
        {
        // decrease resolution.
        xres = std::max(1, xres / 4);
        yres = std::max(1, yres / 4);
        }

        // Read crop window information.
        std::vector<real_type> cw = retrieve(ps, "crop_window", std::vector<real_type>{0, 1, 0, 1});
        std::cout << "Crop window ";
        for (const auto &e : cw)
        std::cout << e << " ";
        std::cout << '\n';

        std::vector<RGBAColor> data;

        for (int i = 0; i < xres; i++)
        {
        for (int j = 0; j < yres; j++)
        {
            data.push_back({0, 0, 0, 255});
        }
        }

        // Note that the image type is fixed here. Must be read from ParamSet, though.
        return new Film(Point2i{float(xres), float(yres)}, filename, Film::image_type_e::PPM3, data);
        */
    }

}
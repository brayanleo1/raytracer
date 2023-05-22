#include "film.h"
#include <cmath>

#include <fstream>
#include <string>
#include <iostream>

#include "api.h"
#include "image_io.h"
#include "paramset.h"
#include "commons.h"

namespace rt3
{

  //=== Film Method Definitions
  Film::Film(const Point2i &resolution, const std::string &filename, image_type_e imgt, std::vector<RGBAColor> &imgdt)
      : m_full_resolution{resolution}, m_filename{filename}, m_image_type{imgt}, m_image_data{imgdt}
  {
    // TODO
  }

  Film::~Film()
  {
  }

  /// Add the color to image.
  void Film::add_sample(const Point2i &pixel_coord, const RGBAColor &pixel_color)
  {

    m_image_data[(pixel_coord[1] * m_full_resolution[0]) + pixel_coord[0]] = pixel_color;
    // m_image_data[(m_image_data.size()-1)].append(" "+std::to_string(pixel_color.r)+' '+std::to_string(pixel_color.g)+' '+std::to_string(pixel_color.b)+"\n");
  }

  /// Convert image to RGB, compute final pixel values, write image.
  void Film::write_image(void) const
  {
    // TODO: call the proper writing function, either PPM or PNG.
    if (m_image_type == image_type_e::PNG)
    {
      // Image_data gets a fourth 255 at each for opacity
      /*std::string data;
      std::vector<unsigned char> img;
      for(auto l : m_image_data) {
        data.append(std::to_string(l.r)+" "+std::to_string(l.g)+" "+std::to_string(l.b)+" 255\n");
      }
      strcpy( (char*) img, data );*/
      // Aqui embaixo está o começo do encode
      // lodepng::encode(m_filename, m_image_data, m_full_resolution[0], m_full_resolution[1]);
      // lodepng::encode(img,img/*in*/,m_full_resolution[0],m_full_resolution[1]);
    }
    else if (m_image_type == image_type_e::PPM3)
    {
      std::ofstream out(m_filename + ".ppm");
      out << "P3\n";
      std::string t = std::to_string(int(m_full_resolution[0])) + ' ' + std::to_string(int(m_full_resolution[1])) + "\n";
      out << t;
      out << "255\n";
      for (auto l : m_image_data)
      {
        out << std::to_string(l.r) << " " << std::to_string(l.g) << " " << std::to_string(l.b) << "\n";
      }
      out.close();
    }
  }

  // Factory function pattern.
  // This is the function that retrieves from the ParamSet object
  // all the information we need to create a Film object.
  Film *create_film(const ParamSet &ps)
  {
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

    // TODO
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
    return new Film(Point2i{xres, yres}, filename, Film::image_type_e::PPM3, data);
  }
} // namespace rt3

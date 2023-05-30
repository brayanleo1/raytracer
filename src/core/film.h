#ifndef FILM_H
#define FILM_H

#include "error.h"
#include "paramset.h"
#include "rt3.h"
#include "commons.h"

namespace rt3 {

/// Represents an image generated by the ray tracer.
class Film {
 public:
  /// List of support image file formats.
  enum class image_type_e : int { PNG = 0, PPM3, PPM6 };

  //=== Film Public Methods
  Film(const Point2i &resolution, const std::string &filename, image_type_e imgt, std::vector<unsigned char> &imgdt);
  virtual ~Film();

  /// Retrieve original Film resolution.
  Point2i get_resolution() const
  {
    return m_full_resolution;
  };
  /// Takes a sample `p` and its radiance `L` and updates the image.
  void add_sample(const Point2i &, const RGBAColor &);
  void write_image() const;

  //=== Film Public Data
  const Point2i m_full_resolution;  //!< The image's full resolution values.
  std::string m_filename;           //!< Full path file name + extension.
  image_type_e m_image_type;        //!< Image type, PNG, PPM3, PPM6.
  // TODO: Create the matrix (or vector) that will hold the image data.
  std::vector<unsigned char> m_image_data;
  // std::unique_ptr< ColorBuffer > m_color_buffer_ptr; //!< Reference to the
  // color buffer (image) object.
};

// Factory pattern. It's not part of this class.
Film *create_film(const ParamSet &ps);
}  // namespace rt3

#endif  // FILM_H

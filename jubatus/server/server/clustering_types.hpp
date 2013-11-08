// This file is auto-generated from clustering.idl(0.4.5-347-gbd3e713) with jenerator version 0.4.5-267-g5536bc5/feature/coreset
// *** DO NOT EDIT ***

#ifndef JUBATUS_SERVER_SERVER_CLUSTERING_TYPES_HPP_
#define JUBATUS_SERVER_SERVER_CLUSTERING_TYPES_HPP_

#include <stdint.h>

#include <map>
#include <string>
#include <vector>
#include <utility>

#include "jubatus/core/fv_converter/datum.hpp"
#include <msgpack.hpp>

namespace jubatus {

struct cluster_datum {
 public:
  MSGPACK_DEFINE(weight, data);
  double weight;
  jubatus::core::fv_converter::datum data;
  cluster_datum() {
  }
  cluster_datum(double weight, const jubatus::core::fv_converter::datum& data)
    : weight(weight), data(data) {
  }
};

}  // namespace jubatus

#endif  // JUBATUS_SERVER_SERVER_CLUSTERING_TYPES_HPP_

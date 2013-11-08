// This file is auto-generated from clustering.idl(0.4.5-347-gbd3e713) with jenerator version 0.4.5-267-g5536bc5/feature/coreset
// *** DO NOT EDIT ***

#ifndef JUBATUS_CLIENT_CLUSTERING_TYPES_HPP_
#define JUBATUS_CLIENT_CLUSTERING_TYPES_HPP_

#include <stdint.h>

#include <map>
#include <string>
#include <vector>
#include <utility>

#include <jubatus/client/common/datum.hpp>
#include <msgpack.hpp>

namespace jubatus {
namespace clustering {

struct cluster_datum {
 public:
  MSGPACK_DEFINE(weight, data);
  double weight;
  jubatus::client::common::datum data;
  cluster_datum() {
  }
  cluster_datum(double weight, const jubatus::client::common::datum& data)
    : weight(weight), data(data) {
  }
};

}  // namespace clustering
}  // namespace jubatus

#endif  // JUBATUS_CLIENT_CLUSTERING_TYPES_HPP_

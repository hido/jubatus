// This file is auto-generated from clustering.idl(0.4.5-349-g996d101) with jenerator version 0.4.5-349-g996d101/develop_temp_coreset_merged
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

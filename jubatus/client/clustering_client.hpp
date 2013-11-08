// This file is auto-generated from clustering.idl(0.4.5-347-gbd3e713) with jenerator version 0.4.5-267-g5536bc5/feature/coreset
// *** DO NOT EDIT ***

#ifndef JUBATUS_CLIENT_CLUSTERING_CLIENT_HPP_
#define JUBATUS_CLIENT_CLUSTERING_CLIENT_HPP_

#include <map>
#include <string>
#include <vector>
#include <jubatus/client/common/client.hpp>
#include <jubatus/client/common/datum.hpp>
#include "clustering_types.hpp"

namespace jubatus {
namespace clustering {
namespace client {

class clustering : public jubatus::client::common::client {
 public:
  clustering(const std::string& host, uint64_t port, const std::string& name,
      unsigned int timeout_sec)
      : client(host, port, name, timeout_sec) {
  }

  std::string get_config(const std::string& name) {
    msgpack::rpc::future f = c_.call("get_config", name_, name);
    return f.get<std::string>();
  }

  bool push(const std::string& name,
      const std::vector<jubatus::client::common::datum>& points) {
    msgpack::rpc::future f = c_.call("push", name_, name, points);
    return f.get<bool>();
  }

  uint32_t get_revision(const std::string& name) {
    msgpack::rpc::future f = c_.call("get_revision", name_, name);
    return f.get<uint32_t>();
  }

  std::vector<std::vector<cluster_datum> > get_core_members(
      const std::string& name) {
    msgpack::rpc::future f = c_.call("get_core_members", name_, name);
    return f.get<std::vector<std::vector<cluster_datum> > >();
  }

  std::vector<jubatus::client::common::datum> get_k_center(
      const std::string& name) {
    msgpack::rpc::future f = c_.call("get_k_center", name_, name);
    return f.get<std::vector<jubatus::client::common::datum> >();
  }

  jubatus::client::common::datum get_nearest_center(const std::string& name,
      const jubatus::client::common::datum& point) {
    msgpack::rpc::future f = c_.call("get_nearest_center", name_, name, point);
    return f.get<jubatus::client::common::datum>();
  }

  std::vector<cluster_datum> get_nearest_members(const std::string& name,
      const jubatus::client::common::datum& point) {
    msgpack::rpc::future f = c_.call("get_nearest_members", name_, name, point);
    return f.get<std::vector<cluster_datum> >();
  }

  bool save(const std::string& name, const std::string& id) {
    msgpack::rpc::future f = c_.call("save", name_, name, id);
    return f.get<bool>();
  }

  bool load(const std::string& name, const std::string& id) {
    msgpack::rpc::future f = c_.call("load", name_, name, id);
    return f.get<bool>();
  }

  std::map<std::string, std::map<std::string, std::string> > get_status(
      const std::string& name) {
    msgpack::rpc::future f = c_.call("get_status", name_, name);
    return f.get<std::map<std::string, std::map<std::string, std::string> > >();
  }
};

}  // namespace client
}  // namespace clustering
}  // namespace jubatus

#endif  // JUBATUS_CLIENT_CLUSTERING_CLIENT_HPP_

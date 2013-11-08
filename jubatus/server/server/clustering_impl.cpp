// This file is auto-generated from clustering.idl(0.4.5-347-gbd3e713) with jenerator version 0.4.5-267-g5536bc5/feature/coreset
// *** DO NOT EDIT ***

#include <map>
#include <string>
#include <vector>
#include <utility>
#include <pficommon/lang/shared_ptr.h>

#include "../../server/framework.hpp"
#include "clustering_serv.hpp"

namespace jubatus {
namespace server {

class clustering_impl : public jubatus::server::common::mprpc::rpc_server {
 public:
  explicit clustering_impl(const jubatus::server::framework::server_argv& a):
    rpc_server(a.timeout),
    p_(new jubatus::server::framework::server_helper<clustering_serv>(a,
        false)) {

    rpc_server::add<std::string(std::string, std::string)>("get_config",
        pfi::lang::bind(&clustering_impl::get_config, this, pfi::lang::_2));
    rpc_server::add<bool(std::string, std::string,
        std::vector<jubatus::core::fv_converter::datum>)>("push",
        pfi::lang::bind(&clustering_impl::push, this, pfi::lang::_2,
        pfi::lang::_3));
    rpc_server::add<uint32_t(std::string, std::string)>("get_revision",
        pfi::lang::bind(&clustering_impl::get_revision, this, pfi::lang::_2));
    rpc_server::add<std::vector<std::vector<cluster_datum> >(std::string,
        std::string)>("get_core_members", pfi::lang::bind(
        &clustering_impl::get_core_members, this, pfi::lang::_2));
    rpc_server::add<std::vector<jubatus::core::fv_converter::datum>(std::string,
        std::string)>("get_k_center", pfi::lang::bind(
        &clustering_impl::get_k_center, this, pfi::lang::_2));
    rpc_server::add<jubatus::core::fv_converter::datum(std::string, std::string,
        jubatus::core::fv_converter::datum)>("get_nearest_center",
        pfi::lang::bind(&clustering_impl::get_nearest_center, this,
        pfi::lang::_2, pfi::lang::_3));
    rpc_server::add<std::vector<cluster_datum>(std::string, std::string,
        jubatus::core::fv_converter::datum)>("get_nearest_members",
        pfi::lang::bind(&clustering_impl::get_nearest_members, this,
        pfi::lang::_2, pfi::lang::_3));
    rpc_server::add<bool(std::string, std::string, std::string)>("save",
        pfi::lang::bind(&clustering_impl::save, this, pfi::lang::_2,
        pfi::lang::_3));
    rpc_server::add<bool(std::string, std::string, std::string)>("load",
        pfi::lang::bind(&clustering_impl::load, this, pfi::lang::_2,
        pfi::lang::_3));
    rpc_server::add<std::map<std::string, std::map<std::string, std::string> >(
        std::string, std::string)>("get_status", pfi::lang::bind(
        &clustering_impl::get_status, this, pfi::lang::_2));

    rpc_server::add<std::string(std::string)>("get_config", pfi::lang::bind(
        &clustering_impl::get_config, this));
    rpc_server::add<bool(std::string, std::string)>("save", pfi::lang::bind(
        &clustering_impl::save, this, pfi::lang::_2));
    rpc_server::add<bool(std::string, std::string)>("load", pfi::lang::bind(
        &clustering_impl::load, this, pfi::lang::_2));
    rpc_server::add<std::map<std::string, std::map<std::string, std::string> >(
        std::string)>("get_status", pfi::lang::bind(
        &clustering_impl::get_status, this));
  }

  std::string get_config(const std::string& name) {
    JRLOCK_(p_);
    return get_p()->get_config(name);
  }

  bool push(const std::string& name,
      const std::vector<jubatus::core::fv_converter::datum>& points) {
    JWLOCK_(p_);
    return get_p()->push(name, points);
  }

  uint32_t get_revision(const std::string& name) {
    JRLOCK_(p_);
    return get_p()->get_revision(name);
  }

  std::vector<std::vector<cluster_datum> > get_core_members(
      const std::string& name) {
    JRLOCK_(p_);
    return get_p()->get_core_members(name);
  }

  std::vector<jubatus::core::fv_converter::datum> get_k_center(
      const std::string& name) {
    JRLOCK_(p_);
    return get_p()->get_k_center(name);
  }

  jubatus::core::fv_converter::datum get_nearest_center(const std::string& name,
      const jubatus::core::fv_converter::datum& point) {
    JRLOCK_(p_);
    return get_p()->get_nearest_center(name, point);
  }

  std::vector<cluster_datum> get_nearest_members(const std::string& name,
      const jubatus::core::fv_converter::datum& point) {
    JRLOCK_(p_);
    return get_p()->get_nearest_members(name, point);
  }

  bool save(const std::string& name, const std::string& id) {
    JWLOCK_(p_);
    return get_p()->save(name, id);
  }

  bool load(const std::string& name, const std::string& id) {
    JWLOCK_(p_);
    return get_p()->load(name, id);
  }

  std::map<std::string, std::map<std::string, std::string> > get_status(
      const std::string& name) {
    JRLOCK_(p_);
    return get_p()->get_status(name);
  }

  std::string get_config() {
    JRLOCK_(p_);
    return get_p()->get_config();
  }

  bool save(const std::string& id) {
    JWLOCK_(p_);
    return get_p()->save(id);
  }

  bool load(const std::string& id) {
    JWLOCK_(p_);
    return get_p()->load(id);
  }

  std::map<std::string, std::map<std::string, std::string> > get_status() {
    JRLOCK_(p_);
    return p_->get_status();
  }

  int run() { return p_->start(*this); }
  pfi::lang::shared_ptr<clustering_serv> get_p() { return p_->server(); }

 private:
  pfi::lang::shared_ptr<jubatus::server::framework::server_helper<clustering_serv> > p_;
};

}  // namespace server
}  // namespace jubatus

int main(int argc, char* argv[]) {
  return
    jubatus::server::framework::run_server<jubatus::server::clustering_impl>
      (argc, argv, "clustering");
}

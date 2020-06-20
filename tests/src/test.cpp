#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pqrs/osx/iokit_hid_element.hpp>

TEST_CASE("iokit_hid_element nullptr") {
  pqrs::osx::iokit_hid_element e(nullptr);

  REQUIRE(e.get_cf_ptr() == false);
  REQUIRE(e.get_raw_ptr() == nullptr);
  REQUIRE(e.get_logical_max() == std::nullopt);
  REQUIRE(e.get_logical_min() == std::nullopt);
  REQUIRE(e.get_name() == std::nullopt);
  REQUIRE(e.get_physical_max() == std::nullopt);
  REQUIRE(e.get_physical_min() == std::nullopt);
  REQUIRE(e.get_report_count() == std::nullopt);
  REQUIRE(e.get_report_id() == std::nullopt);
  REQUIRE(e.get_report_size() == std::nullopt);
  REQUIRE(e.get_type() == std::nullopt);
  REQUIRE(e.get_unit() == std::nullopt);
  REQUIRE(e.get_unit_exponent() == std::nullopt);
  REQUIRE(e.get_usage_page() == std::nullopt);
  REQUIRE(e.get_usage() == std::nullopt);
  REQUIRE(e.has_null_state() == std::nullopt);
  REQUIRE(e.has_preferred_state() == std::nullopt);
  REQUIRE(e.is_array() == std::nullopt);
  REQUIRE(e.is_non_linear() == std::nullopt);
  REQUIRE(e.is_relative() == std::nullopt);
  REQUIRE(e.is_virtual() == std::nullopt);
  REQUIRE(e.is_wrapping() == std::nullopt);
  REQUIRE(e == false);
}

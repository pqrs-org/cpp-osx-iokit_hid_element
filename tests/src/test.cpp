#include <boost/ut.hpp>
#include <pqrs/osx/iokit_hid_element.hpp>

int main(void) {
  using namespace boost::ut;
  using namespace boost::ut::literals;

  "iokit_hid_element nullptr"_test = [] {
    pqrs::osx::iokit_hid_element e;

    expect(e.get_cf_ptr() == false);
    expect(e.get_raw_ptr() == nullptr);
    expect(e.get_logical_max() == std::nullopt);
    expect(e.get_logical_min() == std::nullopt);
    expect(e.get_name() == std::nullopt);
    expect(e.get_physical_max() == std::nullopt);
    expect(e.get_physical_min() == std::nullopt);
    expect(e.get_report_count() == std::nullopt);
    expect(e.get_report_id() == std::nullopt);
    expect(e.get_report_size() == std::nullopt);
    expect(e.get_type() == std::nullopt);
    expect(e.get_unit() == std::nullopt);
    expect(e.get_unit_exponent() == std::nullopt);
    expect(e.get_usage_page() == std::nullopt);
    expect(e.get_usage() == std::nullopt);
    expect(e.has_null_state() == std::nullopt);
    expect(e.has_preferred_state() == std::nullopt);
    expect(e.is_array() == std::nullopt);
    expect(e.is_non_linear() == std::nullopt);
    expect(e.is_relative() == std::nullopt);
    expect(e.is_virtual() == std::nullopt);
    expect(e.is_wrapping() == std::nullopt);
    expect(e == false);
  };

  "get_iokit_hid_element_type_name"_test = [] {
    expect(pqrs::osx::get_iokit_hid_element_type_name(pqrs::osx::iokit_hid_element_type::input_misc) == std::string("input_misc"));
  };

  return 0;
}

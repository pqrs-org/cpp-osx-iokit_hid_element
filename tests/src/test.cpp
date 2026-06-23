#include <boost/ut.hpp>
#include <pqrs/osx/iokit_hid_element.hpp>
#include <string>

int main() {
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

  "iokit_hid_element cf_ptr"_test = [] {
    pqrs::cf::cf_ptr<IOHIDElementRef> ptr;
    pqrs::osx::iokit_hid_element e(ptr);

    expect(e.get_cf_ptr() == false);
    expect(e.get_raw_ptr() == nullptr);
    expect(e == false);
  };

  "get_iokit_hid_element_type_name"_test = [] {
    expect(pqrs::osx::get_iokit_hid_element_type_name(pqrs::osx::iokit_hid_element_type::input_misc) == std::string("input_misc"));
    expect(pqrs::osx::get_iokit_hid_element_type_name(pqrs::osx::iokit_hid_element_type::input_button) == std::string("input_button"));
    expect(pqrs::osx::get_iokit_hid_element_type_name(pqrs::osx::iokit_hid_element_type::input_axis) == std::string("input_axis"));
    expect(pqrs::osx::get_iokit_hid_element_type_name(pqrs::osx::iokit_hid_element_type::input_scancodes) == std::string("input_scancodes"));
    expect(pqrs::osx::get_iokit_hid_element_type_name(pqrs::osx::iokit_hid_element_type::input_null) == std::string("input_null"));
    expect(pqrs::osx::get_iokit_hid_element_type_name(pqrs::osx::iokit_hid_element_type::output) == std::string("output"));
    expect(pqrs::osx::get_iokit_hid_element_type_name(pqrs::osx::iokit_hid_element_type::feature) == std::string("feature"));
    expect(pqrs::osx::get_iokit_hid_element_type_name(pqrs::osx::iokit_hid_element_type::collection) == std::string("collection"));
    expect(pqrs::osx::get_iokit_hid_element_type_name(static_cast<pqrs::osx::iokit_hid_element_type>(-1)) == std::string("unknown"));
  };

  return 0;
}

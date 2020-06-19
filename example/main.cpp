#include <pqrs/osx/iokit_hid_device.hpp>
#include <pqrs/osx/iokit_hid_element.hpp>
#include <pqrs/osx/iokit_registry_entry.hpp>

namespace {
void traverse(pqrs::osx::iokit_registry_entry registry_entry) {
  if (registry_entry.get().conforms_to("IOHIDDevice")) {
    if (auto id = registry_entry.find_registry_entry_id()) {
      std::cout << "registry_entry_id: " << *id << std::endl;
    }

    if (auto device = IOHIDDeviceCreate(kCFAllocatorDefault, *(registry_entry.get()))) {
      pqrs::osx::iokit_hid_device d(device);

      for (auto&& element : d.make_elements()) {
        pqrs::osx::iokit_hid_element e(*element);

        if (auto logical_max = e.get_logical_max()) {
          std::cout << "logical_max " << *logical_max << std::endl;
        }

        if (auto logical_min = e.get_logical_min()) {
          std::cout << "logical_min " << *logical_min << std::endl;
        }

        if (auto name = e.get_name()) {
          std::cout << "name " << *name << std::endl;
        }

        if (auto physical_max = e.get_physical_max()) {
          std::cout << "physical_max " << *physical_max << std::endl;
        }

        if (auto physical_min = e.get_physical_min()) {
          std::cout << "physical_min " << *physical_min << std::endl;
        }

        if (auto report_count = e.get_report_count()) {
          std::cout << "report_count " << *report_count << std::endl;
        }

        if (auto report_id = e.get_report_id()) {
          std::cout << "report_id " << *report_id << std::endl;
        }

        if (auto report_size = e.get_report_size()) {
          std::cout << "report_size " << *report_size << std::endl;
        }

        if (auto type = e.get_type()) {
          std::cout << "type " << static_cast<std::underlying_type<pqrs::osx::iokit_hid_element_type>::type>(*type) << std::endl;
        }

        if (auto unit = e.get_unit()) {
          std::cout << "unit " << *unit << std::endl;
        }

        if (auto unit_exponent = e.get_unit_exponent()) {
          std::cout << "unit_exponent " << *unit_exponent << std::endl;
        }

        if (auto usage_page = e.get_usage_page()) {
          std::cout << "usage_page " << *usage_page << std::endl;
        }

        if (auto usage = e.get_usage()) {
          std::cout << "usage " << *usage << std::endl;
        }

        if (auto has_null_state = e.has_null_state()) {
          std::cout << "has_null_state " << *has_null_state << std::endl;
        }

        if (auto has_preferred_state = e.has_preferred_state()) {
          std::cout << "has_preferred_state " << *has_preferred_state << std::endl;
        }

        if (auto is_array = e.is_array()) {
          std::cout << "is_array " << *is_array << std::endl;
        }

        if (auto is_non_linear = e.is_non_linear()) {
          std::cout << "is_non_linear " << *is_non_linear << std::endl;
        }

        if (auto is_relative = e.is_relative()) {
          std::cout << "is_relative " << *is_relative << std::endl;
        }

        if (auto is_virtual = e.is_virtual()) {
          std::cout << "is_virtual " << *is_virtual << std::endl;
        }

        if (auto is_wrapping = e.is_wrapping()) {
          std::cout << "is_wrapping " << *is_wrapping << std::endl;
        }
      }

      CFRelease(device);
    }
  }

  auto child_iterator = registry_entry.get_child_iterator(kIOServicePlane);
  while (true) {
    auto next = child_iterator.next();
    if (!next) {
      break;
    }

    traverse(pqrs::osx::iokit_registry_entry(next));
  }
}
} // namespace

int main(void) {
  traverse(pqrs::osx::iokit_registry_entry::get_root_entry());

  return 0;
}

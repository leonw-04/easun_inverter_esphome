#include "easun_inverter_switch.h"
#include "esphome/core/log.h"
#include "esphome/core/application.h"

namespace esphome {
namespace easun_inverter {

static const char *const TAG = "easun_inverter.switch";

void easun_inverterSwitch::dump_config() { LOG_SWITCH("", "easun_inverter Switch", this); }
void easun_inverterSwitch::write_state(bool state) {
  if (state) {
    if (this->on_command_.length() > 0) {
      this->parent_->switch_command(this->on_command_);
    }
  } else {
    if (this->off_command_.length() > 0) {
      this->parent_->switch_command(this->off_command_);
    }
  }
}

}  // namespace easun_inverter
}  // namespace esphome

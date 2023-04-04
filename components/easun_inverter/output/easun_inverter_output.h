#pragma once

#include "../easun_inverter.h"
#include "esphome/components/output/float_output.h"
#include "esphome/core/component.h"

#include <vector>

namespace esphome {
namespace easun_inverter {

class easun_inverter;

class easun_inverterOutput : public output::FloatOutput {
 public:
  easun_inverterOutput() {}
  void set_parent(easun_inverter *parent) { this->parent_ = parent; }
  void set_set_command(const std::string &command) { this->set_command_ = command; };
  void set_possible_values(std::vector<float> possible_values) { this->possible_values_ = std::move(possible_values); }
  void set_value(float value) { this->write_state(value); };

 protected:
  void write_state(float state) override;
  std::string set_command_;
  easun_inverter *parent_;
  std::vector<float> possible_values_;
};

template<typename... Ts> class SetOutputAction : public Action<Ts...> {
 public:
  SetOutputAction(easun_inverterOutput *output) : output_(output) {}

  TEMPLATABLE_VALUE(float, level)

  void play(Ts... x) override { this->output_->set_value(this->level_.value(x...)); }

 protected:
  easun_inverterOutput *output_;
};

}  // namespace easun_inverter
}  // namespace esphome

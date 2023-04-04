import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID
from esphome.components import uart

DEPENDENCIES = ["uart"]
CODEOWNERS = ["@andreashergert1984"]
AUTO_LOAD = ["binary_sensor", "text_sensor", "sensor", "switch", "output"]
MULTI_CONF = True

CONF_easun_inverter_ID = "easun_inverter_id"

easun_inverter_ns = cg.esphome_ns.namespace("easun_inverter")
easun_inverterComponent = easun_inverter_ns.class_("easun_inverter", cg.Component)

easun_inverter_COMPONENT_SCHEMA = cv.Schema(
    {
        cv.Required(CONF_easun_inverter_ID): cv.use_id(easun_inverterComponent),
    }
)

CONFIG_SCHEMA = cv.All(
    cv.Schema({cv.GenerateID(): cv.declare_id(easun_inverterComponent)})
    .extend(cv.polling_component_schema("1s"))
    .extend(uart.UART_DEVICE_SCHEMA)
)


def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
    yield uart.register_uart_device(var, config)

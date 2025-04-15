# DHT22

Learn how to use sensor API in zephyr with supported sensor (DHT22).

## How to use it

Based on the official documentation (aosong,dht binding):

In the overlay file, you need to specify the node or pin used by the DHT22.

![image](https://github.com/user-attachments/assets/6b083e07-9a47-411f-9d54-32ef8409cfe4)


example in STM32 board

```
&gpiog {
    dht1: dht22 {
        compatible = "aosong,dht";
        dio-gpios = <&gpiog 7 (GPIO_ACTIVE_LOW)>;
        dht22;
        status = "okay";
    };
};
```

this example use gpiog 7

example in ESP32 board

```
/ {
    dht1: dht22 {
        compatible = "aosong,dht";
        dio-gpios = <&gpio0 7 GPIO_ACTIVE_LOW>;
        dht22;
        status = "okay";
    };
};
```

After configuring the device, use the Zephyr Sensor API (fetch and get) to take measurements from the DHT22 sensor:
https://docs.zephyrproject.org/latest/hardware/peripherals/sensor/fetch_and_get.html

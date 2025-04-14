#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

int main(void)
{
    const struct device *dht1 = DEVICE_DT_GET(DT_NODELABEL(dht1));

    if (!device_is_ready(dht1))
    {
        printk("DHT device not ready\n");
        return 0;
    }
    printk("device ready\n");

    k_sleep(K_MSEC(2000));

    int ret;
    while (1)
    {
        ret = sensor_sample_fetch(dht1);
        // Fetch a sample
        if (ret != 0)
        {
            printk("Sensor sample fetch failed with code: %d\n", ret);
            return 0;
        }

        // Get sensor values
        struct sensor_value temp, humidity;

        if (sensor_channel_get(dht1, SENSOR_CHAN_AMBIENT_TEMP, &temp) < 0)
        {
            printk("Cannot get temperature\n");
        }
        else
        {
            printk("Temperature: %d.%06d C\n", temp.val1, temp.val2);
        }

        if (sensor_channel_get(dht1, SENSOR_CHAN_HUMIDITY, &humidity) < 0)
        {
            printk("Cannot get humidity\n");
        }
        else
        {
            printk("Humidity: %d.%06d %%\n", humidity.val1, humidity.val2);
        }

        // Wait before next sample
        k_sleep(K_SECONDS(2));
    }
}